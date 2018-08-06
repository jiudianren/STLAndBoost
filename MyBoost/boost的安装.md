安装boost
boost有些库需要安装，有些包括响应hpp就可以使用


头文件就是库
使用者最常问的问题就是“我该怎么安装Boost”，这个也是我一开始最关心的问题，Boost这点做的很好，将大部分实现都封装在头文件里，所以对于一些基本的Boost库，其实是不需要安装的，只需要将头文件include到自己的程序里，当然前提是你把Boost的所有用到的头文件都拷贝了一份。
Boost是如何做到这点的?
这是因为Boost的头文件（*.hpp）包含了模板和内联函数，这点随便找一个hpp文件来看你就明白了，所以不需要去静态链接活动态链接二进制lib库了。
不过Boost的某些库还是需要生成二进制的库的，如果你要使用他们，必须编译安装哦，他们是：
Boost.Filesystem
Boost.IOStreams
Boost.ProgramOptions
Boost.Python
Boost.Regex
Boost.Serialization
Boost.Signals
Boost.Thread
Boost.Wave
命名规则
libboost_filesystem-vc80-mt-sgdp-1_42.lib
前缀：统一为lib，但在Windows下只有静态库有lib前缀；
库名称：以"boost一”开头的库名称，在这里是boost_filesystem；
编译器标识：编译该库文件的编译器名称和版本，在这里是-vc80；
多线程标识：支持多线程使用-mt，没有表示不支持多线程；
ABI标识：这个标识比较复杂，标识了Boost库的几个编译链接选项；
s：  静态库标识；
gd：debug版标识；
p：  使用STlport而不是编译器自带STL实现；
版本号：Boost库的版本号，小数点用下画线代替，在这里是1_42；
扩展名：在Windows上是lib，在Linux等类Unix操作系统上是a或者.so。
几个常用宏
#define BOOST_ALL_DYN_LINK
同样，此时boost也会默认帮我们包含对应的lib。如果不想使用boost提供的auto-link机制，或者对它的自动链接不太放心的话（其实大可不必担心），可以预先定义宏：
#define BOOST_ALL_NO_LIB
然后使用以下方法链接：
#pragma comment(lib, "boost_thread-vc100-mt-1_46.lib")或
#pragma comment(lib, "boost_thread-vc100-mt.lib")
这两个lib其实是一样的，实在不明白boost编译时为什么每个库都要复制一份，难道是因为后者在升级boost版本后不用改代码？另外还有一个比较有用的宏：
#define BOOST_LIB_DIAGNOSTIC
它可以让VC在编译时的output窗口中输出程序具体链接了哪些boost库以及链接顺序。