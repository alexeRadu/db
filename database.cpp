#include <string.h>
#include <iostream>
#include "database.h"

static char *skip_whitespaces(char *s)
{
    while (*s == ' '  || *s == '\t' || *s == '\n')
        s++;

    return s;
}

static char *next_token(char *s, char *token)
{
    size_t n = 0;

    while (s[n] != '\0' && s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
        n++;

    memcpy(token, s, n);
    token[n] = '\0'; 

    return skip_whitespaces(s + n);
}

static char *str_toupper(char *s)
{
    size_t n = 0;

    while (s[n]) {
        s[n] = toupper(s[n]);
        n++;
    }

    return s;
}

int Database::parse(char *cmdline)
{
    char token[126];

    cmdline = skip_whitespaces(cmdline);
    cmdline = next_token(cmdline, token);

    if (!strcmp(token, "exit")) {
        return 1;
    } else if (!strcmp(token, "create")) {
        cmdline = next_token(cmdline, token);

        if (strcmp(token, "table")) {
            std::cout << "Unknown command 'CREATE " << str_toupper(token) << "'" << std::endl;
            return 0;
        }

        cmdline = next_token(cmdline, token);
        if (strlen(token) == 0) {
            std::cout << "Provide a name for the table" << std::endl;
        }

        std::cout << "CREATE TABLE " << str_toupper(token) << std::endl;

        tables[cmdline] = new Table(token);
    } else if (!strcmp(token, "drop")) {
        std::cout << "DROP TABLE" << std::endl;
    } else if (!strcmp(token, "display table")) {
        std::cout << "DISPLAY TABLE" << std::endl;
    } else {
        std::cout << "Unknown comman" << std::endl;
    }

    return 0;
}
