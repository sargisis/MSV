#ifndef __SYNTAX__
#define __SYNTAX__
#include "../Includes/Liabrary.h"
#include "../Keywords/Keyword.h"
#include "../Table/Table.h"
#include "../Statments/If_Else_/If_Else.h"

class Syntax
{   
    std::string sym = "QWERTYUIOPASDFGHJKLZXCVBNM_qwertyuiopasdfghjklzxcvbnm{}";
    std::string digits = "0123456789";
    std::vector<std::string> IF_stack{};
public:
    Syntax(std::ifstream& write_obj, Table& table, If_Else& if_else_table);
    void run(std::ifstream& src, Table& table, If_Else& if_else_table); 
    void Syntax_analysis(std::vector<std::string>& vec);
    void add_space(std::string & line);
    std::vector<std::string> Tokenizing(std::string& line);
    void Resolve_expression(std::vector<std::string>& vec, Table& table);
    std::string Eval(std::string unresolved_val, Table& table);
    std::string if_else_Eval(std::string unresolved_val,If_Else& if_else_table, Table& table); //resolve argument
    void resolve_if_expr(std::vector<std::string>& vec, Table& table);
    void resolve_if_body_variable(std::vector<std::string>& vec, Table& table, If_Else& if_else_table);

    ~Syntax();
};




#endif // __SYNTAX__