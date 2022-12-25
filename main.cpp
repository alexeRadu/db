#include <iostream>
#include <string>
#include "database.h"

using namespace std;

int main(int argc, char *argv[])
{
    Database db;
    std::string cmdline;
    int exit = 0;

    while (!exit) {
        cout << "> ";
        getline(cin, cmdline);

        exit = db.parse(cmdline);
    }

    return 0;
}
