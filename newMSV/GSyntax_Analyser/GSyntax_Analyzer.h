#ifndef __GSYNTAX_A_H__
#define __GSYNTAX_A_H__

#include <vector>
#include <string>
#include <string_view>

#include "../Global_Tokenizer/GTable.h"
#include "../GTable/GTable.h"

class GAST
{
    private:
        //MTable table;   // main table
        GTable tbl; // token table
        std::vector<std::string_view> keyword = {"when", "otherwise", "wloop", "floop", "paint", "write"};

    public:
        GAST() = default;
        GAST(std::vector<std::string_view> gast);
        void ch_var(std::vector<std::string_view> tmp);
        void ch_key(std::vector<std::string_view> tmp);
        void ch_paranthesis(std::vector<std::string_view> tmp);
        void ch_quote(std::vector<std::string_view> tmp);
        void set(std::vector<std::string> tmp, Table& tbl);
        void equal_to(std::vector<std::pair<std::string , int>> tmp); // added 
};  

#endif  // __GSYNTAX_A_H__