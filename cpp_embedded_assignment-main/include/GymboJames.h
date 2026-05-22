#ifndef GYMBOJAMES_H_
#define GYMBOJAMES_H_

#include "Advertiser.h"

// Messages for Gymbo James
static const Message gymbojames_messages[] = {
    {"No more excuses! Only GAINS!", BLINK},
    {"Pro Gymbono - 14 days free", PLAIN}
};
// Advertiser struct for Gymbo James
static Advertiser gymbojames = {
    "Gymbo James", 6700, gymbojames_messages, 2, 0
};

#endif