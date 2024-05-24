#include "ResolveExpression.h"
#include "../ALU/ALU.h"

#include <vector>
#include <string>

std::vector<std::string> RExpression::res_exp(std::vector<std::string> tmp)
{
    //std::cout << "MTAV" << std::endl;

    ALU alu;
    std::string expression;
    std::string temp;

    int i = 0;

    double res{};
    i  = 0;
    while (i < tmp.size())
    {
        if(tmp[i] == "*") {
            
           res =  std::stod(tmp[i - 1]) * std::stod(tmp[i + 1]);
           tmp.erase(tmp.begin() + i - 1, tmp.begin() + i + 2);
           tmp.insert(tmp.begin() + i - 1, std::to_string(res));
        }
        if(tmp[i] == "/") {
            
           res =  std::stod(tmp[i - 1]) / std::stod(tmp[i + 1]);
           tmp.erase(tmp.begin() + i - 1, tmp.begin() + i + 2);
           tmp.insert(tmp.begin() + i - 1, std::to_string(res));
        }

        ++i;
    }

    i = 0;
    while (i < tmp.size())
    {
        if(tmp[i] == "+") {
            
           res =  std::stod(tmp[i - 1]) + std::stod(tmp[i + 1]);
           tmp.erase(tmp.begin() + i - 1, tmp.begin() + i + 2);
           tmp.insert(tmp.begin() + i - 1, std::to_string(res));
        }

        if(tmp[i] == "-") {
            
           res =  std::stod(tmp[i - 1]) - std::stod(tmp[i + 1]);
           tmp.erase(tmp.begin() + i - 1, tmp.begin() + i + 2);
           tmp.insert(tmp.begin() + i - 1, std::to_string(res));
        }
        ++i;
    }

    return tmp;
}