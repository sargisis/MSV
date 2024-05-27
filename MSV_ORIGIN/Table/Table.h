#ifndef __TABLE__
#define __TABLE__

#include "../Includes/Liabrary.h"


class Table { 
public:
    struct Table_Info
    {
        std::string name{};
        std::string value{};
        std::string type{};
    };
    

public:
    std::vector<Table_Info> Tab;
    
public:

    Table();
    ~Table(){}
};



#endif// __TABLE__