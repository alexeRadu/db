#ifndef COLUMN_H
#define COLUMN_H

#include <vector>
#include <string>

using namespace std;

class ColumnGeneric {
public:
    ColumnGeneric(string &name, string &type) : name(name), type(type) {};

    string& get_name() { return name; }
    string& get_type() { return type; }

    void display();

private:
    string name;
    string type;
};

template <typename T> class Column : public ColumnGeneric {
public:
    Column(string &name, string &type) : ColumnGeneric(name, type) {};
    ~Column();

private:
    vector<T> values;
};

#endif /* COLUMN_H */
