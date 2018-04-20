/*
 * parametrage.h
 *
 *  Created on: 14 avr. 2018
 *      Author: LENOVO
 */

#ifndef PARAMETRAGE_H_
#define PARAMETRAGE_H_

void param_init();

void param_initInput(int port, int input);

void param_initOutput(int port, int output);

void param_initInterrupt(int port, int input);

void param_led1(unsigned int on);

void param_led2(unsigned int on);

unsigned int param_pinToBit(unsigned int pin);



#endif /* PARAMETRAGE_H_ */
