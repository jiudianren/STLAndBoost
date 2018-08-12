计时器
长时间运行的I / O操作通常会有一个必须完成的截止日期。这些期限可以表示为绝对时间，但通常相对于当前时间计算。

举一个简单的例子，使用相对时间对计时器执行同步等待操作可以写：

io_service  i ; 
... 
deadline_timer  t （i ）; 
t 。expires_from_now （boost :: posix_time :: seconds （5 ））; 
t 。wait （）;
更常见的是，程序将对计时器执行异步等待操作：

void  handler （boost :: system :: error_code  ec ） {  ...  } 
... 
io_service  i ; 
... 
deadline_timer  t （i ）; 
t 。expires_from_now （boost :: posix_time :: milliseconds （400 ））; 
t 。async_wait （handler ）; 
... 
我。run （）;
与计时器相关的截止日期也可以作为相对时间获得：

boost :: posix_time :: time_duration  time_until_expiry 
  =  t 。expires_from_now （）;
或作为允许计时器组成的绝对时间：

deadline_timer  t2 （i ）; 
t2 。expires_at （吨。expires_at （） +  升压:: 了posix_time :: 秒（30 ））;