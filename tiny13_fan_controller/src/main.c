/*
Author: Siarhei Baldzenka (sbaldzenka)
Data  : 02.11.2022
E-mail: venera.electronica@gmail.com
*/

#include <avr/io.h>
#include <util/delay.h>
#include "init_mcu.h"

void main(void)
{
    init_mcu();

    while(1)
    {
        ADCSRA |= (1 << ADSC);
        OCR0B = ADCH;
    }
}