
#ifndef __EINT_H
#define __EINT_H

#define EINT2 2

class eint2 
{
private:
	static volatile int switch_released;
public:
	eint2();
	static int get_switch_released();
	static void set_switch_released(int switch_released);
};

extern "C" {
	void EINT2_IRQHandler(void);
}

#endif

