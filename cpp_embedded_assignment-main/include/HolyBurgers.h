#ifndef HOLYBURGERS_H_
#define HOLYBURGERS_H_

#include "Advertiser.h"

// Messages for Holy Burgers
static const Message holyburgers_messages[] = {
    {"Free drinks included in menu", PLAIN},
    {"Burgermania! 2 for 59 SEK", BLINK},
    {"Badabim... Bada BURGER!", BLINK}
};

// Advertiser struct for Holy Burgers
static Advertiser holyburgers = {
    "Holy Burgers", 1750, holyburgers_messages, 3, 0
};

#endif