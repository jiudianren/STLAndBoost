��ʱ��
��ʱ�����е�I / O����ͨ������һ��������ɵĽ�ֹ���ڡ���Щ���޿��Ա�ʾΪ����ʱ�䣬��ͨ������ڵ�ǰʱ����㡣

��һ���򵥵����ӣ�ʹ�����ʱ��Լ�ʱ��ִ��ͬ���ȴ���������д��

io_service  i ; 
... 
deadline_timer  t ��i ��; 
t ��expires_from_now ��boost :: posix_time :: seconds ��5 ����; 
t ��wait ����;
���������ǣ����򽫶Լ�ʱ��ִ���첽�ȴ�������

void  handler ��boost :: system :: error_code  ec �� {  ...  } 
... 
io_service  i ; 
... 
deadline_timer  t ��i ��; 
t ��expires_from_now ��boost :: posix_time :: milliseconds ��400 ����; 
t ��async_wait ��handler ��; 
... 
�ҡ�run ����;
���ʱ����صĽ�ֹ����Ҳ������Ϊ���ʱ���ã�

boost :: posix_time :: time_duration  time_until_expiry 
  =  t ��expires_from_now ����;
����Ϊ�����ʱ����ɵľ���ʱ�䣺

deadline_timer  t2 ��i ��; 
t2 ��expires_at ���֡�expires_at ���� +  ��ѹ:: ��posix_time :: �루30 ����;