#ifndef __GTABLE_H__
#define __GTABLE_H__

#include <vector>
#include <string>

class GTable
{
    private:
        std::vector<std::string> line;

    public:
        void setLine(std::vector<std::string> l);
        std::vector<std::string> getLine();
        std::size_t size();
};

#endif  // __GTABLE_H__