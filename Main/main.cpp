#include "../Includes/Liabrary.h"
#include "../SyntaxAnaliys/Syntax.h"
#include "../Table/Table.h"

// #include "./Tokenizing/Tokenizing.h"

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
    Table table;
    Syntax object(read, table);

    // while ( i < tbl.size() )
    // {
    //     std::cout << tbl.name_val[i].first << " " << tbl.name_val[i].second << std::endl;
    //     ++i;
    // }
    
    return 0;
}
