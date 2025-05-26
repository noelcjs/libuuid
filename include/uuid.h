#ifndef _UUID_H_
#define _UUID_H_

struct uuid_t {
    unsigned char data[16];
};

void UUID_init();
void UUID_generate_uuid(struct uuid_t *uuid);
const char *UUID_uuid_to_str(struct uuid_t *uuid);
void UUID_str_to_uuid(const char *uuid_str, struct uuid_t *dest);
int UUID_equ(struct uuid_t *first, struct uuid_t *second);

#endif