#ifndef __G_TOKENIZER_H__
#define __G_TOKENIZER_H__

#include <fstream>

#include "GTable.h"

class GTokenizer
{
    public:
        GTokenizer(std::string line, GTable& tbl);
        void addspace(std::string& line);
        void slicer(std::string line, GTable& tbl);

};

#endif  // __G_TOKENIZER_H__