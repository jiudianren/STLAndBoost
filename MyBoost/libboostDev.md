#ubuntu ��װ  

1 ������»�����û��ubunu��װ��gearman����ôֱ��һ������ ִ���������  
sudo apt-get install libboost-all-dev  
ͷ�ļ�һ�㰲װ��  
    
    /usr/include  
�����ļ�һ�㶼���� 
     
     /usr/lib/x86_64-linux-gnu   
Ŀ¼�¡�����libboost_system.a�ļ���  

��β鿴��ǰ��װ��boost�汾  

    dpkg -S /usr/include/boost/version.hpp 

ͨ������������Ϳ��Է���boost�İ汾�ˣ��鿴����������£�  
    
    libboost1.54-dev: /usr/include/boost/version.hpp  

�� ���ɾ����ǰ��װ��boost   

sudo apt-get autoremove libboost1.54-dev   
��ô�Ϳ���ɾ��boost�ˡ������libboost1.54-dev���ڵ�һ���п����İ汾��  
ע����ǣ������ʹ�õ����������װ��boost  

    sudo apt-get install libboost-dev   

��ô���п��ܣ���Ŀ¼/usr/lib/x86_64-linux-gnu�²�û��libboost_system.a���ļ��������Ҫע��ġ�



��libboost_filesystem.so �Ҳ���
����   
 
    apt-get install libboost-filesystem-dev ������װ
�ð�װ�󣬻���

    root@jiudianren:/usr/lib/x86_64-linux-gnu# ls  -l libboo*
    -rw-r--r-- 1 root root 296414 Mar  6 10:21 libboost_filesystem.a
    lrwxrwxrwx 1 root root     29 Mar  6 10:21 libboost_filesystem.so -> libboost_filesystem.so.1.65.1
    -rw-r--r-- 1 root root 105248 Mar  6 10:21 libboost_filesystem.so.1.65.1
    -rw-r--r-- 1 root root  63710 Mar  6 10:21 libboost_system.a
    lrwxrwxrwx 1 root root     25 Mar  6 10:21 libboost_system.so -> libboost_system.so.1.65.1
    -rw-r--r-- 1 root root  18544 Mar  6 10:21 libboost_system.so.1.65.1
���ϵ����ӿ�



#Boost Docker 

https://hub.docker.com/r/zouzias/boost/
  