#ifndef ADVERTISER_H_
#define ADVERTISER_H_

enum DisplayType {
    PLAIN,
    BLINK
};

struct Message {
    const char* text;
    DisplayType type;
};

struct Advertiser {
    const char* name;
    unsigned int paid;
    const Message* messages;
    unsigned char message_count;
    unsigned char current_index;
};

#endif