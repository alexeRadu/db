#include <string.h>
#include <iostream>
#include "database.h"

static char *skip_whitespaces(char *s)
{
    while (*s == ' '  || *s == '\t' || *s == '\n')
        s++;

    return s;
}

static void next_token(char *s, char *token)
{
}

    if (!strcmp(cmdline, "exit")) {
        return 1;
    } else if (!strcmp(cmdline, "create table")) {
        tables[cmdline] = new Table();
    } else if (!strcmp(cmdline, "drop table")) {
    } else if (!strcmp(cmdline, "display table")) {
    }

    return 0;
}
