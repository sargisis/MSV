#include "keyword_checking.h"

KeywordCheck::KeywordCheck( Table& tbl )
    : keywords{"when", "otherwise", "paint", "write", "floop", "wloop"}
{
    for ( int i = 0; i < tbl.size(); ++i )
    {
        for ( int j = 0; j < keywords.size(); ++j )
        {
            if ( tbl.name_val[i].first == keywords[j] || tbl.name_val[i].second == keywords[j] )
            {
                std::cerr << "error: choose correct name for identifer." << std::endl
                << "\t ~~ Identifer name can not be a keyword." << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }
}