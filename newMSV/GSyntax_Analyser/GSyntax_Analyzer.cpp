#include <iostream>

#include "GSyntax_Analyzer.h"

GAST::GAST(std::vector<std::string> gast)
{
    ch_var(gast);
    ch_key(gast);
}

void GAST::ch_var(std::vector<std::string> tmp)
{
    std::string sym = "qwertyuiopasdfghjklzxcvbnm_QWERTYUIOPASDFGHJKLZXCVBNM";
    
    if ( sym.find(tmp[0][0]) == std::string::npos )
    {
        std::cout << "Variable name must start from [a-z][A-Z][-]"
        << std::endl;
        throw;
    }
}

void GAST::ch_key(std::vector<std::string> gast)
{
    for ( int i = 0; i < keyword.size(); ++i )
    {
        for ( int j = 0; j < gast.size(); ++j )
        {
            if ( this->keyword[i] == gast[j] )
            {
                std::cout << "keyword can't be used as a name for variable" << std:: endl;
                throw;
            }
        }
    }
}