#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse.h"

void cmd_log(command cmd) {
    printf("{\n    string: %s    opcode: %d\n    error: %d\n}\n", cmd.string, cmd.operation, cmd.error);
}

/* parses a string into a command */
command parse(char *str, NamedSet collection[]) {
    command cmd;
    cmd.string = malloc(strlen(str));
    strcpy(cmd.string, str);



    return cmd;
}

error parse_read(char *str, NamedSet collection[]) {

}

error parse_print(char *str, NamedSet collection[]) {

}

error parse_union(char *str, NamedSet collection[]) {

}

error parse_intersect(char *str, NamedSet collection[]) {

}

error parse_sub(char *str, NamedSet collection[]) {

}

error parse_symdiff(char *str, NamedSet collection[]) {

}

error parse_stop(char *str, NamedSet collection[]) {

}

/* parses a single token */
token parse_token(char *str);

/* tokenize a string, returns one token at a time */
token **tokenize(char *str) {

}