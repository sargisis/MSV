#ifndef __SYNTAX__
#define __SYNTAX__
#include "../Includes/Liabrary.h"
#include "../Keywords/Keyword.h"
#include "../Table/Table.h"

class Syntax
{
public:
    Syntax(std::ifstream& write_obj, Table& table);
    void run(std::ifstream& src, Table& table); 
    //void Tokenizing(std::string& line); 
    void Syntax_analysis(std::string& line, std::vector<std::string>& vec);
    void add_space(std::string & line);
    std::vector<std::string> Tokenizing(std::string& line);
    void Semantic_analysis(std::string& line, std::vector<std::string>& vec);
    ~Syntax();
};




#endif // __SYNTAX__