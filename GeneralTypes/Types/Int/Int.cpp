#include "Int.h"
#include "../../../Table/Table.h"

Int::Int(std::string Name, std::string Value, std::string Type)
{
    name = Name;
    value = Value;
    type = Type;   
}

void Int::print()
{
    std::cout << name << " " << value << " " << type << std::endl;
}

Int::~Int()
{}