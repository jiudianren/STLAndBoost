Boost.Asio֧��ʹ����Ϊsignal_set��������źŴ������������������һ�������źţ�Ȼ��ִ�� ������������һ���źų���ʱ��������ָ���Ĵ�����򡣿�������signal_set ����ע����ͬ���źű�ţ����źű�ű������Boost.Asioһ��ʹ�á� async_wait()

void  handler ��
    const  boost :: system :: error_code �� error ��
    int  signal_number ��
{ 
  if  ����error ��
  { 
    //������һ���źš�
  } 
}

...

//����Ϊ������ֹע����źż���
boost :: asio :: signal_set  �źţ�io_service �� SIGINT �� SIGTERM ��;

//��ʼ�첽�ȴ�����һ���źŷ�����
�źš�async_wait ��handler ��;
�źŴ���Ҳ������Windows����ΪMicrosoft Visual C ++����ʱ�⽫����̨�¼�����Ctrl + C��ӳ�䵽��Ч�źš�
