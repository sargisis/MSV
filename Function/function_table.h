#ifndef __FUNCTION_TABLE__
#define __FUNCTION_TABLE__

#include <string>
#include <vector>
#include <utility>

class FTable
{
    public:
        void setName(std::string name, std::string val);
        void setId(std::size_t id);
        std::size_t size();

        std::vector<std::pair<std::string, std::string>> lName_lValue;
        std::vector<int> id;
};

#endif  // __FUNCTION_TABLE__