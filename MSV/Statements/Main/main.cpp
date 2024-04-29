#include <iostream>
#include <fstream>

int main(int argc, char * argv[])
{
    std::ifstream read(argv[1]);

    if (!read.is_open()) {
        std::cout << "error" << std::endl;
        throw;
    }

    run(read);

    return 0;
}

