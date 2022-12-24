#include <map>
#include <string>
#include "table.h"

class Database {
public:
    Database() {};
    ~Database() {};

    int parse(char *cmdline);

private:
    std::map<std::string, Table *> tables;
};
