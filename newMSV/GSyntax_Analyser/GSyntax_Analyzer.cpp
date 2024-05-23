#include <iostream>
#include <vector>
#include <string>

#include "GSyntax_Analyzer.h"
#include "../ResolveExpression/ResolveExpression.h"
#include "../GTable/GTable.h"

GAST::GAST(std::vector<std::string_view> gast)
{
    ch_var(gast);
    ch_key(gast);
    ch_paranthesis(gast);
    ch_quote(gast);
}

void GAST::ch_var(std::vector<std::string_view> tmp)
{
    std::string sym = "qwertyuiopasdfghjklzxcvbnm_QWERTYUIOPASDFGHJKLZXCVBNM";
    
    if ( sym.find(tmp[0][0]) == std::string::npos )
    {
        std::cout << "Variable name must start from [a-z][A-Z][-]"
        << std::endl;
        throw;
    }
}

void GAST::ch_key(std::vector<std::string_view> gast)
{
    for ( int i = 0; i < keyword.size(); ++i )
    {
        for ( int j = 0; j < gast.size(); ++j )
        {
            if ( this->keyword[i] == gast[j] )
            {
                std:: cout << "keyword can't be used as a name for variable" << std:: endl;
                throw;
            }
        }
    }
}

void GAST::ch_paranthesis(std::vector<std::string_view> tmp)
{
    std::string recover_line;
    for ( int i = 0; i < tmp.size(); ++i )
    {
        recover_line += tmp[i];
    }

    if ( recover_line.find('(') != std::string::npos )
    {
        int lpi = recover_line.find('(');   // left paranthes's index
        if ( recover_line.find(')') != std::string::npos )
        {
            int rpi = recover_line.find(')');   // right paranthes's index
            if ( rpi < lpi )
            {
                std::cerr << "Paranthesis must be opened then closed" << std::endl;
                throw;
            }
        }
        else
        {
            std::cerr << "Paranthesis must be closed" << std::endl;
            throw;
        }
    }
    else if ( recover_line.find(')') != std::string::npos )
    {
        std::cerr << "Paranthesis must be opend then closed" << std::endl;
        throw;
    }
}

void GAST::ch_quote(std::vector<std::string_view> tmp)
{
    for ( int i = 0; i < tmp.size(); ++i )
    {
        if ( tmp[i].find('"') != std::string::npos )
        {
            int j = i;
            while ( j < tmp.size() )
            {
                if ( tmp[j].find('"') == std::string::npos )
                {
                    std::cerr << "Opened quote must be closed." << std::endl;
                    throw;
                }
                ++j;
            }
        }
        else if ( tmp[i].find('"') != std::string::npos )
        {
            std::cerr << "Quotes must be opened than closed" << std::endl;
            throw;
        }
    }

}

void GAST::set(std::vector<std::string> tmp, Table& tbl)
{   
        std::vector<std::string> tmpVec = tmp; 

        int i = 0;
        while (tmpVec[i] != "=")
        {
            tmpVec.erase(tmpVec.begin() + i);
        }
        tmpVec.erase(tmpVec.begin() + i);
    
        RExpression expres;

        std::vector<std::string> t = expres.res_exp(tmpVec);

        tmp.erase(tmp.begin() + 2, tmp.end() - 1);

        tmp[tmp.size() - 1] = t[0];
    
    for (size_t i = 0; i < tmp.size(); i++)
    {
        std::cout << tmp[i] << " ";
    }
    std::cout << std::endl; 
    
    std::vector<std::string> tmpVec1 = tmp;

     i = 0;
    while (tmpVec1[i] != "=")
    {
        tmpVec1.erase(tmpVec1.begin() + i);
    }
    tmpVec1.erase(tmpVec1.begin() + i);
    
    RExpression expres1;

    std::vector<std::string> t1 = expres1.res_exp(tmpVec);

    tmp.erase(tmp.begin() + 2, tmp.end() - 1);

    tmp[tmp.size() - 1] = t[0];    

}

void GAST::equal_to(std::vector<std::pair<std::string, int>> tmp) {
    if (tmp[0].first == tmp[0].first) {
        return;
    } else if (tmp[0].first != tmp[2].first) {
        tmp[2].second = tmp[0].second;
    } 
}