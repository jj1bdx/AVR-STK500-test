/*
 *  main.c
 *  test project for AVR ATMega8515L
 *
 *  Kenji Rikitake
 *  Copyright (c) 2015 by Kenji Rikitake.
 *  MIT License
 */

#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>

#define F_CPU 8000000UL
#include <util/delay.h>

/* definitions */

#define OutPort PORTB
#define OutDDR  DDRB

int main(void)
{
    int i;

    i = 1;
    OutDDR = 0xff;

    _delay_ms(500);

    while (1) /* Forever */
    {
        OutPort = i;
        _delay_ms(500);
        i <<= 1;
        if (i > 255) {
            i = 1;
        }

    }
    return 0;
}
