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

#include "galileogpio.h"

// File manipulation

int writeString (char * f, char * t)
{
    FILE * rF;
    rF = fopen(f,"r+");
    if (rF == NULL)
    {
	return -1;
    }
    fprintf (rF,"%s",t);
    fclose (rF);
    return 0;
}

int writeInt (char * f, int t)
{
    FILE * rF;
    rF = fopen(f,"r+");
    if (rF == NULL)
    {
	return -1;
    }
    fprintf (rF,"%d",t);
    fclose (rF);
    return 0;
}

int writeLint (char * f, unsigned long int t)
{
    FILE * rF;
    rF = fopen(f,"r+");
    if (rF == NULL)
    {
	return -1;
    }
    fprintf (rF,"%lu",t);
    fclose (rF);
    return 0;
}

int readString (char * f, char * t)
{
    FILE * rF;
    rF = fopen (f,"r+");
    if (rF == NULL)
    {
        return -1;
    }
    fscanf (rF,"%s",t);
    fclose (rF);
    return 0;
}

int readInt (char * f)
{
    FILE * rF;
    int value;
    rF = fopen (f,"r+");
    if (rF == NULL)
    {
        return -1;
    }
    fscanf (rF,"%d",&value);
    fclose (rF);
    return value;
}

// Digital IOs

int exportIO(unsigned char n)
{
    int r;
    switch (n)
    {
        case (IO0):
            r = writeInt("/sys/class/gpio/export",IO0);
            r += writeInt("/sys/class/gpio/export",IO0A);
            r += direction(IO0A,OUT);
            r += setDigital(IO0A,HIGH);
            return r;
            break;
        case (IO1):
            r = writeInt("/sys/class/gpio/export",IO1);
            r += writeInt("/sys/class/gpio/export",IO1A);
            r += direction(IO1A,OUT);
            r += setDigital(IO1A,HIGH);
            return r;
            break;
        case (IO2):
            r = writeInt("/sys/class/gpio/export",IO2);
            r += writeInt("/sys/class/gpio/export",IO2A);
            r += direction(IO2A,OUT);
            r += setDigital(IO2A,HIGH);
            return r;
            break;
        case (IO3):
            r = writeInt("/sys/class/gpio/export",IO3);
            r += writeInt("/sys/class/gpio/export",IO3A);
            r += direction(IO3A,OUT);
            r += setDigital(IO3A,HIGH);
            return r;
            break;
        case (IO10):
            r = writeInt("/sys/class/gpio/export",IO10);
            r += writeInt("/sys/class/gpio/export",IO10A);
            r += direction(IO10A,OUT);
            r += setDigital(IO10A,HIGH);
            return r;
            break;
        case (IO11):
            r = writeInt("/sys/class/gpio/export",IO11);
            r += writeInt("/sys/class/gpio/export",IO11A);
            r += direction(IO11A,OUT);
            r += setDigital(IO11A,HIGH);
            return r;
            break;
        case (IO12):
            r = writeInt("/sys/class/gpio/export",IO12);
            r += writeInt("/sys/class/gpio/export",IO12A);
            r += direction(IO12A,OUT);
            r += setDigital(IO12A,HIGH);
            return r;
            break;
        case (IO13):
            r = writeInt("/sys/class/gpio/export",IO13);
            r += writeInt("/sys/class/gpio/export",IO13A);
            r += direction(IO13A,OUT);
            r += setDigital(IO13A,HIGH);
            return r;
            break;
        default:
            return writeInt("/sys/class/gpio/export",n);
    }
}

int unexportIO(unsigned char n)
{
    int r;
    switch (n)
    {
        case (IO0):
            r = writeInt("/sys/class/gpio/unexport",IO0);
            r += writeInt("/sys/class/gpio/unexport",IO0A);
            return r;
            break;
        case (IO1):
            r = writeInt("/sys/class/gpio/unexport",IO1);
            r += writeInt("/sys/class/gpio/unexport",IO1A);
            return r;
            break;
        case (IO2):
            r = writeInt("/sys/class/gpio/unexport",IO2);
            r += writeInt("/sys/class/gpio/unexport",IO2A);
            return r;
            break;
        case (IO3):
            r = writeInt("/sys/class/gpio/unexport",IO3);
            r += writeInt("/sys/class/gpio/unexport",IO3A);
            return r;
            break;
        case (IO10):
            r = writeInt("/sys/class/gpio/unexport",IO10);
            r += writeInt("/sys/class/gpio/unexport",IO10A);
            return r;
            break;
        case (IO11):
            r = writeInt("/sys/class/gpio/unexport",IO11);
            r += writeInt("/sys/class/gpio/unexport",IO11A);
            return r;
            break;
        case (IO12):
            r = writeInt("/sys/class/gpio/unexport",IO12);
            r += writeInt("/sys/class/gpio/unexport",IO12A);
            return r;
            break;
        case (IO13):
            r = writeInt("/sys/class/gpio/unexport",IO13);
            r += writeInt("/sys/class/gpio/unexport",IO13A);
            return r;
            break;
        default:
            return writeInt("/sys/class/gpio/unexport",n);
    }
}

int direction(unsigned char n, unsigned char * d)
{
    char f [34];
    sprintf(f,"/sys/class/gpio/gpio%d/direction",n);
    return writeString(f,d);
}

int drive(unsigned char n, unsigned char * d)
{
    char f [30];
    sprintf(f,"/sys/class/gpio/gpio%d/drive",n);
    return writeString(f,d);	
}

int setDigital(unsigned char n, unsigned char d)
{
    char f [30];
    sprintf(f,"/sys/class/gpio/gpio%d/value",n);
    return writeInt(f,d);
}

int getDigital(unsigned char n)
{
    char f [30];
    sprintf(f,"/sys/class/gpio/gpio%d/value",n);
    return readInt(f);
}

// Analog Inputs

int enableAnalog (unsigned char n)
{
	int r;
	switch(n)
	{
		case A0:
			r = exportIO(ADMUX0);
			r += direction(ADMUX0,OUT);
			r += setDigital(ADMUX0,LOW);
			return r;
			break;
		case A1:
			r = exportIO(ADMUX1);
			r += direction(ADMUX1,OUT);
			r += setDigital(ADMUX1,LOW);
			return r;
			break;
		case A2:
			r = exportIO(ADMUX2);
			r += direction(ADMUX2,OUT);
			r += setDigital(ADMUX2,LOW);
			return r;
			break;
		case A3:
			r = exportIO(ADMUX3);
			r += direction(ADMUX3,OUT);
			r += setDigital(ADMUX3,LOW);
			return r;
			break;
		case A4:
			r = exportIO(ADMUX4A);
			r += direction(ADMUX4A,OUT);
			r += setDigital(ADMUX4A,LOW);
			r += exportIO(ADMUX4B);
			r += direction(ADMUX4B,OUT);
			r += setDigital(ADMUX4B,HIGH);
			return r;
			break;
		case A5:
			r = exportIO(ADMUX5A);
			r += direction(ADMUX5A,OUT);
			r += setDigital(ADMUX5A,LOW);
			r += exportIO(ADMUX5B);
			r += direction(ADMUX5B,OUT);
			r += setDigital(ADMUX5B,HIGH);
			return r;
			break;
		default:
			return -1;
			break;
	}
}

int disableAnalog (unsigned char n)
{
	int r;
	switch(n)
	{
		case A0:
			r = unexportIO(ADMUX0);
			return r;
			break;
		case A1:
			r = unexportIO(ADMUX1);
			return r;
			break;
		case A2:
			r = unexportIO(ADMUX2);
			return r;
			break;
		case A3:
			r = unexportIO(ADMUX3);
			return r;
			break;
		case A4:
			r = unexportIO(ADMUX4A);
			r += unexportIO(ADMUX4B);
			return r;
			break;
		case A5:
			r = unexportIO(ADMUX5A);
			r += unexportIO(ADMUX5B);
			return r;
			break;
		default:
			return -1;
			break;
	}
}

int getAnalog(unsigned char n)
{
	char f[51];
	sprintf(f,"/sys/bus/iio/devices/iio:device0/in_voltage%d_raw",n);
	return readInt(f);
}


// PWM

int exportPWM(unsigned char n)
{
    return writeInt("/sys/class/pwm/pwmchip0/export",n);
}

int unexportPWM(unsigned char n)
{
    return writeInt("/sys/class/pwm/pwmchip0/unexport",n);
}

int enablePWM(unsigned char n)
{
    char f[40];
    sprintf(f,"/sys/class/pwm/pwmchip0/pwm%d/enable",n);
    writeInt(f,1);
}

int disablePWM(unsigned char n)
{
    char f[40];
    sprintf(f,"/sys/class/pwm/pwmchip0/pwm%d/enable",n);
    writeInt(f,0);
}

int setPeriodPWM(unsigned char n, unsigned long int period)
{
    char f[40];
    sprintf(f,"/sys/class/pwm/pwmchip0/pwm%d/period",n);
    writeLint(f,period);
}

int setDutyCyclePWM(unsigned char n, unsigned long int dutyCycle)
{
    char f[44];
    sprintf(f,"/sys/class/pwm/pwmchip0/pwm%d/duty_cycle",n);
    writeLint(f,dutyCycle);
}

int initPWM(unsigned char n, unsigned long int period,
    unsigned long int dutyCycle)
{
    exportPWM(n);
    enablePWM(n);
    setPeriodPWM(n,period);
    setDutyCyclePWM(n,dutyCycle);
}
