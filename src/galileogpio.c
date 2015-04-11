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
    return writeInt("/sys/class/gpio/export",n);
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
/*
int exportAnalog (unsigned char n)
{
	switch(n)
	{
		case ANALOG0:
			return -!(!exportIO(ADMUX0) && !direction(OUT) && !setValue(LOW));
			break;
		case ANALOG1:
			return -!(!exportIO(ADMUX1) && !direction(OUT) && !setValue(LOW));
			break;
		case ANALOG2:
			return -!(!exportIO(ADMUX2) && !direction(OUT) && !setValue(LOW));
			break;
		case ANALOG3:
			return -!(!exportIO(ADMUX3) && !direction(OUT) && !setValue(LOW));
			break;
		case ANALOG4:
			return -!(!exportIO(ADMUX4A) && !direction(OUT) && !setValue(LOW) && !exportIO(ADMUX4B) && !direction(OUT) && !setValue(HIGH));
			break;
		case ANALOG5:
			return -!(!exportIO(ADMUX5A) && !direction(OUT) && !setValue(LOW) && !exportIO(ADMUX5B) && !direction(OUT) && !setValue(HIGH));
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
*/