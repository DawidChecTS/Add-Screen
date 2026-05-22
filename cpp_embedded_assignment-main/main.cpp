#include "include/millis.h"
#include "include/lcd_driver.hpp"
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "include/CoolCars.h"
#include "include/GymboJames.h"
#include "include/HolyBurgers.h"
#include "include/PiePeople.h"
#include "include/Washomania.h"
#include <stdlib.h>

#define NUM_ADVERTISERS 5

static Advertiser* pickAdvertiser(void) {
    // Roll a random number between 0 and the total amount paid by all advertisers
    unsigned int roll = rand() % 20850;

    // Pick an advertiser based on the amount they paid
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
        // Pick an advertiser based on the amount they paid
        Advertiser* current = pickAdvertiser();

        // Display the advertiser's name for 5 seconds
        lcd.write_text(current->name);
        millis_wait_ms(5000);

        // Display the current message for the advertiser
        Message msg = current->messages[current->current_index];

        // Move to the next message for the advertiser
        if (msg.type == PLAIN) {
            lcd.write_text(msg.text);
            millis_wait_ms(10000);
        } else if (msg.type == BLINK) {
            lcd.blink_text(msg.text);
        }

        // Go to the next message index
        current->current_index++;
        if (current->current_index >= current->message_count) {
            current->current_index = 0;
        }
    }

    return 0;
}