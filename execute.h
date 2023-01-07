#ifndef MAMAN_22_EXECUTE_H
#define MAMAN_22_EXECUTE_H

#include "parse.h"

/* executes a command. */
void execute(command *cmd);

/* reads a set */
void exec_read(command *cmd);

/* prints a set */
void exec_print(command *cmd);

/* perform set operation (union, intersect, ...) */
void exec_set_op(command *cmd);

/* stops the program */
void exec_stop(command *cmd);

/* prints an error */
void print_error(command *cmd);

#endif //MAMAN_22_EXECUTE_H
