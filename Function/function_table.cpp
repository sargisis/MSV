#include "../Tokenizing/Table.h"
#include "../Tokenizing/Tokenizing.h"
#include "function_table.h"
#include "../KeywordCheck/keyword_checking.h"

// Tokenizing::add_space();

void FTable::setName(std::string name, std::string val)
{
    std::pair<std::string, std::string> tmp;

    // valid variable name start
    std::string sym = "QWERTYUIOPASDFGHJKLZXCVBNM_qwertyuiopasdfghjklzxcvbnm";
    std::string digits = "0123456789";

    // if variable name don't start ['_', a-z, A-Z] throw runtime_error
    if (sym.find(name[0]) == std::string::npos)
    {  
       std::cout << "Identifier error:" << std::endl
       << "Identifer name must start ['_', 'a-z', 'A-Z']." << std::endl;
       throw std::runtime_error("");
    }


   
    int count = 0;

    for (int i = 0; i < lName_lValue.size(); ++i)
    {
       
       if ( lName_lValue[i].first == val ) {
          val = lName_lValue[i].second;
          count = i;
          break;
       }
    }  

    for (size_t i = 0; i < lName_lValue.size(); ++i) {
       
        if (name == lName_lValue[i].first)  {
            lName_lValue[i].second = val;
            return;
        }
        
    }
    
    tmp.first = name;
    tmp.second = val; 
    lName_lValue.push_back(tmp);
}