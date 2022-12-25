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

static void str_toupper(string &s)
{
    size_t n = 0;

    while (s[n]) {
        s[n] = toupper(s[n]);
        n++;
    }
}

int Database::parse(string &cmdline)
{
    string token;

    next_token(cmdline, token);

    if (token == "exit") {
        return 1;
    } else if (token == "create") {
        next_token(cmdline, token);

        if (token != "table") {
            str_toupper(token);
            cout << "Unknown command 'CREATE " << token << "'" << endl;
            return 0;
        }

        next_token(cmdline, token);
        if (token.length() == 0) {
            cout << "Provide a name for the table" << endl;
            return 0;
        }

        cout << "CREATE TABLE " << token << endl;

    //     tables[cmdline] = new Table(token);
    } else if (token == "drop") {
        std::cout << "DROP TABLE" << std::endl;
    } else if (token == "display table") {
        std::cout << "DISPLAY TABLE" << std::endl;
    } else {
        std::cout << "Unknown comman" << std::endl;
    }

    return 0;
}
