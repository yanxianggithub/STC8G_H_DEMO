/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCAI.com ---------------------------------------------*/
/* --- BBS: www.STCAIMCU.com  -----------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* 如果要在程序中使用此代码,请在程序中注明使用了STC的资料及程序            */
/*---------------------------------------------------------------------*/

/*************	功能说明	**************

本文件为模拟串口发送程序, 一般为测试监控用.

串口参数:9600,8,n,1.

可以根据主时钟自动适应.

******************************************/

#include	"STC8G_H_Soft_UART.h"

sbit	P_TXD = P3^1;	//定义模拟串口发送端,可以是任意IO

//========================================================================
// 函数: void	BitTime(void)
// 描述: 位时间函数。
// 参数: none.
// 返回: none.
// 版本: VER1.0
// 日期: 2013-4-1
// 备注: 
//========================================================================
void	BitTime(void)
{
	u16 i;
	i = ((MAIN_Fosc / 100) * 138) / 130000L - 1;		//根据主时钟来计算位时间
	while(--i);
}

//========================================================================
// 函数: void	TxSend(uchar dat)
// 描述: 模拟串口发送一个字节。9600，N，8，1
// 参数: dat: 要发送的数据字节.
// 返回: none.
// 版本: VER1.0
// 日期: 2013-4-1
// 备注: 
//========================================================================
void	TxSend(u8 dat)
{
	u8	i;
	EA = 0;
	P_TXD = 0;
	BitTime();
	for(i=0; i<8; i++)
	{
		if(dat & 1)		P_TXD = 1;
		else			P_TXD = 0;
		dat >>= 1;
		BitTime();
	}
	P_TXD = 1;
	EA = 1;
	BitTime();
	BitTime();
}

//========================================================================
// 函数: void PrintString(unsigned char code *puts)
// 描述: 模拟串口发送一串字符串。9600，N，8，1
// 参数: *puts: 要发送的字符指针.
// 返回: none.
// 版本: VER1.0
// 日期: 2013-4-1
// 备注: 
//========================================================================
void PrintString(unsigned char code *puts)
{
    for (; *puts != 0;	puts++)  TxSend(*puts);
}

