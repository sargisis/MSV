#include "TypeController.h"

TypeController::TypeController(std::vector<std::string>& vec, Table& table)
{
    
    resolveDeclaration(vec, table);
}

void TypeController::resolveDeclaration(std::vector<std::string>& vec, Table& table)
{   
    std::string digits = "0123456789";
    std::string symStr = "\"";
    std::string symDot = ".";
    std::string sym = "QWERTYUIOPASDFGHJKLZXCVBNM_qwertyuiopasdfghjklzxcvbnm";

    if (digits.find(vec[2].front()) != std::string::npos && vec[2].find(".") != std::string::npos) { // Check if the character is found in the digits string
        code = vec[2];
        type = "Double";
        name = vec[0];
        createType(table);
    }
    else if(digits.find(vec[2].front()) != std::string::npos && symDot.find(vec[2]) == std::string::npos) {
        code = vec[2];
        type = "Int";
        name = vec[0];
        createType(table);
    }
    else if(vec[2] == "true" || vec[2] == "false") {
        
        code = vec[2];
        type = "Bool";
        name = vec[0];
        createType(table);
    }
    else if(symStr.find(vec[2].front() != std::string::npos)) {
        code = vec[2];
        type = "String";
        name = vec[0];
        createType(table);
    }
    else if(vec[0].find("[") != std::string::npos) {
        //code = vec[1];
        type = "Array";
        int i = 0;
        while (vec[0][i] != '[') {
            name +=  vec[0][i];
            ++i;
        }
        createType(table);
        
    }
    
}

void TypeController::createType(Table& table)
{
    if (type == "Int") {
     Int* ob = new Int (std::string(name), std::string(code), std::string(type));
     table.SetIntPointer(ob);
    } else if (type == "Bool") {
     Bool* ob1 = new Bool (std::string(name), std::string(code), std::string(type));
     table.SetBoolPointer(ob1);
        Bool (std::string(name), std::string(code), std::string(type));
    } else if (type == "Double") {
        Double* ob2 = new Double (std::string(name), std::string(code), std::string(type));
     table.SetDoublePointer(ob2);
        Double (std::string(name), std::string(code), std::string(type));
    } else if (type == "String") {
        String* ob3 = new String (std::string(name), std::string(code), std::string(type));
     table.SetStringPointer(ob3);
        String (std::string(name), std::string(code), std::string(type));
    } else if (type == "Array") {
        Array* ob4 = new Array ();
     table.SetArrayPointer(ob4);
        Array();
    }
}

TypeController::~TypeController()
{}