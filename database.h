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
