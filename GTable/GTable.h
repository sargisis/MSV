#ifndef __GTABLE__
#define __GTABLE__

#include <vector>
#include <string>

std::string deduceType(std::string value);

struct Table
{
    struct VarInfo
    {
        std::string name;
        std::string value;
        std::string type;
    };

    std::vector<VarInfo> table;

    void setTable(std::vector<std::string> tmp);

};

#endif  // __GTABLE__