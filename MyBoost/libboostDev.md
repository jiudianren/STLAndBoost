ubuntu ��װ  

1 ������»�����û��ubunu��װ��gearman����ôֱ��һ������ ִ���������  
sudo apt-get install libboost-all-dev  
ͷ�ļ�һ�㰲װ��  
/usr/include  

������һ��Ŀ¼boost��������ͷ�ļ��������ļ�һ�㶼����  
/usr/lib/x86_64-linux-gnu   

Ŀ¼�¡�����libboost_system.a�ļ���  
һ ��β鿴��ǰ��װ��boost�汾  

dpkg -S /usr/include/boost/version.hpp 

ͨ������������Ϳ��Է���boost�İ汾�ˣ��鿴����������£�  
libboost1.54-dev: /usr/include/boost/version.hpp  

�� ���ɾ����ǰ��װ��boost
sudo apt-get autoremove libboost1.54-dev   
��ô�Ϳ���ɾ��boost�ˡ������libboost1.54-dev���ڵ�һ���п����İ汾��  
ע����ǣ������ʹ�õ����������װ��boost  

sudo apt-get install libboost-dev   
��ô���п��ܣ���Ŀ¼/usr/lib/x86_64-linux-gnu�²�û��libboost_system.a���ļ��������Ҫע��ġ�  