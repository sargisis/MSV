#include "Table.h"

// ete val-@ ka name-eri mej,
// name-in veragrel val-i(val-@ darnuma name) val-@

void Table::setName(std::string name , std::string val) {
    std::pair<std::string, std::string> tmp;
   
    // valid variable name start
    std::string sym = "QWERTYUIOPASDFGHJKLZXCVBNM_qwertyuiopasdfghjklzxcvbnm";
    std::string digits = "0123456789";

    // if variable name don't start ['_', a-z, A-Z] throw runtime_error
     if (sym.find(name[0]) == std::string::npos) {  

        std::cout << "Identifier error:" << std::endl
        << "Identifer name must start ['_', 'a-z', 'A-Z']." << std::endl;
        throw std::runtime_error("");
     }
   
     int count = 0;
    
     for (int i = 0; i < name_val.size(); ++i) {
        
        if ( name_val[i].first == val ) {
           val = name_val[i].second;
           count = i;
           break;
        }
     }  

    for (size_t i = 0; i < name_val.size(); ++i) {
       
        if (name == name_val[i].first)  {
            name_val[i].second = val;
            return;
        }
        
    }
    
    tmp.first = name;
    tmp.second = val; 
    name_val.push_back(tmp);
   
}

void Table::setId(std::size_t id) {
    this->id.push_back(id);
}

size_t Table::size() {
    return name_val.size();
}

// Just added
// std::string Table::findById(std::size_t Id)
// {
//      binary search for id
//     int start = id.front();
//     int end = id.back();
    
//     while ( start <= end )
//     {
//         int mid = start + (end - 1) / 2;
        
//         if ( id[mid] == Id )
//         {
//              return variable's value
//             return name_val[mid].second;
//         }

//         if ( id[mid] < Id )
//         {
//             start = mid + 1;
//         }
//         else
//         {
//             end = mid - 1;    
//         }
//     }

//     std::cout << "Undefined variable usage"  << std::endl;
//     throw;
// }