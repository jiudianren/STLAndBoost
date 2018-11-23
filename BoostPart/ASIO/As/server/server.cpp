/*
 * server.cpp
 *
 *  Created on: 2018��8��16��
 *      Author: Administrator
 */


#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>
#include <boost/asio/ip/tcp.hpp>

#include <string.h>
#include <iostream>

using namespace std;
using namespace boost::asio;



#define MEM_FN(x)   boost::bind(&self_type::x, shared_from_this())
#define MEM_FN1(x,y) boost::bind(&self_type::x, shared_from_this(),y)
#define MEM_FN2(x,y,z) boost::bind(&self_type::x, shared_from_this(),y,z)

io_service service;

class talk_to_client : public boost::enable_shared_from_this<talk_to_client>, boost::noncopyable {
    typedef talk_to_client self_type;


    talk_to_client() : sock_(service), started_(false) {}
public:
    typedef boost::system::error_code           error_code;
    typedef boost::shared_ptr<talk_to_client>   ptr;

    void start() {
        started_ = true;
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
    void do_read() {
        async_read(sock_, buffer(read_buffer_), MEM_FN2(read_complete,_1,_2), MEM_FN2(on_read,_1,_2));
    }
    void do_write(const std::string & msg) {
        if ( !started() ) return;
        std::copy(msg.begin(), msg.end(), write_buffer_);
        sock_.async_write_some( buffer(write_buffer_, msg.size()), MEM_FN2(on_write,_1,_2));
    }

    void on_read(const error_code & err, size_t bytes) {
        if ( !err) {
            std::string msg(read_buffer_, bytes);
            do_write(msg + "\n");
        }
        stop();
    }
    void on_write(const error_code & err, size_t bytes) {
        do_read();
    }

    size_t read_complete(const boost::system::error_code & err, size_t bytes) {
        // ��TCP�ͻ����е�����
        if ( err) return 0;
        bool found = std::find(read_buffer_, read_buffer_ + bytes, '\n') < read_buffer_ + bytes;
        // ����һ��һ����ȡֱ�������س���������
        return found ? 0 : 1;
    }


    ip::tcp::socket & sock() { return sock_;}
private:
    ip::tcp::socket sock_;
    enum { max_msg = 1024 };
    char read_buffer_[max_msg];
    char write_buffer_[max_msg];
    bool started_;
};


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
