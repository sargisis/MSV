#ifndef __INT__
#define __INT__
#include "../../../Includes/Liabrary.h"
#include "../../BaseTypes/BaseType.h"

class Int : BaseType
{
public:
    Int(std::string name, std::string value, std::string type);
    void print();
    ~Int();
};




#endif// __INT__