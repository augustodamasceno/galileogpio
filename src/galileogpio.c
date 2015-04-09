/* Library galileogpio, easy access to Intel Galileo GPIOs.
 * 
 * Copyright (c) 2015, Augusto Damasceno, Eduardo ..., Sérgio ... .
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

// comentei so de zoa xD

int write(char * f, char * t)
{
     FILE * rF;
     rF = fopen(f,"w");
     if (rF != NULL)
     {
        fprintf (rF,"%s",t);
        fclose (rF);
        return 0;
     }
     else
     {
         return -1;
     }
}

int read(char * f, char * t)
{
     FILE * rF;
     rF = fopen (f,"r");
     if (rF != NULL)
     {
        fscanf (rF,"%s",t);
        fclose (rF);
        return 0;
     }
     else
     {
         return -1;
     }
}

// Digital IOs

int exportIO(unsigned char * n)
{
    if (n > 0 && n < RANGE_IO)
    {
        return write("/sys/class/gpio/export",n);
    }
    else
    {
        return -1;
    }
}

int direction(unsigned char n, unsigned char * d)
{
    if (n > 0 && n < RANGE_IO)
    {
        // Escreva "in" no arquivo /sys/class/gpio/export se d == 0
        // Escreva "out" no arquivo /sys/class/gpio/export se d == 1
    }
    else
    {
        return -1;
    }
}

int drive(unsigned char n, unsigned char * d)
{
    if (n > 0 && n < RANGE_IO)
    {
        // Escreva "in" no arquivo /sys/class/gpio/export se d == 0
        // Escreva "out" no arquivo /sys/class/gpio/export se d == 1
    }
    else
    {
        return -1;
    }
}

int setValue(unsigned char n)
{
    if (n > 0 && n < RANGE_IO)
    {
        // Escreva n no arquivo /sys/class/gpio/export
    }
    else
    {
        return -1;
    }
}

int getValue(unsigned char n)
{
    if (n > 0 && n < RANGE_IO)
    {
        // ler arquivo /sys/class/gpio/gpio<n>/value e retornar valor inteiro.
    }
    else
    {
        return -1;
    }
}
