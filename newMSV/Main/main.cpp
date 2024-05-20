#include <iostream>
#include <fstream>
#include <string>

#include "../Library/Library.h"

void error(const char* msg);
void ch_argc(int argc);
void ch_ext(std::string ext);
void ch_fopen(std::ifstream& file);

int main(int argc, char* argv[])
{
    // checking arguments count
    ch_argc(argc);
    // argv[1] to std::string
    std::string farg = argv[1];
    // checking extansion compatibility
    ch_ext(farg);

    // Opening file
    std::ifstream file(argv[1], std::ios::in);
    // checking file opening correctness
    ch_fopen(file);

    Table vtbl;     // main table
    std::string line;

    while ( file.good() )
    {
        getline(file, line);

        if ( line == "" )
            continue;

        GTable tbl;
        GTokenizer tmp(line, tbl);
        GAST gast(tbl.getLine());
        vtbl.setTable(tbl.getLine());
    }
    for ( int i = 0; i < vtbl.table.size(); ++i )
        {
            std::cout << vtbl.table[i].name << " "
            << vtbl.table[i].value << " " << vtbl.table[i].type << std::endl;
        }
        std::cout << std::endl;
    return 0;
}

void error(const char* msg)
{
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(EXIT_FAILURE);
}

void ch_argc(int argc)
{
    if( argc != 2 )
        error("Wrong arguments count.");
}

void ch_ext(std::string farg)
{
    std::string ext = farg.substr(farg.size() - 4);

    if ( ext != ".msv" )
        error("File extansion is not compatible.");
}

void ch_fopen(std::ifstream& file)
{
    if ( !file.is_open() )
        error("Something gone wrong.\nCan't open the file");
}