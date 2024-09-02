/*
Author: Siarhei Baldzenka (sbaldzenka)
Data  : 09.08.2022
E-mail: venera.electronica@gmail.com
*/

#include <avr/io.h>
#include <util/delay.h>

void main(void)
{
    // GPIO
    // PORTB0 = out, value = 0
    // PORTB1 = out, value = 0
    // PORTB2 = out, value = 0
    // PORTB3 = out, value = 0
    // PORTB4 = out, value = 0
    DDRB |= (1 << PB4) | (1 << PB3) | (1 << PB2) | (1 << PB1) | (1 << PB0);
    PORTB = 0x00;

    while(1)
    {
        PORTB = (1 << PB0);
        _delay_ms(100);
        PORTB = (1 << PB1);
        _delay_ms(100);
        PORTB = (1 << PB2);
        _delay_ms(100);
        PORTB = (1 << PB3);
        _delay_ms(100);
        PORTB = (1 << PB4);
        _delay_ms(100);
    }
}