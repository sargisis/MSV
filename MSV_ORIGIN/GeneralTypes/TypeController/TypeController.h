#ifndef __TYPECONTROLLER__
#define __TYPECONTROLLER__
#include "../../Includes/Liabrary.h"
#include "../../Table/Table.h"
#include "../../Statments/If_Else_/If_Else.h"

class TypeController
{
private:
    std::string name;
    std::string code;
    std::string type;
public:
    TypeController(std::vector<std::string>& vec, Table& table);
    TypeController(std::vector<std::string>& vec, If_Else& if_else_table, Table& table);
    void resolveDeclaration(std::vector<std::string>& vec, Table& table);
    void resolve_if_Declaration(std::vector<std::string>& vec, If_Else& if_else_table, Table& table);
    ~TypeController();
};




#endif //__TYPECONTROLLER__