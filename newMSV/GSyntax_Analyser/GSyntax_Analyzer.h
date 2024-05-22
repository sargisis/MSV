#ifndef __GSYNTAX_A_H__
#define __GSYNTAX_A_H__

#include <vector>
#include <string>

#include "../Global_Tokenizer/GTable.h"
#include "../GTable/GTable.h"

class GAST
{
    private:
        //MTable table;   // main table
        GTable tbl; // token table
        std::vector<std::string> keyword = {"when", "otherwise", "wloop", "floop", "paint", "write"};

    public:
        GAST() = default;
        GAST(std::vector<std::string> gast);
        void ch_var(std::vector<std::string> tmp);
        // void ch_key(std::vector<std::string> tmp);
        // void ch_paranthesis(std::vector<std::string> tmp);
        // void ch_quote(std::vector<std::string> tmp);
        void set(std::vector<std::string> tmp, Table& tbl, std::stack<std::string>& when, Table& tmp_table);
        bool W_hen(std::vector<std::string>&);
};  

#endif  // __GSYNTAX_A_H__