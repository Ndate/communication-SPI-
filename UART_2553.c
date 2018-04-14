#include <msp430.h>
#include "UART_2553.h"


/*********************************************************************************************************
 * Fonction init_UART
 *
 * Elle permet d'initialiser la Launchpad pour la communication UART
 ********************************************************************************************************/
void init_UART( void )
{
    P1SEL  |= (BIT1 | BIT2);                    // P1.1 = RXD, P1.2=TXD
    P1SEL2 |= (BIT1 | BIT2);                    // P1.1 = RXD, P1.2=TXD
    UCA0CTL1 |= UCSWRST;                        // SOFTWARE RESET
    UCA0CTL1 |= UCSSEL_2;                       // SMCLK (2 - 3)
    UCA0BR0 = 104;                             // 104 1MHz, OSC16, 9600 (8Mhz : 52) : 8 115k - 226/12Mhz
    UCA0BR1 = 0;                                // 1MHz, OSC16, 9600 - 4/12Mhz
    UCA0MCTL = 10;
    UCA0CTL0 &= ~(UCPEN  | UCMSB | UCDORM);
    UCA0CTL0 &= ~(UC7BIT | UCSPB  | UCMODE_3 | UCSYNC); // dta:8 stop:1 usci_mode3uartmode
    UCA0CTL1 &= ~UCSWRST;                       // **Initialize USCI state machine**
    /* Enable USCI_A0 RX interrupt */
    IE2 |= UCA0RXIE;
}

/*********************************************************************************************************
 * Fonction envoi_msg_UART
 *
 * Elle permet d'envoyer un message par l'UART
 ********************************************************************************************************/
void envoi_msg_UART(unsigned char *msg)
{
    unsigned int i = 0;
    for(i=0 ; msg[i] != 0x00 ; i++)
    {
        while(!(IFG2 & UCA0TXIFG));    //attente de fin du dernier envoi (UCA0TXIFG à 1 quand UCA0TXBUF vide)
        UCA0TXBUF=msg[i];
    }
}
