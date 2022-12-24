#include <iostream>
#include <string>
#include "database.h"

int main(int argc, char *argv[])
{
    Database db;
    std::string cmdline;
    int exit = 0;

    while (!exit) {
        std::cout << "> ";
        std::getline(std::cin, cmdline);

        exit = db.parse((char *)cmdline.c_str());
    }

    return 0;
}
