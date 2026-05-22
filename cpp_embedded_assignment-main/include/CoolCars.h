#ifndef COOLCARS_H_
#define COOLCARS_H_

#include "Advertiser.h"
// Messages for CoolCars
static const Message coolcars_messages[] = {
    {"Drive me crazy!", PLAIN},
    {"30-day moneyback guarantee", PLAIN}
};
// Advertiser struct for CoolCars
static Advertiser coolcars = {
    "CoolCars LLC", 5000, coolcars_messages, 2, 0
};

#endif