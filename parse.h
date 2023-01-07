#ifndef MAMAN_22_CMD_PARSER_H
#define MAMAN_22_CMD_PARSER_H

#include "set.h"

/* List of every possible opcode. */
typedef enum {
    OP_UNDEFINED = 0,
    OP_PRINT,
    OP_READ,
    OP_UNION,
    OP_INTERSECT,
    OP_SUB,
    OP_SYMDIFF,
    OP_STOP
} opcode;

typedef enum {
    E_NO_ERROR = -1,
    E_UNDEFINED_OP = 0,
    E_UNDEFINED_SET,
    E_INVALID_NUMBER,
    E_MISSING_PARAMS,
    E_TOO_MANY_PARAMS,
    E_EXPECTED_STOP,
    E_EXPECTED_COMMA,
    E_UNEXPECTED_COMMA,
    E_EXPECTED_SET,
    E_UNEXPECTED_SET,
    E_EXPECTED_NUMBER,
    E_UNEXPECTED_NUMBER,
    E_EXPECTED_MINUSONE,
    E_UNEXPECTED_MINUSONE
} error;

/* command struct for execution. */
typedef struct {
    char *string;
    opcode operation;
    error error;
    set sets[3];
    byte numbers[];
} command;

/* List of every possible token type the user can enter. */
typedef enum {
    T_INVALID = 0,
    T_OPERATION,
    T_SET,
    T_NUMBER,
    T_LIST_END,
    T_COMMA,
    T_NEWLINE,
    T_BLANK,
    T_EOF
} token_type;

/* the token has a type and content. */
typedef struct token {
    token_type type;
    char *content;
    struct token *next;
    struct token *prev;
} token;

typedef struct token token;

/* Define a set to be found by corresponding name */
typedef struct {
    char *name;
    set *set;
} NamedSet;

/* parses a string into a command */
command parse(char *str, NamedSet collection[]);

error parse_read(char *str, NamedSet collection[]);

error parse_print(char *str, NamedSet collection[]);

error parse_union(char *str, NamedSet collection[]);

error parse_intersect(char *str, NamedSet collection[]);

error parse_sub(char *str, NamedSet collection[]);

error parse_symdiff(char *str, NamedSet collection[]);

error parse_stop(char *str, NamedSet collection[]);

/* parses a single token */
token parse_token(char *str);

/* tokenize a string, returns one token at a time */
token tokenize(char *str);

void cmd_log(command cmd);

#endif //MAMAN_22_CMD_PARSER_H
