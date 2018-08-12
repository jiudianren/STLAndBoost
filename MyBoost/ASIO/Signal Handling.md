Boost.Asio支持使用名为signal_set的类进行信号处理。程序可以向该组添加一个或多个信号，然后执行 操作。当其中一个信号出现时，将调用指定的处理程序。可以向多个signal_set 对象注册相同的信号编号，但信号编号必须仅与Boost.Asio一起使用。 async_wait()

void  handler （
    const  boost :: system :: error_code ＆ error ，
    int  signal_number ）
{ 
  if  （！error ）
  { 
    //发生了一个信号。
  } 
}

...

//构造为进程终止注册的信号集。
boost :: asio :: signal_set  信号（io_service ， SIGINT ， SIGTERM ）;

//开始异步等待其中一个信号发生。
信号。async_wait （handler ）;
信号处理也适用于Windows，因为Microsoft Visual C ++运行时库将控制台事件（如Ctrl + C）映射到等效信号。
