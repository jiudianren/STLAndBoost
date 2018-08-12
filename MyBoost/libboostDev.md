#ubuntu 安装  

1 如果是新机器，没在ubunu上装过gearman，那么直接一条命令 执行以下命令：  
sudo apt-get install libboost-all-dev  
头文件一般安装在  
    
    /usr/include  
而库文件一般都放在 
     
     /usr/lib/x86_64-linux-gnu   
目录下。比如libboost_system.a文件。  

如何查看当前安装的boost版本  

    dpkg -S /usr/include/boost/version.hpp 

通过上面的命令，你就可以发现boost的版本了，查看结果可能如下：  
    
    libboost1.54-dev: /usr/include/boost/version.hpp  

二 如何删除当前安装的boost   

sudo apt-get autoremove libboost1.54-dev   
那么就可以删除boost了。上面的libboost1.54-dev是在第一步中看到的版本。  
注意的是，如果你使用的是以下命令安装的boost  

    sudo apt-get install libboost-dev   

那么很有可能，在目录/usr/lib/x86_64-linux-gnu下并没有libboost_system.a等文件，这个是要注意的。



如libboost_filesystem.so 找不到
可以   
 
    apt-get install libboost-filesystem-dev 单独安装
该安装后，会多出

    root@jiudianren:/usr/lib/x86_64-linux-gnu# ls  -l libboo*
    -rw-r--r-- 1 root root 296414 Mar  6 10:21 libboost_filesystem.a
    lrwxrwxrwx 1 root root     29 Mar  6 10:21 libboost_filesystem.so -> libboost_filesystem.so.1.65.1
    -rw-r--r-- 1 root root 105248 Mar  6 10:21 libboost_filesystem.so.1.65.1
    -rw-r--r-- 1 root root  63710 Mar  6 10:21 libboost_system.a
    lrwxrwxrwx 1 root root     25 Mar  6 10:21 libboost_system.so -> libboost_system.so.1.65.1
    -rw-r--r-- 1 root root  18544 Mar  6 10:21 libboost_system.so.1.65.1
如上的链接库



#Boost Docker 

https://hub.docker.com/r/zouzias/boost/
  