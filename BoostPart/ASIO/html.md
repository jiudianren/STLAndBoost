https://blog.csdn.net/gongluck93/article/details/79364205


�����ĳ�� boost::asio::io_service ���͵Ķ���֮�ϵ��� run() ��������������ľ��Ҳ����ͬһ���߳��ڱ�ִ�С� ͨ��ʹ�ö��̣߳�Ӧ�ó������ͬʱ���ö�� run() ������ һ��ĳ���첽������������Ӧ�� I/O ����ͽ�����Щ�߳��е�ĳһ��֮��ִ�о���� ����ڶ��������ڵ�һ������֮��ܿ�Ҳ�����ˣ��� I/O �����������һ���߳���ִ�о����������ȴ���һ�������ֹ��



https://mmoaay.gitbooks.io/boost-asio-cpp-network-programming-chinese/content/



Timer��ʱ��
https://blog.csdn.net/yockie/article/details/40386145

ֵ��������ǣ��첽�ص�����handler�Ĳ�������һ��error��ע�����error����Ҫ���������handler����Ϊ��ʱ��ִ�л�����Ϊ��cancel��

����2�����֮һ��handler��ִ�У���ʱ���߱�cancel������ͨ����error��ֵ�������֣���
��ͬʱ������˵���˳���io.stop�����ã�����handlerһ���ᱻִ�С������Ǳ�cancel��
��cancel�ж��ַ�����ֱ�ӵ���cancel���ߵ���expires_at��expires_from_now�������ó�ʱʱ�䡣