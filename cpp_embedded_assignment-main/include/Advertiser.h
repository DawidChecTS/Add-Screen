#ifndef ADVERTISER_H_
#define ADVERTISER_H_

// Advertiser struct definition
enum DisplayType {
    PLAIN,
    BLINK
};
// Message struct definition
struct Message {
    const char* text;
    DisplayType type;
};
// Advertiser struct definition
struct Advertiser {
    const char* name;
    unsigned int paid;
    const Message* messages;
    unsigned char message_count;
    unsigned char current_index;
};

#endif