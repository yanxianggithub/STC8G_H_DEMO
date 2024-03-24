#include <intrins.h>
#include "masu.h"

#define led P20
#define rel P14
#define key P33

void Delay10ms(void);
void Delay1000ms(void);

int main()
{
	led = 1;
	rel = 1;

	while(1){
		if(key==0)
		{
			Delay10ms;
			if(key==0)
			{
				 rel = !rel;
				 while(key==0);
			}
		}
	}
	return 0;
}

void Delay1000ms(void)	//@11.0592MHz
{
	unsigned char data i, j, k;
	_nop_();
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void Delay10ms(void)	//@11.0592MHz
{
	unsigned char data i, j;

	i = 108;
	j = 145;
	do
	{
		while (--j);
	} while (--i);
}
