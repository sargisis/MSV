#ifndef __GSYNTAX_A_H__
#define __GSYNTAX_A_H__

#include <vector>
#include <string>

#include "../Global_Tokenizer/GTable.h"

class GAST
{
    private:
        //MTable table;   // main table
        GTable tbl; // token table
        std::vector<std::string> keyword = {"when", "otherwise", "wloop", "floop", "paint", "write"};

    public:
        GAST(std::vector<std::string> gast);
        void ch_var(std::vector<std::string> tmp);
        void ch_key(std::vector<std::string> tmp);
};

#endif  // __GSYNTAX_A_H__