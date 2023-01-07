#include <stdlib.h>
#include "set_helpers.h"

unsigned int byte_pos(int number) {
    return number / CHAR_BIT;
}
unsigned int bit_pos(int number) {
    return number % CHAR_BIT;
}

int map_number(unsigned int byte_pos, unsigned int bit_pos) {
    return bit_pos + byte_pos * CHAR_BIT;
}

bool in_set(set haystack, int needle) {
    byte b = haystack[byte_pos(needle)];

    /* compare the relevant bit against it's place in the bit-field. */
    return b & (1 << bit_pos(needle));
}

void insert_member(set target, int number) {
    byte *b = &target[byte_pos(number)];
    /* Set the number's bit in the set to 1 */
    *b = *b | (1 << bit_pos(number));
}

void clear_member(set target, int number) {
    byte *b = &target[byte_pos(number)];
    /* Set the number's bit in the set to 0 */
    *b = *b & ~(1 << bit_pos(number));
}

void toggle_member(set target, int number) {
    byte *b = &target[byte_pos(number)];
    *b = *b ^ (1 << bit_pos(number));
}

set *empty_set() {
    /* Allocates memory and sets it to 0's */
    set *s = calloc(1, sizeof(set));
    return s;
}

/*
set *empty_set(set target) {
    byte i;
    for (i = 0; i < SET_FIELDS; i++) {
        target[i] = 0;
    }
}*/
