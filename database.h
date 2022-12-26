#ifndef DATABASE_H
#define DATABASE_H

#include <map>
#include <string>
#include "table.h"

using namespace std;

class Database {
public:
    Database() {};
    ~Database() {};

    int parse(string &cmdline);

private:
    map<string, Table *> tables;
};

#endif /* DATABASE_H */
