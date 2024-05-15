#ifndef __TYPE__
#define __TYPE__

#include "../Table/Table.h"
#include "../Libraries/Libraries.h"
#include "../Tokenizing/Tokenizing.h"
#include "../Type/Array/Array.h"
#include "../Type/Int/Int.h"
#include "../Type/Bool/Bool.h"
#include "../Type/Double/Double.h"
#include "../Type/String/String.h"

class TypeController {
private:
    vector<pair<string , void*>> check; 
    
    Int i_int;
    Double d_double; 
    Bool b_bool;
    String s_string;
    Array a_array; 

    string type; 
    string name; 
    string code; 
public:
    TypeController(vector<std::string>& vec, Table& table);
    void resolveDeclaration(vector<string>& vec, Table& table);
    void createType(Table& table);
    ~TypeController() = default;
};



#endif // 