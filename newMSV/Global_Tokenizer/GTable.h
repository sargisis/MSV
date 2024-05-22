#ifndef __GTABLE_H__
#define __GTABLE_H__

#include <vector>
#include <string>
#include <stack>

class GTable
{
    private:
        std::vector<std::string> line;

    public:

        GTable() = default;
        void setLine(std::vector<std::string> l);
        std::vector<std::string> getLine();
        std::size_t size();
        bool When( std::vector<std::string>& When_vec, std::stack<std::string>& when);
};

#endif  // __GTABLE_H__