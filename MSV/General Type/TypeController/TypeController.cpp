#include "./TypeController.h"
// #include "../../GeneralTypes/Types/Int/Int.h"
// #include "../../GeneralTypes/Types/Char/Char.h"
// #include "../../GeneralTypes/Types/Bool/Bool.h"
// #include "../../GeneralTypes/Types/Double/Double.h"
// #include "../../GeneralTypes/Types/Float/Float.h"
// #include "../../GeneralTypes/Types/Short/Short.h"

TypeController::TypeController(const std::string type, const std::string codeLine)
{
    createType(type, codeLine);
}

void TypeController::createType(const std::string type, const std::string code)
{
    if (type == "int") {
        Int(std::string(code));
    } else if (type == "char") {
        Char(std::string(code));
    } else if (type == "bool") {
        Bool(std::string(code));
    } else if (type == "double") {
        Double(std::string(code));
    } 
}
