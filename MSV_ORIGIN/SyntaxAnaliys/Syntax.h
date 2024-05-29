#ifndef __SYNTAX__
#define __SYNTAX__
#include "../Includes/Liabrary.h"
#include "../Keywords/Keyword.h"
#include "../Table/Table.h"
#include "../Statments/If_Else_/If_Else.h"
#include "../Statments/Loops/While.h"
#include "../InputOutput/InputOutput.h"


class Syntax
{   
    std::string sym = "QWERTYUIOPASDFGHJKLZXCVBNM_qwertyuiopasdfghjklzxcvbnm{}~";
    std::string digits = "0123456789";
    std::vector<std::string> IF_stack{};
    std::vector<std::vector<std::string>> w_line;//wloop-i toxer@ tokenizing exac qcumenq stex
    
public:
    Syntax(std::ifstream& write_obj, Table& table, If_Else& if_else_table, While& while_table, Input& in, onst Output& out);
    void run(std::ifstream& src, Table& table, If_Else& if_else_table, While& while_table, Input& in,  Output& out); 
    void Syntax_analysis(std::vector<std::string>& vec);
    void add_space(std::string & line);
    std::vector<std::string> Tokenizing(std::string& line);
    void Resolve_expression(std::vector<std::string>& vec, Table& table);
    std::string Eval(std::string unresolved_val, Table& table);
    std::string if_else_Eval(std::string unresolved_val,If_Else& if_else_table, Table& table); //resolve argument
    std::string wloop_Eval(std::string unresolved_val, While& while_table, Table& table);
    void resolve_if_expr(std::vector<std::string>& vec, Table& table);
    void resolve_if_body_variable(std::vector<std::string>& vec, Table& table, If_Else& if_else_table);
    void resolve_wloop_body(Table& table, While& while_table);
    void set_wline(std::vector<std::string> vec);
    bool resolve_wloop_expr(std::vector<std::string> line_0, Table& table);

    ~Syntax();
};




#endif // __SYNTAX__