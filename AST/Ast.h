#ifndef __AST__
#define __AST__
#include "../Includes/Liabrary.h"

class Ast
{
private:
    /* data */
public:
    Ast(const std::string& expression);
    operator double();
    operator int();
    ~Ast();
};




#endif // __AST__