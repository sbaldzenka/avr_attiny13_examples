/*
Author: Siarhei Baldzenka (sbaldzenka)
Data  : 14.08.2022
E-mail: venera.electronica@gmail.com
*/

#include <avr/io.h>
#include <util/delay.h>

void main(void)
{
    uint8_t duty = 0;
    uint8_t updown = 0;

    // GPIO
    // PORTB0 = out, value = pwm
    // PORTB1 = in, value = 0
    // PORTB2 = in, value = 0
    // PORTB3 = in, value = 0
    // PORTB4 = in, value = 0
    DDRB = (1 << PB0);
    PORTB = 0x00;

    // Timer/Counter 0
    // PWM mode
    TCCR0A |= (1 << COM0A1)| (1 << WGM01) | (1 << WGM00);
    TCCR0B |= (1 << CS01) | (1 << CS00);
    TCNT0 = 0x00;
    OCR0A = 0x00;

    while(1)
    {
        if (updown == 0)
        {
            duty++;

            if (duty == 255)
                updown = 1;
        }

        if (updown == 1)
        {
            duty--;

            if (duty == 0)
                updown = 0;
        }

        OCR0A = duty;
        _delay_ms(5);
    }
}