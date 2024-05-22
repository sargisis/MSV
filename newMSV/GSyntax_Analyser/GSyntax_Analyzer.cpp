#include <iostream>
#include <vector>
#include <string>

#include "GSyntax_Analyzer.h"
#include "../ResolveExpression/ResolveExpression.h"
#include "../GTable/GTable.h"

GAST::GAST(std::vector<std::string> gast)
{
    ch_var(gast);
    // ch_key(gast);
    // ch_paranthesis(gast);
    // ch_quote(gast);
    //set(gast);
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

// void GAST::ch_key(std::vector<std::string> gast)
// {
//     for ( int i = 0; i < keyword.size(); ++i )
//     {
//         for ( int j = 0; j < gast.size(); ++j )
//         {
//             if ( this->keyword[i] == gast[j] )
//             {
//                 std::cout << "keyword can't be used as a name for variable" << std:: endl;
//                 throw;
//             }
//         }
//     }
// }

// void GAST::ch_paranthesis(std::vector<std::string> tmp)
// {
//     std::string recover_line;
//     for ( int i = 0; i < tmp.size(); ++i )
//     {
//         recover_line += tmp[i];
//     }

//     if ( recover_line.find('(') != std::string::npos )
//     {
//         int lpi = recover_line.find('(');   // left paranthes's index
//         if ( recover_line.find(')') != std::string::npos )
//         {
//             int rpi = recover_line.find(')');   // right paranthes's index
//             if ( rpi < lpi )
//             {
//                 std::cerr << "Paranthesis must be opened then closed" << std::endl;
//                 throw;
//             }
//         }
//         else
//         {
//             std::cerr << "Paranthesis must be closed" << std::endl;
//             throw;
//         }
//     }
//     else if ( recover_line.find(')') != std::string::npos )
//     {
//         std::cerr << "Paranthesis must be opend then closed" << std::endl;
//         throw;
//     }
// }

//void GAST::ch_quote(std::vector<std::string> tmp)
//{
    // for ( int i = 0; i < tmp.size(); ++i )
    // {
    //     if ( tmp[i].find('"') != std::string::npos )
    //     {
    //         int j = i;
    //         while ( j < tmp.size() )
    //         {
    //             if ( tmp[j].find('"') == std::string::npos )
    //             {
    //                 std::cerr << "Opened quote must be closed." << std::endl;
    //                 throw;
    //             }
    //             ++j;
    //         }
    //     }
    //     else if ( tmp[i].find('"') != std::string::npos )
    //     {
    //         std::cerr << "Quotes must be opened than closed" << std::endl;
    //         throw;
    //     }
    // }



// Just testing rsolve expression object

//std::vector<std::string> tempr = {"a", "=", "2", "+", "3", "-", "4", "*", "1"};
//}

void GAST::set(std::vector<std::string> tmp, Table& tbl,  std::stack<std::string>& when, Table& tmp_table)
{   
    ch_var(tmp);
    if(W_hen(tmp)) 
    {
        when.push("{");
    }

    if (when.empty())
    {
        std::cout << "mtaaaaaaaaaaav" << std::endl;
        // if(W_hen(tmp)) {
        // when.push("{");

    

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
    
    // for (size_t i = 0; i < tmp.size(); i++)
    // {
    //     std::cout << tmp[i] << " ";;
    // }
    
    
   
        tmp_table.setTable(tmp);
        return;
    }
    
    




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
    
    // for (size_t i = 0; i < tmp.size(); i++)
    // {
    //     std::cout << tmp[i] << " ";;
    // }
    
    
   
    tbl.setTable(tmp);
}

bool GAST::W_hen( std::vector<std::string>& When_vec)
{
    for (size_t i = 0; i < When_vec.size(); i++)
    {
        if (When_vec[i] == "when")
        {   
            if(When_vec.size() == 2 && (When_vec[2] != "0" || When_vec[2] != "false")){
                return true;
            }
            
            
        }
        
    }
    return false;
}