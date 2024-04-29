#include "Tokenizing.h"

Tokenizing::Tokenizing(std::ifstream& ob , Table& tbl) {
    run(ob ,tbl);
}


std::vector<std::string> Tokenizing::tokenizing(std::string line) {
    std::vector<std::string> v; 
    std::string word; 
    std::istringstream slice(line);
    while(slice >> word) {
        v.push_back(word);
    }
    return v; 
}
 

void Tokenizing::run(std::ifstream& src , Table& tbl) {
    std::string line; 
    std::size_t count = 0; 

    int i = 0;

    while( src.good() ) {
        std::getline(src ,line);
        
        if ( line == "" )
        {
            continue;
        }
        
        // if (  == ";" )
        // {
        //     line = line.substr(i);
        // }

        // line.pop_back();
        std::vector<std::string> v = tokenizing(line);
        v[2].pop_back();
        tbl.setName(v[0], v[2]);
        tbl.setId(count);
        ++count; 
        ++i;

    }
}

