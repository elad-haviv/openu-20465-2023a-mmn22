#include <stdio.h>
#include <stdlib.h>
#include "execute.h"
#include "set.h"
#include "parse.h"

void execute(command *cmd) {
    if (cmd->error) {
        print_error(cmd);
        return;
    }

    switch (cmd->operation) {
        case OP_READ:
            return exec_read(cmd);
            break;
        case OP_PRINT:
            exec_print(cmd);
            break;
        case OP_STOP:
            exec_stop(cmd);
            break;
        case OP_UNION:
        case OP_INTERSECT:
        case OP_SUB:
        case OP_SYMDIFF:
            exec_set_op(cmd);
            break;
        case OP_UNDEFINED:
        default:
            cmd->error = E_UNDEFINED_OP;
            print_error(cmd);
            break;
    }

    if (cmd->error) {
        print_error(cmd);
        return;
    }
}

void exec_read(command *cmd) {
    read_set(cmd->sets[0], cmd->numbers);
}

void exec_print(command *cmd) {
    print_set(cmd->sets[0]);
}

void exec_set_op(command *cmd) {
    void (*op)(set, set, set);
    switch (cmd->operation) {
        case OP_UNION:
            op = &union_set;
            break;
        case OP_INTERSECT:
            op = &intersect_set;
            break;
        case OP_SUB:
            op = &sub_set;
            break;
        case OP_SYMDIFF:
            op = &symdiff_set;
            break;
        default:
            print_error(cmd);
    }

    (*op)(cmd->sets[0], cmd->sets[1], cmd->sets[2]);
}

void exec_stop(command *cmd) {
    printf("Program has finished.");
    exit(0);
}

void print_error(command *cmd) {
    char *err;

    char *errors[] = {
            "Undefined operation",
            "Undefined set",
            "Invalid number given (must be between 0-127)",
            "Missing parameters in command",
            "Too many parameters given",
            "Expected stop at the end of input",
            "Expected comma between parameters",
            "Unexpected comma",
            "Expected det as parameter",
            "Unexpected set",
            "Expected number as parameter",
            "Unexpected number",
            "Expected -1 as last parameter",
            "Unexpected -1 as a parameter"
    };

    fprintf(stderr, "Error: %s.\n", errors[cmd->error]);
}