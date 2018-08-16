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

io_service service;
size_t read_complete(char * buff, const error_code & err, size_t  bytes) {
    if ( err) return 0;
    bool found = std::find(buff, buff + bytes, '\n') < buff + bytes;
    // ����һ��һ����ȡֱ�������س���������
    return found ? 0 : 1;
}
void handle_connections() {
    ip::tcp::acceptor acceptor(service, ip::tcp::endpoint(ip::tcp::v4(),8001));
    char buff[1024];
    while ( true) {
        ip::tcp::socket sock(service);
        acceptor.accept(sock);
        int bytes = read(sock, buffer(buff), boost::bind(read_complete,buff,_1,_2));
        std::string msg(buff, bytes);
        sock.write_some(buffer(msg));
        sock.close();
    }
}
int main(int argc, char* argv[]) {
    handle_connections();
}
