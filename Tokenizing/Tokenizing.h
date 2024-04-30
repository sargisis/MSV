#ifndef __TOKEN__
#define __TOKEN__

#include "Liabrary.h"
#include "Table.h"

class Tokenizing {
public: 
    Tokenizing(std::ifstream& ob, Table& tbl);
    void add_space(std::string & line);
    std::vector<std::string> tokenizing(std::string line);
    void run(std::ifstream& src, Table& tbl);

};

#endif // TOKEN