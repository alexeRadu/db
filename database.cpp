#include <iostream>
#include <string>
#include <vector>

#include "database.h"

static void skip_whitespaces(string &s)
{
    size_t n = 0;

    while (s[n] == ' '  || s[n] == '\t' || s[n] == '\n') {
        n++;
    }

    s.erase(0, n);
}

static void next_token(string &cmdline, string &token, const char *sep)
{
    size_t n;
    skip_whitespaces(cmdline);

    n = cmdline.find_first_of(sep);
    token = cmdline.substr(0, n);
    cmdline.erase(0, n);
}

static void next_arg(string &cmdline, string &arg)
{
}

static void get_command(string &cmdline, string &command)
{
    string token;

    next_token(cmdline, token, " \t\n");

    if (token == "exit") {
        command = token;
    } else if (token == "create" || token == "drop" || token == "display") {
        command = token;

        next_token(cmdline, token, " \t\n");
        command += " " + token;
    } else {
        command = "";
    }
}

static int get_arglist(string &cmdline, string &arglist)
{
    size_t n;
    int contexts = 0;

    skip_whitespaces(cmdline);

    if (cmdline[0] != '(') {
        cout << "Argument List not found" << endl;
        return 1;
    }

    cmdline.erase(0, 1);

    while (cmdline[n] != ')' || contexts > 0) {
        if (cmdline[n] == '(') {
            contexts++;
        } else if (cmdline[n] == ')') {
            contexts--;
        }

        n++;
    }

    if (cmdline[n] != ')') {
        cout << "Argument List not properly finished" << endl;
        return 1;
    }

    arglist = cmdline.substr(0, n);
    cmdline.erase(0, n);

    return 0;
}

static int parse_arglist(string &arglist, vector<tuple<string, string>> &args)
{
    string var, type;

    skip_whitespaces(arglist);

    while (arglist.length() > 0) {
        next_token(arglist, var, " \t\n");
        skip_whitespaces(arglist);

        next_token(arglist, type, ",");
        arglist.erase(0, 1);

        // validating types
        if (type != "int" && type != "string") {
            cout << "Type: " << type << " not recognized as a valid type" << endl;
            return 1;
        }

        args.push_back(make_tuple(var, type));
    }

    return 0;
}

int Database::parse(string &cmdline)
{
    string cmd;

    get_command(cmdline, cmd);

    if (cmd == "exit") {
        return 1;
    } else if (cmd == "create table") {
        string name;
        string arglist;
        vector<tuple<string, string>> args;

        next_token(cmdline, name, " \t\n(");
        if (name.length() == 0) {
            cout << "Provide a name for the table" << endl;
            return 0;
        }

        if (get_arglist(cmdline, arglist))
            return 0;

        if (parse_arglist(arglist, args))
            return 0;

        tables[name] = new Table(name, args);

        cout << "Table '" << name << "' created" << endl;
    } else if (cmd == "drop table") {

        std::cout << "DROP TABLE" << std::endl;
    } else if (cmd == "display table") {
        string name;
        Table *table;
        bool found = false;

        if (tables.size() == 0) {
            cout << "No tables available" << endl;
            return 0;
        }

        next_token(cmdline, name, " \t\n");
        if (name.length() == 0) {
            cout << "Please provide table name" << endl;
            return 0;
        }

        for (auto & [tname, tbl] : tables) {
            if (tname == name) {
                table = tbl;
                found = true;
                break;
            }
        }

        if (not found) {
            cout << "No table with the name '" << name << "' found" << endl;
            return 0;
        }

        table->display();

    } else {

        std::cout << "Unknown comman" << std::endl;
    }

    return 0;
}
