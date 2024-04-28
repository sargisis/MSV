#ifndef __TABLE__
#define __TABLE__

#include "Liabrary.h"

class Table {
public:
        void setName(std::string name , std::string val);
        void setId(std::size_t id);

        std::vector<std::string> name;
        std::vector<std::string> value; 
        std::vector<int> id; 
};





#endif // __TABLE__