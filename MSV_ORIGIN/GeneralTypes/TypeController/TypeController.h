#ifndef __TYPECONTROLLER__
#define __TYPECONTROLLER__
#include "../../Includes/Liabrary.h"
#include "../../Table/Table.h"
#include "../../Statments/If_Else_/If_Else.h"
#include "../../Statments/Loops/While.h"


class TypeController
{
private:
    std::string name;
    std::string code;
    std::string type;
    std::string digits = "0123456789";
    std::string symStr = "\"";
    std::string sym = "QWERTYUIOPASDFGHJKLZXCVBNM_qwertyuiopasdfghjklzxcvbnm";
public:
    TypeController(std::vector<std::string>& vec, Table& table);
    TypeController(std::vector<std::string>& vec, If_Else& if_else_table, Table& table);
    TypeController(Table& table, std::vector<std::string>& w_line, While& while_table);
    void resolveDeclaration(std::vector<std::string>& vec, Table& table);
    void resolve_if_Declaration(std::vector<std::string>& vec, If_Else& if_else_table, Table& table);
    void resolve_while_Declaration(Table& table, std::vector<std::string>& w_line, While& while_table);
    ~TypeController();
};




#endif //__TYPECONTROLLER__