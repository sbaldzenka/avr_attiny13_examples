/*
Author: Siarhei Baldzenka (sbaldzenka)
Data  : 02.11.2022
E-mail: venera.electronica@gmail.com
*/

#include <avr/io.h>

void init_mcu(void)
{
    // GPIO
    // PORTB0 = in, value = 0
    // PORTB1 = out, value = ~pwm
    // PORTB2 = in, value = 0
    // PORTB3 = in, value = 0
    // PORTB4 = in, value = 0
    DDRB |= (1 << PB1);
    PORTB = 0x00;

    // Timer/Counter 0
    // PWM mode
    TCCR0A |= (1 << COM0B1) | (1 << COM0B0) | (1 << WGM01) | (1 << WGM00);
    TCCR0B |= (1 << CS01) | (1 << CS00);
    TCNT0 = 0x00;
    OCR0A = 0x00;
    OCR0B = 0x00;

    // ADC
    // ADC channel = 2
    // Vref = Vcc
    // Free Running mode
    ADMUX |= (1 << MUX1) | (1 << ADLAR);
    ADCSRA |= (1 << ADEN) | (1 << ADATE);
    DIDR0 |= (1 << ADC2D);
}