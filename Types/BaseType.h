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

class BaseType {
protected:
    string name;
    string value; 
    string type; 
public:
    BaseType() = default;
    string getType() const; 
    virtual ~BaseType();
};

#endif // TYPE