#include <msp430g2553.h>
#include <stdlib.h>
#include "moteur.h"
#include "parametrage.h"
#include "spi.h"


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	 init_USCI( );
	Send_char_SPI();


	ch_init ();
	ch_move(70);
	__delay_cycles (100);
	ch_move_right(70);
	__delay_cycles (50);
	ch_move_left(70);
	__delay_cycles(50);



	return 0;
}
