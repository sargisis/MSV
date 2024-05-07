#ifndef __DOUBLE__
#define __DOUBLE__
#include "../../../Includes/Liabrary.h"
#include "../../BaseTypes/BaseType.h"

class Double : public BaseType
{
private:
    /* data */
public:
    Double(std::string Name, std::string Value, std::string Type);
    ~Double();
};




#endif// __DOUBLE__