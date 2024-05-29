#include "./InputOutput.h"

Input::Input(Table& out)
    : tbl{out}
{}

Output::Output(Table& in)
    : tbl{in}
{}

void Output::Paint(std::string object)
{
    std::string digits = "0123456789";
    std::string sym = "qwertyuiopasdfghjklzxcvbnm_QWERTYUIOPASDFGHJKLZXCVBNM";

    for ( int i = 0; i < tbl.Tab.size(); ++i )
    {
        // if variable print variable value
        if ( object == tbl.Tab[i].name )
        {
            if ( tbl.Tab[i].type == "string" )
            {
                tbl.Tab[i].value.erase(tbl.Tab[i].value.begin());
                tbl.Tab[i].value.pop_back();
            }

            std::cout << tbl.Tab[i].value << std::endl;
            return;
        }

        // print if digit
        if ( digits.find(object) != std::string::npos )
        {
            cout << object << endl;
        }

        if ( object[0] == '\"' )
        {
            object.erase(object.begin());
            object.pop_back();
            cout << object << endl;
        }

        if ( object == "true" || object == "false" )
        {
            cout << object << endl;
        }
    }
}

void Input::Write(std::string object)
{
    for ( int i = 0; i < tbl.Tab.size(); ++i )
    {
        if ( object == tbl.Tab[i].name )
        {
            std::string tmp;
            std::getline(std::cin, tmp);
            tbl.Tab[i].value = tmp;
            return;
        }
    }

    throw;
}