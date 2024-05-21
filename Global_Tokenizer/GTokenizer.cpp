#include <sstream>
#include <string>

#include "GTokenizer.h"


GTokenizer::GTokenizer(std::string line, GTable& tbl)
{
    addspace(line);
    slicer(line, tbl);
}

void GTokenizer::addspace(std::string& line)
{
    for ( int i = 0; i < line.size(); ++i )
    {
        if ( line[i] == '=' )
        {
            line.insert(i, " ");
            line.insert(i + 2, " ");
            ++i;
        }

        if ( line[i] == '+' )
        {
            line.insert(i, " ");
            line.insert(i + 2, " ");
            ++i;
        }

        if ( line[i] == '-' )
        {
            line.insert(i, " ");
            line.insert(i + 2, " ");
            ++i;
        }

        if ( line[i] == '*' && line[0] != '"' )
        {
            line.insert(i, " ");
            line.insert(i + 2, " ");
            ++i;
        }

        if ( line[i] == '/' )
        {
            line.insert(i, " ");
            line.insert(i + 2, " ");
            ++i;
        }

        if ( line[i] == '%' )
        {
            line.insert(i, " ");
            line.insert(i + 2, " ");
            ++i;
        }

        if ( line[i] == '(' )
        {
            line.insert(i, " ");
            line.insert(i + 2, " ");
            ++i;
        }

        if ( line[i] == ')' )
        {
            line.insert(i, " ");
            line.insert(i + 2, " ");
            ++i;
        }
    }
}


void GTokenizer::slicer(std::string line, GTable& tbl)
{
    std::vector<std::string> tmp;
    std::string word;
    std::istringstream slice(line);

    while ( slice >> word )
    {
        tmp.push_back(word);
    }

    tbl.setLine(tmp);

}

