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
        if ( line == "" ) {
            continue;
        }

        add_space(line);
        std::vector<std::string> v = tokenizing(line);

        if (!v.empty() && v.size() > 2) {
            v[2].pop_back(); // Remove the last character from the third element

            if (!v[2].empty() && v[2][0] == '\"') {
                v[2].erase(0, 1); // Erase the first character (starting from index 0)
                v[2].pop_back(); // Remove the last character
            }
        }
        
        tbl.setName(v[0], v[2]);
        tbl.setId(count);
        ++count; 
        ++i;

    }
}

void Tokenizing::add_space(std::string & line) {   
    for (size_t i = 0; i < line.size(); i++) {     
        if (line[i] == '=') {
            line.insert(i, " ");
            line.insert(i + 2, " ");
            i++; // Increment i to skip the newly inserted space
        }
    }
}