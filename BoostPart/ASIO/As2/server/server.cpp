/*
 * server.cpp
 *
 *  Created on: 2018年8月16日
 *      Author: Administrator
 */


#define BOOST_ASIO_ENABLE_HANDLER_TRACKING

#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>
#include <boost/asio/ip/tcp.hpp>

#include <string.h>
#include <iostream>



using namespace std;
using namespace boost::asio;
using namespace boost::posix_time;




#define MEM_FN(x)   boost::bind(&self_type::x, shared_from_this())
#define MEM_FN1(x,y) boost::bind(&self_type::x, shared_from_this(),y)
#define MEM_FN2(x,y,z) boost::bind(&self_type::x, shared_from_this(),y,z)

io_service service;


class talk_to_client;
typedef boost::shared_ptr<talk_to_client>client_ptr;
typedef std::vector<client_ptr> arrayclient;
arrayclient clients;


class talk_to_client : public boost::enable_shared_from_this<talk_to_client>, boost::noncopyable {
    typedef talk_to_client self_type;

public:
    talk_to_client() : sock_(service), started_(false), clients_changed_(false) , timer_(service){}
    typedef boost::system::error_code           error_code;
    typedef boost::shared_ptr<talk_to_client>   ptr;

    void start() {
        started_ = true;
        clients.push_back( shared_from_this());
        last_ping = boost::posix_time::microsec_clock::local_time();
        do_read();
    }
    static ptr new_() {
        ptr new_(new talk_to_client);
        return new_;
    }
    void stop() {
        if ( !started_) return;
        started_ = false;
        sock_.close();
    }

    bool started()
    {
        return  started_;
    }


    void do_ping() {
        do_write("ping\n");
    }
    void do_ask_clients() {
        do_write("ask_clients\n");
    }
    void on_write(const error_code & err, size_t bytes) {

        do_read();

    }
    void do_read() {
        async_read(sock_, buffer(read_buffer_), MEM_FN2(read_complete,_1,_2), MEM_FN2(on_read,_1,_2));
        post_check_ping();
    }
    void do_write(const std::string & msg) {
        if ( !started() ) return;
        std::copy(msg.begin(), msg.end(), write_buffer_);
        sock_.async_write_some( buffer(write_buffer_, msg.size()), MEM_FN2(on_write,_1,_2));
    }

    size_t read_complete(const boost::system::error_code & err, size_t bytes) {
        // 和TCP客户端中的类似
        if ( err) return 0;
        bool found = std::find(read_buffer_, read_buffer_ + bytes, '\n') < read_buffer_ + bytes;
        // 我们一个一个读取直到读到回车，不缓存
        return found ? 0 : 1;
    }


    /*on_read 这里只是一个分解 ，
     * 并不能认为onread 是一个动作，他是多个异步动作的汇合点
     * */

    void on_read(const error_code & err, size_t bytes) {
        if ( err) stop();
        if ( !started() ) return;
        std::string msg(read_buffer_, bytes);
        if ( msg.find("login ") == 0) on_login(msg);
        else if ( msg.find("ping") == 0) on_ping();
        else if ( msg.find("ask_clients") == 0) on_clients();
    }
    void on_login(const std::string & msg) {
        std::istringstream in(msg);
        in >> username_ >> username_;
        do_write("login ok\n");
        update_clients_changed();
    }
    void on_ping() {
        do_write(clients_changed_ ? "ping client_list_changed\n" : "ping ok\n");
        clients_changed_ = false;
    }
    void on_clients() {
        std::string msg;
        for(arrayclient::const_iterator b =clients.begin(),e =clients.end(); b != e; ++b)
            msg += (*b)->username() + " ";
        do_write("clients " + msg + "\n");
    }



    std::string username()
    {
        return username_;
    }
    void update_clients_changed()
    {

    }

    void on_check_ping() {
        ptime now = microsec_clock::local_time();
        if ( (now - last_ping).total_milliseconds() > 5000)
            stop();
        last_ping = boost::posix_time::microsec_clock::local_time();
    }
    void post_check_ping() {
        timer_.expires_from_now(boost::posix_time::millisec(5000));
        timer_.async_wait( MEM_FN(on_check_ping));
    }

    ip::tcp::socket & sock() { return sock_;}
private:
    ip::tcp::socket sock_;
    enum { max_msg = 1024 };
    char read_buffer_[max_msg];
    char write_buffer_[max_msg];
    bool started_;
    std::string username_;
    deadline_timer timer_;
    boost::posix_time::ptime last_ping;
    bool clients_changed_;
};




/*注意本程序为单线程*/

ip::tcp::acceptor acceptor(service, ip::tcp::endpoint(ip::tcp::v4(),8001));
void handle_accept(talk_to_client::ptr client, const error_code     & err)
{
    client->start();
    talk_to_client::ptr new_client = talk_to_client::new_();
    acceptor.async_accept(new_client->sock(), boost::bind(handle_accept,new_client,_1));
}
int main(int argc, char* argv[]) {

    talk_to_client::ptr client = talk_to_client::new_();
    acceptor.async_accept(client->sock(), boost::bind(handle_accept,client,_1));
    service.run();
}





