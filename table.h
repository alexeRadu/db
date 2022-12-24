#include <string>

using namespace std;

class Table {
public:
    Table(char *name) : name(name) {};
    ~Table() {};

private:
    string name;
};
