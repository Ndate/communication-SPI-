#include <msp430.h>
#include "Moteur.h"
#include "parametrage.h"

/*********************************************************************************************************
 * Fonction ch_init
 *
 * Elle permet d'initialiser les roues du SAMbot, composé de ses 2 moteurs ( un pour chaque roue )
 ********************************************************************************************************/
void ch_init()
{
    // init PWM
    TA1CTL = TASSEL_2 | MC_0 | ID_1;
    TA1CCTL1 |= OUTMOD_7;
    TA1CCTL2 |= OUTMOD_7;
    TA1CCR0 = 100;

    // init Engine Left
    param_initOutput(2, BIT2);
    P2SEL |= BIT2;
    P2SEL2 &= ~(BIT2);
    param_initOutput(2, BIT1);
    P2OUT &= ~(BIT1);
    param_initInterrupt(2, BIT0);

    // init Engine Right
    param_initOutput(2, BIT4);
    P2SEL |= BIT4;
    P2SEL2 &= ~(BIT4);
    param_initOutput(2, BIT5);
    P2OUT &= ~(BIT5);
    param_initInterrupt(2, BIT3);
}

/*********************************************************************************************************
 * Fonction ch_move_right
 *
 * Elle permet de faire tourner à droite le robot avec une vitesse donnée en paramètre
 ********************************************************************************************************/
void ch_move_right(int speed)
{
    P2OUT &= ~(BIT1); // Forward Engine Left
    P2OUT |= (BIT5); // Forward Engine Right
    TA1CCR1 = 0; // Speed Engine Left
    TA1CCR2 = speed; // Speed Engine Right
    TA1CTL |= MC_1;
}

/*********************************************************************************************************
 * Fonction ch_move_left
 *
 * Elle permet de faire tourner à gauche le robot avec une vitesse donnée en paramètre
 ********************************************************************************************************/
void ch_move_left(int speed)
{
    P2OUT &= ~(BIT1); // Forward Engine Left
    P2OUT |= (BIT5); // Forward Engine Right
    TA1CCR1 = speed; // Speed Engine Left
    TA1CCR2 = 0; // Speed Engine Right
    TA1CTL |= MC_1;
}

/*********************************************************************************************************
 * Fonction ch_move
 *
 * Elle permet de faire avancer tout droit le robot avec une vitesse donnée en paramètre
 ********************************************************************************************************/
void ch_move(int speed)
{
    P2OUT &= ~(BIT1); // Forward Engine Left
    P2OUT |= (BIT5); // Forward Engine Right
    TA1CCR1 = speed; // Speed Engine Left
    TA1CCR2 = speed; // Speed Engine Right
    TA1CTL |= MC_1;
}

void ch_back(int speed)
{
    P2OUT &= ~(BIT1); // Forward Engine Left
    P2OUT |= (BIT5); // Forward Engine Right
    TA1CCR1 = -speed; // Speed Engine Left
    TA1CCR2 = -speed; // Speed Engine Right
    TA1CTL |= MC_1;
}
