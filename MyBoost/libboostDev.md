ubuntu 安装  

1 如果是新机器，没在ubunu上装过gearman，那么直接一条命令 执行以下命令：  
sudo apt-get install libboost-all-dev  
头文件一般安装在  
/usr/include  

下面有一个目录boost，里面是头文件。而库文件一般都放在  
/usr/lib/x86_64-linux-gnu   

目录下。比如libboost_system.a文件。  
一 如何查看当前安装的boost版本  

dpkg -S /usr/include/boost/version.hpp 

通过上面的命令，你就可以发现boost的版本了，查看结果可能如下：  
libboost1.54-dev: /usr/include/boost/version.hpp  

二 如何删除当前安装的boost
sudo apt-get autoremove libboost1.54-dev   
那么就可以删除boost了。上面的libboost1.54-dev是在第一步中看到的版本。  
注意的是，如果你使用的是以下命令安装的boost  

sudo apt-get install libboost-dev   
那么很有可能，在目录/usr/lib/x86_64-linux-gnu下并没有libboost_system.a等文件，这个是要注意的。  