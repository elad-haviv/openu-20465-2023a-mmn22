#ifndef MAMAN_22_SET_HELPERS_H
#define MAMAN_22_SET_HELPERS_H

#include "set.h"

typedef enum {
    FALSE = 0,
    TRUE = 1
} bool;

/* determines the specific byte in a bit-field in which 'number' is represented */
unsigned int byte_pos(int number);

/* determines the specific bit within the bit-field that represents the 'number' */
unsigned int bit_pos(int number);

/* returns the number represented by the given bit in the given byte */
int map_number(unsigned int byte_pos, unsigned int bit_pos);

/* tells whether the given number is a member of the given set. */
bool in_set(set haystack, int needle);

/* inserts a number to a set. */
void insert_member(set target, int number);

/* removes a number from a set. */
void clear_member(set target, int number);

/* inserts a number to a set, i
 * f it's already there - the function removes it. */
void toggle_member(set target, int number);

/* returns the empty set */
set *empty_set();

#endif //MAMAN_22_SET_HELPERS_H
