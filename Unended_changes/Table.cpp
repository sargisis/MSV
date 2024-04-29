#include "Table.h"

// ete val-@ ka name-eri mej,
// name-in veragrel val-i(val-@ darnuma name) val-@

void Table::setName(std::string name , std::string val) {
    std::pair<std::string, std::string> tmp;

    // // if variable name don't start ['_', a-z, A-Z] throw error
    // if ( (name[0] < 'A') && (name[0] > 'Z') && (name[0] < 'a') && (name[0] > 'z') &&  (name[0] != 0) )
    // {
    //     std::cout << "Identifier error:" << std::endl
    //     << "Identifer name must start ['_', 'a-z', 'A-Z']." << std::endl;
    // }


    for ( std::size_t i = 0; i < name_val.size(); ++i )
    {
        if ( name == name_val[i].first )
        {
            name_val[i].first = name;
            name_val[i].second = val;
            return;
        }
    }
    
    // if assign value is variable <=> checking
    // if ( val[0] >= 65 && val[0] <= 90 || val[0] >= 97 && val[0] <= 122 || val[0] == 95 )
    // {
    //     for ( std::size_t i = 0; i < name_val.size(); ++i )
    //     {
    //         if ( val == name_val[i].first )
    //         {
    //             name = name_val[i].second;
    //         }
    //     }

    //     std::cout << std::endl << "Undefined identifier:" << std::endl
    //     << "\t'" <<  val << "' used, but didn't declared" << std::endl;
    //     throw;
    // }

    tmp.first = name;
    tmp.second = val;
    name_val.push_back(tmp);
}

void Table::setId(std::size_t id)
{
    this->id.push_back(id);
}

size_t Table::size()
{
    return name_val.size();
}

// Just added
// std::string Table::findById(std::size_t Id)
// {
//     // binary search for id
//     int start = id.front();
//     int end = id.back();
    
//     while ( start <= end )
//     {
//         int mid = start + (end - 1) / 2;
        
//         if ( id[mid] == Id )
//         {
//             // return variable's value
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