#include "include/millis.h"
#include "include/lcd_driver.hpp"

#include <avr/pgmspace.h>
#include <avr/interrupt.h>

int main(void) {
    millis_init(); 
    sei();

    hd44780 lcd;
  

    while(1) {
        lcd.write_text("Hello, World!"); 
        _delay_ms(2000);
        lcd.clear();
        _delay_ms(500);
    }

    return 0;
}