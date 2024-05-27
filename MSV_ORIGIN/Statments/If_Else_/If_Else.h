#ifndef __IF_ELSE__
#define __IF_ELSE__
#include "../../Includes/Liabrary.h"
#include "../../Table/Table.h"

class If_Else : public Table
{
public:
    void when(); // when = if 
    void otherwise(); // otherwise = else
    If_Else() = default;
    ~If_Else() = default;
};



#endif// __IF_ELSE__