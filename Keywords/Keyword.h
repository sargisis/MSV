#ifndef __KEYWORDS__
#define __KEYWORDS__
#include "../Includes/Liabrary.h"

class Keyword
{
    
public:
    void when(); // when = if 
    void otherwise(); // otherwise = else 
    void paint(); // paint = std::cout 
    void write(); // write = std::cin
    void floop(); // floop = for 
    void wloop(); // wloop = while 
    Keyword(/* args */);
    ~Keyword();
};

#endif