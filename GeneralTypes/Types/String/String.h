#ifndef __STRING__
#define __STRING__
#include "../../../Includes/Liabrary.h"
#include "../../BaseTypes/BaseType.h"

class String : public BaseType
{
private:
    /* data */
public:
    String(std::string Name, std::string Value, std::string Type);
    ~String();
};



#endif// __STRING__