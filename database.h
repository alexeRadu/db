#include <map>
#include <string>
#include "table.h"

class Database {
public:
    Database() {};
    ~Database() {};

    int parse(const char *cmdline);

private:
    int create_table(const char *cmdline);

    std::map<std::string, Table *> tables;
};
