#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector>
#include <tuple>
#include "column.h"

using namespace std;

class Table {
public:
    Table(string &name, vector<tuple<string, string>> &args);
    ~Table() {};

    void display();

private:
    string name;
    vector<ColumnGeneric *> columns;
};

#endif /* TABLE_H */
