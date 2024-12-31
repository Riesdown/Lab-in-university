#include <sys/some_define/define.hpp>


/*****************用于计算频率*****************/
u16 fps1; // 缓冲
u16 fps;

hw_timer_t * timer0 = NULL;
void Tomer0_Hander()
{
	fps = fps1;
	fps1 = 0;
}