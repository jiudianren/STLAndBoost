Boost.Asio includes classes that implement iostreams on top of sockets. These hide away the complexities associated with endpoint resolution, protocol independence, etc. To create a connection one might simply write:

ip::tcp::iostream stream("www.boost.org", "http");
if (!stream)
{
  // Can't connect.
}
The iostream class can also be used in conjunction with an acceptor to create simple servers. For example:

io_service ios;

ip::tcp::endpoint endpoint(tcp::v4(), 80);
ip::tcp::acceptor acceptor(ios, endpoint);

for (;;)
{
  ip::tcp::iostream stream;
  acceptor.accept(*stream.rdbuf());
  ...
}
Timeouts may be set by calling expires_at() or expires_from_now() to establish a deadline. Any socket operations that occur past the deadline will put the iostream into a "bad" state.

For example, a simple client program like this:

ip::tcp::iostream stream;
stream.expires_from_now(boost::posix_time::seconds(60));
stream.connect("www.boost.org", "http");
stream << "GET /LICENSE_1_0.txt HTTP/1.0\r\n";
stream << "Host: www.boost.org\r\n";
stream << "Accept: */*\r\n";
stream << "Connection: close\r\n\r\n";
stream.flush();
std::cout << stream.rdbuf();
will fail if all the socket operations combined take longer than 60 seconds.

If an error does occur, the iostream's error() member function may be used to retrieve the error code from the most recent system call:

if (!stream)
{
  std::cout << "Error: " << stream.error().message() << "\n";