#ifndef MAMAN_22_SET_H
#define MAMAN_22_SET_H

#include <limits.h>

/* The required number of possible set members. */
#define SET_WIDTH 128

/* The number of bytes needed to store a single set */
#define SET_FIELDS SET_WIDTH/CHAR_BIT

/* byte definition,
 * unsigned with the same amount of memory as a char.
 * for easier coding. */
typedef unsigned char byte;

/* Set definition,
 * as a field of bytes. */
typedef byte set[SET_FIELDS];

/* Takes a set and populates it with members */
void read_set(set target, byte members[]);

/* return a string to nicely print the set.
   this function is required not to actually print according to maman instructions. */
char *print_set(set target);

/* performs union of sets a and b, puts it in the target set */
void union_set(set a, set b, set target);

/* performs intersection of sets a and b, puts it in the target set */
void intersect_set(set a, set b, set target);

/* performs subtraction of set b from set a, puts it in the target set */
void sub_set(set a, set b, set target);

/* performs symmetric difference of sets a and b, puts it in the target set */
void symdiff_set(set a, set b, set target);

#endif //MAMAN_22_SET_H
