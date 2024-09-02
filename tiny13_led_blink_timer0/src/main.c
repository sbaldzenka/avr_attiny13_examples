/*
Author: Siarhei Baldzenka (sbaldzenka)
Data  : 09.08.2022
E-mail: venera.electronica@gmail.com
*/

#include <avr/io.h>

void main(void)
{
    uint16_t counter = 0;
    uint8_t value = 0;

    // GPIO
    // PORTB0 = out, value = 1
    // PORTB1 = out, value = 0
    // PORTB2 = out, value = 0
    // PORTB3 = out, value = 0
    // PORTB4 = out, value = 0
    DDRB |= (1 << PB4) | (1 << PB3) | (1 << PB2) | (1 << PB1) | (1 << PB0);
    PORTB = (1 << PB0);

    // Timer/Counter 0
    // Normal mode
    TCCR0A = 0x00;
    TCCR0B = (1 << CS00);
    TCNT0 = 0x00;

    while(1)
    {
        if (TCNT0 == 0xFF)
            counter++;

        if (counter == 0x05DC)
        {
            TCNT0 = 0x00;
            counter = 0x00;
            value++;

            if (value == 5)
                value = 0;

            switch (value)
            {
                case 0:
                    PORTB = (1 << PB0);
                    break;
                case 1:
                    PORTB = (1 << PB1);
                    break;
                case 2:
                    PORTB = (1 << PB2);
                    break;
                case 3:
                    PORTB = (1 << PB3);
                    break;
                case 4:
                    PORTB = (1 << PB4);
                    break;
            }
        }
    }
}