#ifndef __KEYWORD_CHECKING_HEADER__
#define __KEYWORD_CHECKING_HEADER__

#include <string>
#include <vector>

#include "../Table/Table.h"

class KeywordCheck
{
    private:
        std::vector<std::string> keywords;

    public:
        KeywordCheck( Table& tbl );
};

#endif  // KEYWORD_CHECKING