#include <iostream>
#include <fstream>

int main()
{
    std::ifstream read("source.msv");

    if (!read.is_open()) {
        std::cout << "error" << std::endl;
        throw;
    }

    run(read);

    return 0;
}

