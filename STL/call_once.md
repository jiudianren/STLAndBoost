
//https://blog.csdn.net/xijiacun/article/details/71023777

 某些场景下，我们需要代码只被执行一次，比如单例类的初始化，考虑到多线程安全，需要进行加锁控制。C++11中提供的call_once可以很好的满足这种需求，使用又非常简单。

头文件#include<mutex>

? ? ? ? template <class Fn, class... Args>

? ? ? ? void call_once (once_flag& flag, Fn&& fn, Args&&...args);

? ? ? ? 第一个参数是std::once_flag的对象(once_flag是不允许修改的，其拷贝构造函数和operator=函数都声明为delete)，第二个参数可调用实体，即要求只执行一次的代码，后面可变参数是其参数列表。

? ? ? ? call_once保证函数fn只被执行一次，如果有多个线程同时执行函数fn调用，则只有一个活动线程(active call)会执行函数，其他的线程在这个线程执行返回之前会处于”passive execution”(被动执行状态)——不会直接返回，直到活动线程对fn调用结束才返回。对于所有调用函数fn的并发线程，数据可见性都是同步的(一致的)。

? ? ? ? 如果活动线程在执行fn时抛出异常，则会从处于”passive execution”状态的线程中挑一个线程成为活动线程继续执行fn，依此类推。一旦活动线程返回，所有”passive execution”状态的线程也返回,不会成为活动线程。(实际上once_flag相当于一个锁，使用它的线程都会在上面等待，只有一个线程允许执行。如果该线程抛出异常，那么从等待中的线程中选择一个，重复上面的流程)。

? ? ? ? static std::once_flag oc;? // 用于call_once的局部静态变量

? ? ? ? Singleton* Singleton::m_instance;

? ? ? ? Singleton* Singleton::getInstance() {

? ? ? ? ? ? std::call_once(oc,?[&] () { m_instance = newSingleton(); });

? ? ? ? ? ? return m_instance;

? ? ? ? }

?? ? ? ?还有一个要注意的地方是 once_flag的生命周期，它必须要比使用它的线程的生命周期要长。所以通常定义成全局变量比较好。

