/*
 * parametrage.c
 *
 *  Created on: 14 avr. 2018
 *      Author: LENOVO
 */
#include <msp430.h>
#include "parametrage.h"

///////////////////////////////////////////////////////////////
// Initialise les clocks, les leds et le bouton interruption //
///////////////////////////////////////////////////////////////
void param_init()
{
    // Clocks and WatchDog
    WDTCTL = WDTPW | WDTHOLD;
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;

    // LED 1 & 2
    P1DIR |= (BIT0 | BIT6);
    P1OUT &= ~(BIT0 | BIT6);

    // Button S2
    P1SEL &= ~(BIT3);
    P1SEL2 &= ~(BIT3);
    P1DIR &= ~(BIT3);
    P1REN |= (BIT3);
    P1OUT |= (BIT3);
    P1IE |= (BIT3);
    P1IES |= (BIT3);
    P1IFG &= ~(BIT3);
    __enable_interrupt();
}

///////////////////////////////////////////////////////////////
// Initialise une entrée directement                         //
///////////////////////////////////////////////////////////////
void param_initInput(int port, int input)
{
    if (port == 1)
    {
        P1SEL &= ~(input);
        P1SEL2 &= ~(input);
        P1DIR &= ~(input);
        P1REN |= (input);
        P1OUT |= (input);
    }
    else if (port == 2)
    {
        P2SEL &= ~(input);
        P2SEL2 &= ~(input);
        P2DIR &= ~(input);
        P2REN |= (input);
        P2OUT |= (input);
    }
}

///////////////////////////////////////////////////////////////
// Initialise une sortie directement                         //
///////////////////////////////////////////////////////////////
void param_initOutput(int port, int output)
{
    if (port == 1)
    {
        P1SEL &= ~(output);
        P1SEL2 &= ~(output);
        P1DIR |= (output);
    }
    else if (port == 2)
    {
        P2SEL &= ~(output);
        P2SEL2 &= ~(output);
        P2DIR |= (output);
    }
}

///////////////////////////////////////////////////////////////
// Initialise une entrée d'interruption                      //
///////////////////////////////////////////////////////////////
void param_initInterrupt(int port, int input)
{
    if (port == 1)
    {
        P1SEL &= ~(input);
        P1SEL2 &= ~(input);
        P1DIR &= ~(input);
        P1REN |= (input);
        P1OUT &= ~(input);
        P1IE |= (input);
        P1IES |= (input);
        P1IFG &= ~(input);
    }
    else if (port == 2)
    {
        P2SEL &= ~(input);
        P2SEL2 &= ~(input);
        P2DIR &= ~(input);
        P2REN |= (input);
        P2OUT &= ~(input);
        P2IE |= (input);
        P2IES |= (input);
        P2IFG &= ~(input);
    }
}

///////////////////////////////////////////////////////////////
// Allume ou éteint la led 1 (1 = on, 0 = off)               //
///////////////////////////////////////////////////////////////
void param_led1(unsigned int on)
{
    if (on == 1)
    {
        P1OUT |= BIT0;
    }
    else
    {
        P1OUT &= ~(BIT0);
    }
}

///////////////////////////////////////////////////////////////
// Allume ou éteint la led 2 (1 = on, 0 = off)               //
///////////////////////////////////////////////////////////////
void param_led2(unsigned int on)
{
    if (on == 1)
    {
        P1OUT |= BIT6;
    }
    else
    {
        P1OUT &= ~(BIT6);
    }
}

///////////////////////////////////////////////////////////////
// Convertit une pin désirée en un BITX pour les registres   //
///////////////////////////////////////////////////////////////
unsigned int param_pinToBit(unsigned int pin)
{
    if (pin == 0) return BIT0;
    if (pin == 1) return BIT1;
    if (pin == 2) return BIT2;
    if (pin == 3) return BIT3;
    if (pin == 4) return BIT4;
    if (pin == 5) return BIT5;
    if (pin == 6) return BIT6;
    if (pin == 7) return BIT7;
    return pin;
}



