#include <string.h>
#include <iostream>
#include "database.h"

static void skip_whitespaces(string &s)
{
    size_t n = 0;

    while (s[n] == ' '  || s[n] == '\t' || s[n] == '\n')
        n++;

    s.erase(0, n);
}

static void next_token(string &s, string &token)
{
    size_t n;
    skip_whitespaces(s);

    n = s.find_first_of(" \t\n");
    token = s.substr(0, n);
    s.erase(0, n);
}

static void get_command(string &cmdline, string &command)
{
    string token;

    next_token(cmdline, token);

    if (token == "exit") {
        command = token;
    } else if (token == "create" || token == "drop" || token == "display") {
        command = token;

        next_token(cmdline, token);
        command += " " + token;
    } else {
        command = "";
    }
}

int Database::parse(string &cmdline)
{
    string cmd;

    get_command(cmdline, cmd);

    if (cmd == "exit") {
        return 1;
    } else if (cmd == "create table") {
        string name;

        next_token(cmdline, name);
        if (name.length() == 0) {
            cout << "Provide a name for the table" << endl;
            return 0;
        }

        cout << "CREATE TABLE " << name << endl;

    //     tables[cmdline] = new Table(token);
    } else if (cmd == "drop table") {

        std::cout << "DROP TABLE" << std::endl;
    } else if (cmd == "display table") {

        std::cout << "DISPLAY TABLE" << std::endl;
    } else {

        std::cout << "Unknown comman" << std::endl;
    }

    return 0;
}
