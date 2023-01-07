#include <stdio.h>
#include "set_helpers.h"

#include "set.h"

void read_set(set target, byte members[]) {
    int i;
    target = *empty_set();

    for (i = 0; members[i] != 255; ++i) {
        insert_member(target, members[i]);
    }
}

/* TODO: this function should not actually print the set. */
char *print_set(set target) {
    int i, count;

    for (i = 0, count = 0; i < SET_WIDTH; ++i) {
        if (!in_set(target, i)) {
            continue;
        }

        printf("%d%c", i, (count++ % 16) == 15 ? '\n' : ' ');
    }

    if (!count) {
        printf("This set is empty.");
    }

    printf("\n");

    return "";
}

void union_set(set a, set b, set target) {
    int i;
    for (i = 0; i < SET_FIELDS; i++) {
        target[i] = a[i] | b[i];
    }
}

void intersect_set(set a, set b, set target) {
    int i;
    for (i = 0; i < SET_FIELDS; i++) {
        target[i] = a[i] & b[i];
    }
}

void sub_set(set a, set b, set target) {
    int i;
    for (i = 0; i < SET_FIELDS; i++) {
        target[i] = a[i] & ~(a[i] & b[i]);
    }
}

void symdiff_set(set a, set b, set target) {
    int i;
    for (i = 0; i < SET_FIELDS; i++) {
        target[i] = (a[i] | b[i]) & ~(a[i] & b[i]);
    }
}