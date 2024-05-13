#ifndef __KEYWORDS_
#define __KEYWORDS_

#include "Liabrary.h"

typedef std::function<void()> Action; 
class Keywords
{
private:
    std::string  value; 
public:

    void when(bool condition , Action trueAction , Action falseAction); // when = if 
    void otherwise(); // otherwise = else 
    void paint(); // paint = std::cout 
    void write(); // write = std::cin
    void floop(); // floop = for 
    void wloop(); // wloop = while 
    Keywords() = default;
    ~Keywords() = default; 
    

};


#endif // __KEYWORDS_ 

