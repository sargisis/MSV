#ifndef __BASETYPE__
#define __BASETYPE__
#include "../../Includes/Liabrary.h"

class BaseType
{
protected:
    std::string name;
    std::string value;
    std::string type;
public:
    std::string getType();
    BaseType() = default;
    ~BaseType();
};




#endif // __BASETYPE__