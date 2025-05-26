#include "uuid.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void UUID_init(){
    srand((unsigned int) time(NULL));
}

void UUID_generate_uuid(struct uuid_t *uuid) {

    // Generate 16 random bytes
    for (int i = 0; i < 16; i++) {
        uuid->data[i] = rand() % 256;
    }

    // Set the version to 4 (Random UUID) in the 7th byte (i.e., the first byte of the 2nd half of the UUID)
    uuid->data[6] &= 0x0F; // Clear the high nibble of the 7th byte (0x40)
    uuid->data[6] |= 0x40;  // Set the version field to 4 (0x40)

    // Set the variant (most significant 2 bits of the 9th byte) to 10 (0x80) for UUID variant 1
    uuid->data[8] &= 0x3F; // Clear the high nibble of the 9th byte (0x80)
    uuid->data[8] |= 0x80;  // Set the variant field to 10 (0x80)
}

const char *UUID_uuid_to_str(struct uuid_t *uuid) {
    // Print UUID in standard format
    static char uuid_str[37]; // UUID is always 36 characters + 1 for null-terminator

    // Format the UUID into the string
    snprintf(uuid_str, sizeof(uuid_str), "%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x",
             uuid->data[0], uuid->data[1], uuid->data[2], uuid->data[3],
             uuid->data[4], uuid->data[5], uuid->data[6], uuid->data[7],
             uuid->data[8], uuid->data[9], uuid->data[10], uuid->data[11],
             uuid->data[12], uuid->data[13], uuid->data[14], uuid->data[15]);

    return uuid_str;
}

void UUID_str_to_uuid(const char *uuid_str, struct uuid_t *dest){
    const char *p = uuid_str;
    for (int byte = 0; byte < 16; byte++) {
        while (*p == '-') p++; // Skip dashes

        char buf[3] = {0};
        buf[0] = *p++;
        buf[1] = *p++;

        dest->data[byte] = (unsigned char) strtol(buf, 0, 16);
    }
}