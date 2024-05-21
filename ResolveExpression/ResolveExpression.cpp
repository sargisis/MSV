#include "ResolveExpression.h"
#include "../ALU/ALU.h"

void RExpression::res_exp(std::vector<std::string> tmp)
{
    std::string expression;

    for ( int i = 2; i < tmp.size(); ++i )
    {
        expression += tmp[i];
    }

    if ( expression.find('*') != std::string::npos )
    {
        ALU alu;
        double first = std::stod(expression.find('*') - 1);
        double second = std::stod(expression.find('*') + 1);
        double r = alu.multiply(first, second);
        std::cout << "Multiply result = " << r << std::endl;
    }
}