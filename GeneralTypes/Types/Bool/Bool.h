#ifndef __BOOL__
#define __BOOL__
#include "../../../Includes/Liabrary.h"
#include "../../BaseTypes/BaseType.h"

class Bool : public BaseType
{
private:
    /* data */
public:
    Bool(std::string name, std::string value, std::string type);
    ~Bool() = default;
};




#endif //__BOOL__