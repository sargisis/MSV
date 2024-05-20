#include "GTable.h"

void Table::setTable(std::vector<std::string> tmp, VarInfo ob)
{   
        ob.name = tmp[0];
        ob.value = tmp[2];
        ob.type = "int";
    

    table.push_back(ob);
}


void Table::resolveDeclaration(std::vector<std::string>& vec)
{   
    VarInfo ob;
    std::string digits = "0123456789";
    std::string symStr = "\"";
    std::string symDot = ".";
    std::string sym = "QWERTYUIOPASDFGHJKLZXCVBNM_qwertyuiopasdfghjklzxcvbnm";

    if (digits.find(vec[2].front()) != std::string::npos && vec[2].find(".") != std::string::npos) { // Check if the character is found in the digits string
        ob.value = vec[2];
        ob.type = "Double";
        ob.name = vec[0];
        setTable(ob);
    }
    else if(digits.find(vec[2].front()) != std::string::npos && symDot.find(vec[2]) == std::string::npos) {
        ob.value = vec[2];
        ob.type = "Int";
        ob.name = vec[0];
    }
    else if(vec[2] == "true" || vec[2] == "false") {
        
        value = vec[2];
        type = "Bool";
        name = vec[0];
    }
    else if(symStr.find(vec[2].front() != std::string::npos)) {
        value = vec[2];
        type = "String";
        name = vec[0];
    }
    else if(vec[0].find("[") != std::string::npos) {
        type = "Array";
        int i = 0;
        while (vec[0][i] != '[') {
            name +=  vec[0][i];
            ++i;
        }
        
    }
    
}
