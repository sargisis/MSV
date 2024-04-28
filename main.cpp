#include "./Tokenizing/Liabrary.h"
#include "./Tokenizing/Table.h"
#include "./Tokenizing/Tokenizing.h"

int main(int argc, char *argv[])
{
    if ( argc != 2 ) {
        std::exception();
    }

    std::ifstream read(argv[1]);
    if (!read.is_open()) {
        std::cerr << "Error" << std::endl;
        std::exception(); 
    }
    Table tbl;
    Tokenizing(read, tbl);

    int i = 0;
    while ( i < 2 )
    {
        std::cout << tbl.name[i] << " "
        << tbl.value[i] << std::endl;
        ++i;
    }
    
    return 0;
}
