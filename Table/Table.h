#ifndef __TABLE__
#define __TABLE__

#include "../Includes/Liabrary.h"
#include "../GeneralTypes/BaseTypes/BaseType.h"
#include "../GeneralTypes/Types/Int/Int.h"
#include "../GeneralTypes/Types/Double/Double.h"
#include "../GeneralTypes/Types/Bool/Bool.h"
#include "../GeneralTypes/Types/String/String.h"
#include "../GeneralTypes/Types/Array/Array.h"

class Table
{
private:
    std::vector<std::unordered_set<Int*>> Tab;
    std::vector<std::unordered_set<Double*>> Tab1;
    std::vector<std::unordered_set<Bool*>> Tab2;
    std::vector<std::unordered_set<String*>> Tab3;
    std::vector<std::unordered_set<Array*>> Tab4;

public:
    Table();
    void SetIntPointer(Int* bt);
    void SetDoublePointer(Double* dt);
    void SetBoolPointer(Bool* bt);
    void SetStringPointer(String* bt);
    void SetArrayPointer(Array* bt);
    ~Table(){}
};



#endif// __TABLE__