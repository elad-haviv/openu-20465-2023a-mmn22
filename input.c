#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "input.h"

void print_instructions() {
    printf("Set Calculator: \n");
}

char *ask_for_line() {
    printf("$>");

    char c;
    char *line = NULL;
    size_t len = 0;

    do {
        c = (char)getchar();

        /* store the input in 'c' in the command line */
        line = realloc(line, len+2);
        line[len] = c;
        line[++len] = '\0';

        if (c == '\n') break;
    } while (c != EOF && c != '\n');

    return line;
}