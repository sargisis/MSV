#ifndef __TYPECONTROLLER__
#define __TYPECONTROLLER__
#include "../../Includes/Liabrary.h"
#include "../Types/Array/Array.h"
#include "../Types/Bool/Bool.h"
#include "../Types/Double/Double.h"
#include "../Types/Int/Int.h"
#include "../Types/String/String.h"
#include "../../Table/Table.h"

class TypeController
{
private:
    std::string type;
    std::string name;
    std::string code;
public:
    TypeController(std::vector<std::string>& vec, Table& table);
    void resolveDeclaration(std::vector<std::string>& vec, Table& table);
    void createType(Table& table);
    ~TypeController();
};




#endif //__TYPECONTROLLER__