#include <iostream>
#include "table.h"
#include "column.h"

Table::Table(string &name, vector<tuple<string, string>> &args)
{
    this->name = name;

    for (auto var : args) {
        string varname = get<0>(var);
        string vartype = get<1>(var);

        if (vartype == "int") {
            columns.push_back(new Column<int>(varname, vartype));
        } else if (vartype == "string") {
            columns.push_back(new Column<string>(varname, vartype));
        }

        // for (auto col : columns) {
        //     cout << col->get_name() << ": " << col->get_type() << endl;
        // }
    }
}

void Table::display()
{
    cout << "---------------------------------" << endl;
    cout << "Table: " << name << endl;
    cout << "---------------------------------" << endl;
    for (auto col : columns) {
        col->display();
    }
    cout << "---------------------------------" << endl;
}
