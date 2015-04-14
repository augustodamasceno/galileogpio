/* Library galileogpio, easy access to Intel Galileo GPIOs.
 * 
 * Copyright (c) 2015, Augusto Damasceno(@augustomatheuss), Carlos Bentzen(@cadubentzen), Sérgio Roza(@kalmik).
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 * 
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 */

#ifndef GALILEOGPIO_H
#define	GALILEOGPIO_H

#include <stdio.h>
#include <string.h>

#define HIGH 1
#define LOW 0
#define IN "in"
#define OUT "out"
#define PULLUP "pullup"
#define PULLDOWN "pulldown"
#define STRONG "strong"
#define HIZ "hiz"
#define IO0 50
#define IO0A 40
#define IO1 51
#define IO1A 41
#define IO2 32
#define IO2A 31
#define IO3 18
#define IO3A 30
#define IO4 28
#define IO5 17
#define IO6 24
#define IO7 27
#define IO8 26
#define IO9 19
#define IO10 16
#define IO10A 42
#define IO11 25
#define IO11A 43
#define IO12 38
#define IO12A 54
#define IO13 39
#define IO13A 55
#define ADMUX0 37
#define ADMUX1 36
#define ADMUX2 23
#define ADMUX3 22
#define ADMUX4A 21
#define ADMUX4B 29
#define ADMUX5A 20
#define ADMUX5B 29
#define A0 0
#define A1 1
#define A2 2
#define A3 3
#define A4 4
#define A5 5
#define PWM3 3
#define PWM5 5
#define PWM6 6
#define PWM9 1
#define PWM10 7
#define PWM11 4
#define US 1000
#define MS 1000000


// File Manipulation.

int writeString (char * f, char * t);

int writeInt (char * f, int t);

int writeLint (char * f, unsigned long int t);

int readString (char * f, char * t);

int readInt (char * f); 

// Digital IOs

int exportDigital(unsigned char n);

int direction(unsigned char n, unsigned char * d);

int drive(unsigned char n, unsigned char * d);

int setDigital(unsigned char n, unsigned char d);

int getDigital(unsigned char n);

// Analog Inputs
/*
// Wouldn't be easier just a exportAnalog?
int exportAnalog (unsigned char n);
//int setADmux(unsigned char n);

int getAnalog(unsigned char n);
*/

// PWM

int exportPWM(unsigned char n);

int unexportPWM(unsigned char n);

int enablePWM(unsigned char n);

int disablePWM(unsigned char n);

int setPeriodPWM(unsigned char n, unsigned long int period);

int setDutyCyclePWM(unsigned char n, unsigned long int dutyCycle);

int initPWM(unsigned char n, unsigned long int period,
    unsigned long int dutyCycle);

// Counters


// Interrupts


#endif
