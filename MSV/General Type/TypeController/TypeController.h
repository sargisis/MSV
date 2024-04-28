#ifndef TYPECONTROLLER_H
#define TYPECONTROLLER_H

#include <sstream>

class TypeController {
public:
    explicit TypeController(const std::string type, const std::string codeLine);
    void createType(const std::string type, const std::string code);
    ~TypeController() = default;
};

#endif // TYPECONTROLLER_H
