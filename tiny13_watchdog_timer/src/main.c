/*
Author: Siarhei Baldzenka (sbaldzenka)
Data  : 14.08.2022
E-mail: venera.electronica@gmail.com
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void main(void)
{
    // GPIO
    // PORTB0 = out, value = 0
    // PORTB1 = in,  value = 0
    // PORTB2 = in,  value = 0
    // PORTB3 = in,  value = 0
    // PORTB4 = in,  value = 0
    DDRB = (1 << PB0);
    PORTB = 0x00;

    // Watchdog timer
    WDTCR = (1 << WDE) | (1 << WDTIE) | (1 << WDP3) | (1 << WDP0);

    // Global interrupt enable
    sei();

    while(1)
    {
        PORTB = (1 << PB0);
    }
}

ISR(WDT_vect)
{
    PORTB = 0x00;
    _delay_ms(1000);

    // Returns from an interrupt routine
    reti();
}