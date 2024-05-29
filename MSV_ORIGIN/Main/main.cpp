#include "../Includes/Liabrary.h"
#include "../SyntaxAnaliys/Syntax.h"
#include "../Table/Table.h"
#include "../Statments/If_Else_/If_Else.h"
#include "../Statments/Loops/While.h"
#include "../InputOutput/InputOutput.h"


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
    
    While while_table;
    If_Else if_else_table;
    Table table;
    Input in(table);
    Output out(table);
    Syntax object(read, table, if_else_table, while_table, in, out);

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

    for (size_t i = 0; i < while_table.Tab.size(); i++) {
        std::cout << "while_loc_name = " << while_table.Tab[i].name << "         " 
        << "value = " << while_table.Tab[i].value << "          " 
        << "type = " << while_table.Tab[i].type << std::endl;
    }
    
    
    return 0;
}
