#include "Table.h"

void Table::setName(std::string name , std::string val) {
    this->name.push_back(name);
    this->value.push_back(val);
}

void Table::setId(std::size_t id) {
    this->id.push_back(id);
}