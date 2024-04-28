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
    while( std::getline(src ,line), !src.eof() ) {
        // std::getline(src ,line);
        line.pop_back();
        std::vector<std::string> v = tokenizing(line);
        tbl.setName(v[0], v[2]);
        tbl.setId(count);
        ++count; 

    }
}


