#include "Table.h"

void Table::setName(std::string name , std::string val) {
    std::pair<std::string, std::string> tmp;
    for (size_t i = 0; i < name_val.size(); i++)
    {
        if (name == name_val[i].first) {
            name_val[i].first = name;
            name_val[i].second = val;
            /*for (size_t j = 0; j < name_val.size(); i++) { 
                if (val == name_val[j].first) {
                    name_val[i].second = name_val[j].second;
                    return;
                }
            
           }*/
         return;  
        }
        
        
    }
    
    tmp.first = name;
    tmp.second = val;
    //this->name.push_back(name);
    //this->value.push_back(val);
    name_val.push_back(tmp);
    //name_val[0].second  = val;

}

void Table::setId(std::size_t id) {
    this->id.push_back(id);
}

size_t Table::size()
{
    return name_val.size();
}