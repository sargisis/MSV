#include "Table.h"

Table::Table() = default;


void Table::SetIntPointer(Int* bt)
{   
    std::unordered_set<Int*> t;
    Tab.push_back(t);
    bt->print();
}

void Table::SetDoublePointer(Double* dt)
{   
    std::unordered_set<Double*> t1;
    Tab1.push_back(t1);
}

void Table::SetBoolPointer(Bool* bt)
{   
    std::cout << "bool";
    std::unordered_set<Bool*> t2;
    Tab2.push_back(t2);
    
    
}

void Table::SetStringPointer(String* bt)
{   
    
    std::unordered_set<String*> t3;
    Tab3.push_back(t3);
    
}

void Table::SetArrayPointer(Array* bt)
{   
    
    std::unordered_set<Array*> t4;
    Tab4.push_back(t4);
    
}