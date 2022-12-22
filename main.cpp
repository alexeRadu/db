#include <iostream>
#include "database.h"

#define MAX_CMD_LINE    100

int main(int argc, char *argv[])
{
    Database db;
    char cmdline[MAX_CMD_LINE];
    int exit = 0;

    while (!exit) {
        std::cout << "> ";
        std::cin >> cmdline;

        exit = db.parse(cmdline);
    }

    return 0;
}
