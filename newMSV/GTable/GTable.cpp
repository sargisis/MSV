#include "GTable.h"
#include <iostream>

std::string deduceType(std::string value)
{
    std::string digits = "0123456789";
    //std::string type;

    // checkig string
    if ( value[0] == '"' && value[value.size() - 1] == '"' )
    {
        //type = "string";
        return "string";
    }

    // checking int
    int count{};
    for ( int i = 0; i < value.size(); ++i )
    {
        if ( digits.find(value[i]) != std::string::npos )
        {
            ++count;
        }
    }

    if ( count == value.size() )
    {
        //type = "int";
        return "int";
    }

    // checking double
    int i{}, j{};
    while ( i < value.size() )
    {
        if ( digits.find(value[i]) != std::string::npos )
        {
            ++j;
        }
        ++i;
    }

    if ( j == value.size() - 1 && value.find('.') )
    {
        //type = "double";
        return "double";
    }

    // checking array
    if ( value[0] == '[' && value[value.size() - 1] == ']' )
    {
        //type = "array";
        return "array";
    }

    // checking bool
    if ( value == "true" || value == "false" )
    {
        //type = "bool";
        return "bool";
    }

    //return type;
    std::cerr << "Type is incorrect" << std::endl;
    throw;
}

Table::Table() = default;

Table::Table(std::vector<std::string> tmp)
{
    setTable(tmp);
}

void Table::setTable(std::vector<std::string> tmp)
{   

    VarInfo ob;
    
    for ( int i = 0; i < table.size(); ++i )
    {
        if ( tmp[2] == table[i].name )
        {
            tmp[2] = table[i].value;
            break;
        }
    }

    for (size_t i = 0; i < table.size(); i++)
    {
        if (table[i].name == tmp[0])
        {
        table[i].value = tmp[2];
        return;
        }
    }
    
    
    
    ob.name = tmp[0];

    if ( tmp[2][0] == '[' && tmp[tmp.size() - 1].find(']') != std::string::npos )
    {
        for ( int i = 3; i < tmp.size(); ++i )
        {
            tmp[2] += tmp[i];
        }
        ob.value = tmp[2];
        //cout << ob.value << endl;
    }
    else
    {
        ob.value = tmp[2];
    }

    if ( tmp[2][0] == '"' && tmp[tmp.size() - 1].find('"') != std::string::npos )
    {
        for ( int i = 3; i < tmp.size(); ++i )
        {
            tmp[2] += tmp[i];
        }
        ob.value = tmp[2];
        //cout << ob.value << endl;
    }
    else
    {
        ob.value = tmp[2];
    }

    ob.type = ::deduceType(tmp[2]);

    table.push_back(ob);
}