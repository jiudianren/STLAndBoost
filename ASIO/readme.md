Boost.Asio C++ 网络编程 John Torjo
dummy_work

cpp11 来自boost.asio.example是官方样例



	如果希望在调用run()函数后即使做完任务后也不要run()函数返回，则可使用以下类实现
	boost::asio::executor_work_guard
	asio::io_context io_context;
	asio::executor_work_guard<asio::io_context::executor_type> 
	    work = asio::make_work_guard(io_context);
	......
	work.reset(); // Allow run() to exit. @endcode