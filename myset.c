#include <stdio.h>
#include "set.h"
#include "input.h"
#include "parse.h"
#include "execute.h"

int main() {
    set SETA = {0},
        SETB = {0},
        SETC = {0},
        SETD = {0},
        SETE = {0},
        SETF = {0};

    NamedSet collection[6] = {
        { "SETA", &SETA },
        { "SETB", &SETB },
        { "SETC", &SETC },
        { "SETD", &SETD },
        { "SETE", &SETE },
        { "SETF", &SETF }
    };

    print_instructions();

    char *line = NULL;
    command cmd;

    while((line = ask_for_line()) != NULL) {
        cmd = parse(line, collection);
        cmd_log(cmd);
    }

    return 0;
}