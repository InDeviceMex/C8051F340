/*
 * EXTI.c
 *
 *  Created on: 09/02/2020
 *      Author: vyldram
 */

#include <EXTI.h>


void EXT0_vInit(void)
{
	IT01CF&=~0xF;
	IT01CF|=0x9; //external interrupt in P0.1, INT0 active high

	P0MDOUT&=~0x2; //P0.1 open-drain output
	P0MDIN|=0x2; //P0.1 digital input
	P0SKIP|=0x2; //P0.1 skip in crossbar
	P0|= 0x2; //P0.1 to high impedance

	EX0=1; //enable External INT0
	PX0=1; //high prioprity
	IT0=1; //edge sensitive
}

void EXT1_vInit(void)
{
	IT01CF&=~0xF0;
	IT01CF|=0xA0; //external interrupt in P0.2, INT1 active high

	P0MDOUT&=~0x4; //P0.2 open-drain output
	P0MDIN|=0x4; //P0.2 digital input
	P0SKIP|=0x4; //P0.2 skip in crossbar
	P0|= 0x4; //P0.2 to high impedance

	EX1=1; //enable External INT0
	PX1=1; //high prioprity
	IT1=1; //edge sensitive
}


INTERRUPT(EXT0_ISR, INTERRUPT_INT0)
{
	IE0=0; //reset Flag for INT0
	P2^=0x4; //Toggle P2.2
}

INTERRUPT(EXT1_ISR, INTERRUPT_INT1)
{
	IE1=0; //reset Flag for INT0
	P2^=0x8; //Toggle P2.3
}

