Boost.Asio C++ ������ John Torjo
dummy_work

cpp11 ����boost.asio.example�ǹٷ�����



	���ϣ���ڵ���run()������ʹ���������Ҳ��Ҫrun()�������أ����ʹ��������ʵ��
	boost::asio::executor_work_guard
	asio::io_context io_context;
	asio::executor_work_guard<asio::io_context::executor_type> 
	    work = asio::make_work_guard(io_context);
	......
	work.reset(); // Allow run() to exit. @endcode