#ifndef PIEPEOPLE_H_
#define PIEPEOPLE_H_

#include "Advertiser.h"

// Messages for Pie People
static const Message piepeople_messages[] = {
    {"Making people float", BLINK},
    {"They are hot and jammy", PLAIN}
};

// Advertiser struct for Pie People
static Advertiser piepeople = {
    "Pie People", 2500, piepeople_messages, 2, 0
};

#endif