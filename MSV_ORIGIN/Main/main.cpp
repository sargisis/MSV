#include "../Includes/Liabrary.h"
#include "../SyntaxAnaliys/Syntax.h"
#include "../Table/Table.h"
#include "../Statments/If_Else_/If_Else.h"

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
   
    If_Else if_else_table;
    Table table;
    Syntax object(read, table, if_else_table);

    for (size_t i = 0; i < table.Tab.size(); i++) {
        std::cout << "global_name = " << table.Tab[i].name << "         " 
        << "value = " << table.Tab[i].value << "          " 
        << "type = " << table.Tab[i].type << std::endl;
    }

   for (size_t i = 0; i < if_else_table.Tab.size(); i++) {
        std::cout << "local_name = " << if_else_table.Tab[i].name << "         " 
        << "value = " << if_else_table.Tab[i].value << "          " 
        << "type = " << if_else_table.Tab[i].type << std::endl;
    }
    
    return 0;
}
