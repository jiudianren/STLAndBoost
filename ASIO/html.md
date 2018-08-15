https://blog.csdn.net/gongluck93/article/details/79364205


如果在某个 boost::asio::io_service 类型的对象之上调用 run() 方法，则相关联的句柄也会在同一个线程内被执行。 通过使用多线程，应用程序可以同时调用多个 run() 方法。 一旦某个异步操作结束，相应的 I/O 服务就将在这些线程中的某一个之中执行句柄。 如果第二个操作在第一个操作之后很快也结束了，则 I/O 服务可以在另一个线程中执行句柄，而无需等待第一个句柄终止。



https://mmoaay.gitbooks.io/boost-asio-cpp-network-programming-chinese/content/