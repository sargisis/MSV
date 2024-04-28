#ifndef BASETYPE_H
#define BASETYPE_H
#include <iostream>
#include <vector>

class BaseType
{
protected:
    std::string name;
    std::string value;
    std::string size;
    std::string type;
    bool containsTypeInfo;

public:
    BaseType();
    std::vector<std::string> Tokenizing(std::string cur_line);
    //virtual void ShowingObjectInUi(Segment segment);
    virtual void operator=(std::string unresolved_value) = 0;
    virtual ~BaseType();
};
#endif // BASETYPE_H

