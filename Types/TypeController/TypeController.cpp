#include "TypeController.h"

TypeController::TypeController(vector<string>& vec, Table& table)
{
    
    resolveDeclaration(vec, table);
}

void TypeController::resolveDeclaration(vector<string>& vec, Table& table)
{   
    std::string digits = "0123456789";
    std::string symStr = "\"";
    std::string symDot = ".";
    std::string sym = "QWERTYUIOPASDFGHJKLZXCVBNM_qwertyuiopasdfghjklzxcvbnm";

    if (digits.find(vec[2].front()) != string::npos && vec[2].find(".") != string::npos) { // Check if the character is found in the digits string
        code = vec[2];
        type = "Double";
        name = vec[0];
        createType(table);
    }
    else if(digits.find(vec[2].front()) != std::string::npos && symDot.find(vec[2]) == string::npos) {
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
    else if(symStr.find(vec[2].front() != string::npos)) {
        code = vec[2];
        type = "String";
        name = vec[0];
        createType(table);
    }
    else if(vec[0].find("[") != string::npos) {
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
   for (size_t i = 0; i < check.size(); ++i) {
        if (check[i].first == "Int") {
            check[i].second = (Int*)&i_int;
            Int();
        }else if (check[i].first == "Double") {
            check[i].second = (Double*)&d_double;
            Double();
        } else if (check[i].first == "String") {
            check[i].second = (String*)&s_string;
            String();
        } else if (check[i].first == "Bool") {
            check[i].second = (Bool*)&b_bool;
            Bool();
        } else if (check[i].first == "Array") {
            check[i].second = (Array*)&a_array;
            Array();
        }
   }
}

