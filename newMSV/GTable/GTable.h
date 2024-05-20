#ifndef __GTABLE__
#define __GTABLE__

#include <vector>
#include <string>

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
    void resolveDeclaration(std::vector<std::string>& vec);

};

#endif  // __GTABLE__