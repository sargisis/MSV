#ifndef __ALU_H__
#define __ALU_H__

#include <string>

class ALU
{
    private:

    public:
        double adder(double first, double second);
        double subtract(double first, double second);
        double multiply(double first, double second);
        double divider(double first, double second);
        size_t modulo(int first, int second);
};

#endif  // __ALU_H__