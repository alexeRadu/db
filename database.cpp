#include <string.h>
#include <iostream>
#include "database.h"

int Database::parse(const char *cmdline)
{
    if (!strcmp(cmdline, "exit")) {
        return 1;
    } else if (!strcmp(cmdline, "create table")) {
        tables[cmdline] = new Table();
    } else if (!strcmp(cmdline, "drop table")) {
    } else if (!strcmp(cmdline, "display table")) {
    }

    return 0;
}
