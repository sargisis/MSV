#ifndef __INPUT_OUTPUT__
#define __INPUT_OUTPUT__

#include "../Table/Table.h"

using std::cout;
using std::endl;

class Output
{
    private:
        Table& tbl;

    public:
        Output(Table& out);
        void Paint(std::string object);
};

class Input
{
    private:
        Table& tbl;

    public:
        Input(Table& in);
        void Write(std::string object);
};

#endif  // __INPUT_OUTPUT__