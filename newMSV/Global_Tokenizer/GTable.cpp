#include "GTable.h"

void GTable::setLine(std::vector<std::string> l)
{
    line = std::move(l);
}

std::vector<std::string> GTable::getLine()
{
    return line;
}

std::size_t GTable::size()
{
    return line.size();
}