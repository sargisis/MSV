#include "../Includes/Liabrary.h"
#include "../GeneralTypes/TypeController/TypeController.h"
#include "Syntax.h"

Syntax::Syntax(std::ifstream& write_obj, Table& table) // ctor called run function
{
    run(write_obj, table);
}

void Syntax::run(std::ifstream& write, Table& table)
{ 
    std::string line; 

    while(write.good()) { //loop to end file
        std::getline(write, line);
        
        if (line == "") { //line is empty ++line
            continue;
        }
        std::vector<std::string> vec;

        add_space(line);// a=5 --> a = 5, a+5 --> a + 5, 
        vec = Tokenizing(line);// a = 5 ----> [0] = "a" [1] = "=" [2] = "5"
        Syntax_analysis(line, vec);//valid variable or not
        Semantic_analysis(line, vec);
        TypeController object(vec, table);

    }
}

void Syntax::Syntax_analysis(std::string& line, std::vector<std::string>& vec)

{
    if (!vec.empty() && vec.size() > 2) {
        vec[2].pop_back(); // Remove the last character from the third element
        // if (!vec[2].empty() && vec[2][0] == '\"') {
        //     vec[2].erase(0, 1); // Erase the first character (starting from index 0)
        //     vec[2].pop_back(); // Remove the last character
        // }
    }
    // valid variable name start
    std::string sym = "QWERTYUIOPASDFGHJKLZXCVBNM_qwertyuiopasdfghjklzxcvbnm";
    std::string digits = "0123456789";

    // if variable name don't start ['_', a-z, A-Z] throw runtime_error
    if ( sym.find(vec[0].front()) == std::string::npos ) {  
        
        std::cout << "Identifier error:" << std::endl
        << "Identifer name must start ['_', 'a-z', 'A-Z']." << std::endl;
        throw std::runtime_error("");
     }
}

void Syntax::add_space(std::string & line)
{   
    for (size_t i = 0; i < line.size(); i++)//loop end line or added spaces
    {
        if (line[i] == '=') {
            line.insert(i, " ");
            line.insert(i + 2, " ");
            i++; // Increment i to skip the newly inserted space
        }
        if (line[i] == '+') {
            line.insert(i, " ");
            line.insert(i + 2, " ");
            i++;
        }
        if (line[i] == '-') {
            line.insert(i, " ");
            line.insert(i + 2, " ");
            i++;
        }
        if (line[i] == '*') {
            line.insert(i, " ");
            line.insert(i + 2, " ");
            i++;
        }
        if (line[i] == '/') {
            line.insert(i, " ");
            line.insert(i + 2, " ");
            i++;
        }
        if (line[i] == '%') {
            line.insert(i, " ");
            line.insert(i + 2, " ");
            i++;
        }
        
    }
}

std::vector<std::string> Syntax::Tokenizing(std::string& line) {
    std::vector<std::string> vec; 
    std::string word; 
    std::istringstream slice(line);
    while(slice >> word) {
        vec.push_back(word);
    }
    return vec; 
}

void Syntax::Semantic_analysis(std::string& line, std::vector<std::string>& vec)
{
    //keywordneri stugum, sxal veragrumner
}


Syntax::~Syntax()
{}