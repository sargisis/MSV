#include "Table.h"
#include "../KeywordCheck/keyword_checking.h"


void Table::setName(std::string name , std::string val) {
    std::pair<std::string, std::string> tmp;

    // valid variable name start
    std::string sym = "QWERTYUIOPASDFGHJKLZXCVBNM_qwertyuiopasdfghjklzxcvbnm";
    std::string digits = "0123456789";

    // label to know if code execution get into 
    // some loop or if statement -> ( 0=false, 1=true )
    //int check = 1;  // default false;

    // if variable name don't start ['_', a-z, A-Z] throw runtime_error
    if (sym.find(name[0]) == std::string::npos)
    {
        std::cerr << "Identifier error:" << std::endl
        << "Identifer name must start ['_', 'a-z', 'A-Z']." << std::endl;
        throw std::runtime_error("");
    }

    // if val is as variable get value of that variable
    // if not as variable, stay as it is
    for (int i = 0; i < name_val.size(); ++i)
    {   
        if ( name_val[i].first == val )
        {
            // check = 1;
            val = name_val[i].second;
            break;
        }
    }

    // Checking if value is as variable,
    // are there any matching variable in our table
    if ( sym.find(val[0]) != std::string::npos )
    {
        std::cerr << "Undefined variable." << std::endl
        << "There is not declared variable \"" << val << "\"." << std::endl;
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < name_val.size(); ++i)
    {   
        if (name == name_val[i].first)
        {
            name_val[i].second = val;
            return;
        }
    }

    tmp.first = name;
    tmp.second = val; 
    name_val.push_back(tmp);  
}

void Table::setId(std::size_t id) {
    this->id.push_back(id);
}

size_t Table::size() {
    return name_val.size();
}