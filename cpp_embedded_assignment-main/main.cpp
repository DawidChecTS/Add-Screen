#include "include/millis.h"
#include "include/lcd_driver.hpp"
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "include/millis.h"
#include "include/lcd_driver.hpp"
#include "include/CoolCars.h"
#include "include/GymboJames.h"
#include "include/HolyBurgers.h"
#include "include/PiePeople.h"
#include "include/Washomania.h"

#include <avr/interrupt.h>
#include <stdlib.h>

#define NUM_ADVERTISERS 5

static Advertiser* advertisers[NUM_ADVERTISERS] = {
    &coolcars,
    &gymbojames,
    &holyburgers,
    &piepeople,
    &washomania
};

static Advertiser* pickAdvertiser(void) {
    unsigned int roll = rand() % 20850;

    if (roll < 1750){return &holyburgers;} 
    else if (roll < 1750 + 2500) {return &piepeople;}
    else if (roll < 1750 + 2500 + 4900) {return &washomania;}
    else if (roll < 1750 + 2500 + 4900 + 5000) {return &coolcars;}
    else {return &gymbojames;}
}

int main(void) {
    millis_init(); 
    sei();

    hd44780 lcd;
  

    while(1) {
        Advertiser* current = pickAdvertiser();

        lcd.write_text(current->name);
        millis_wait_ms(5000);
    }

    return 0;
}