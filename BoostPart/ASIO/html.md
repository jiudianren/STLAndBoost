https://blog.csdn.net/gongluck93/article/details/79364205


如果在某个 boost::asio::io_service 类型的对象之上调用 run() 方法，则相关联的句柄也会在同一个线程内被执行。 通过使用多线程，应用程序可以同时调用多个 run() 方法。 一旦某个异步操作结束，相应的 I/O 服务就将在这些线程中的某一个之中执行句柄。 如果第二个操作在第一个操作之后很快也结束了，则 I/O 服务可以在另一个线程中执行句柄，而无需等待第一个句柄终止。



https://mmoaay.gitbooks.io/boost-asio-cpp-network-programming-chinese/content/



Timer定时器
https://blog.csdn.net/yockie/article/details/40386145

值得提出的是，异步回调函数handler的参数中有一个error，注意这个error很重要，表明这个handler是因为超时被执行还是因为被cancel。

符合2种情况之一，handler被执行：超时或者被cancel（可以通过此error的值进行区分）。
这同时隐含的说明了除非io.stop被调用，否则handler一定会被执行。即便是被cancel。
被cancel有多种方法，直接调用cancel或者调用expires_at，expires_from_now重新设置超时时间。