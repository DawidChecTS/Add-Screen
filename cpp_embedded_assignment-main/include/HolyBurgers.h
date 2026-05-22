#ifndef HOLYBURGERS_H_
#define HOLYBURGERS_H_

#include "Advertiser.h"

static const Message holyburgers_messages[] = {
    {"Free drinks included in menu", PLAIN},
    {"Burgermania! 2 for 59 SEK", BLINK},
    {"Badabim... Bada BURGER!", BLINK}
};

static Advertiser holyburgers = {
    "Holy Burgers", 1750, holyburgers_messages, 3, 0
};

#endif