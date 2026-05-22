#ifndef WASHOMANIA_H_
#define WASHOMANIA_H_

#include "Advertiser.h"

static const Message washomania_messages[] = {
    {"Clean customers happy customers!", BLINK}
};

static Advertiser washomania = {
    "Washomania", 4900, washomania_messages, 1, 0
};

#endif