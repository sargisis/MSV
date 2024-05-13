#ifndef __TABLE__
#define __TABLE__

#include "../Libraries/Libraries.h"

class Table {
public: 
    void setName(std::string name , std::string val);
    void setId(std::size_t id);
    size_t size();

    std::vector<std::pair<std::string, std::string>> name_val;
    std::vector<int> id; 
};


#endif // __TABLE__