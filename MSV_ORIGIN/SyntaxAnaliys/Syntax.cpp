#include "../Includes/Liabrary.h"
#include "../GeneralTypes/TypeController/TypeController.h"
#include "../Table/Table.h"
#include "Syntax.h"

Syntax::Syntax(std::ifstream& write_obj, Table& table, If_Else& if_else_table) // ctor called run function
{
    run(write_obj, table, if_else_table);
}

void Syntax::run(std::ifstream& write, Table& table, If_Else& if_else_table)
{ 
    std::string line; 
    int flag_if = 6;

    while(write.good()) { //loop to end file
        std::getline(write, line);
        
        if (line == "" || line == "{") { //line is empty ++line
            continue;
        }
        
        std::vector<std::string> vec;

        add_space(line);// a=5 --> a = 5, a+5 --> a + 5, 
        vec = Tokenizing(line);// a = 5 ----> [0] = "a" [1] = "=" [2] = "5"
        Syntax_analysis(vec);//valid variable or not
        
        
        
        if (vec[0] == "when") {
            resolve_if_expr(vec, table); // check if_expr true or false 
            if ((vec[2] == "1") || (vec[2] == "true")) {
                IF_stack.push_back("{");
                flag_if = 1; //if_expr true
                continue;// nexet line
            }else{
                flag_if = 2;//false
                continue;
            }
        }
     
        //wheni falsi depqum petq e mtni ev ancni bolor toxerov minchev }
        if ((flag_if == 2) && (IF_stack.empty() == true)) {
                if (vec[0] == "}") {
                    flag_if = 3;//scope end
                    continue;;
                } 
            continue;
                           //true
        }else if((flag_if == 1) && (IF_stack.back() == "{")) { // the next if body
            if (vec[0] == "}") {
                IF_stack.pop_back();
                //if_else_table.Tab.clear();
                flag_if = 0;
                continue;
            }
            resolve_if_body_variable(vec, table, if_else_table);
            TypeController object(vec, if_else_table, table);
            continue;
        }
  
        //Else-i hamar
        //ete when-@ true e
        if ((vec[0] == "otherwise" || vec[1] == "otherwise") && flag_if == 0) {           
            continue;
        }else if (flag_if == 0)
        {
            if (vec[0] == "}"){
                flag_if = 6;
            }    
            continue;
        }else if ((vec[0] == "otherwise" || vec[1] == "otherwise") && flag_if == 2) {
            std::cout << vec[0] << std::endl;
            IF_stack.push_back("{");
            flag_if = 7;
            continue;
        }

        //ete when@ false e
        if (flag_if == 7) {
            if (vec[0] == "}") {
                IF_stack.pop_back();
                //if_else_table.Tab.clear();
                flag_if = 6;
                continue;
            }
            resolve_if_body_variable(vec, table, if_else_table);
            TypeController object(vec, if_else_table, table);
            continue;
        }
          
                
        Resolve_expression(vec, table);
        TypeController object(vec, table);
    }
   
}

void Syntax::Syntax_analysis(std::vector<std::string>& vec)
{   
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
        if (line[i] == ':') {
            line.insert(i, " ");
            line.insert(i + 2, " ");
            ++i;
        }
        if (line[i] == '{' && line[i - 1] != ' ') {
            line.insert(i, " ");
            //line.insert(i + 2, " ");
            ++i;
        }     
        if (line[i] == '}' && line[i + 1] != ' ') {
            //line.insert(i, " ");
            line.insert(i + 1, " ");
            ++i;
        } 
        if (line[i] == '=' && line[i + 1] == '=') {
            line.insert(i, " ");
            line.insert(i + 3, " ");
            i += 3; // Increment i to skip the newly inserted space
        }

        if (line[i] == '=' && line[i + 1] != '=') {
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
        if (line[i] == '!' && line[i + 1] == '=') {
            line.insert(i, " ");   // Insert space before '<'
            line.insert(i + 3, " "); // Insert space after '='
            i += 2;
        }
        if (line[i] == '>' && line[i + 1] == '=') {
            line.insert(i, " ");   // Insert space before '<'
            line.insert(i + 3, " "); // Insert space after '='
            i += 2;
        }
        if (line[i] == '<' && line[i + 1] == '=') {
            line.insert(i, " ");   // Insert space before '<'
            line.insert(i + 3, " "); // Insert space after '='
            i += 2;
        }
        if (line[i] == '>') {
            line.insert(i, " ");
            line.insert(i + 2, " ");
            i++;
        }
        if (line[i] == '<') {
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

void Syntax::Resolve_expression(std::vector<std::string>& vec, Table& table)
{   
    if (vec.size() == 3) {
        for (size_t i = 0; i < table.Tab.size(); i++) {
            if (vec[2] == table.Tab[i].name) {
                vec[2] =  table.Tab[i].value;
            }            
   
        }  
    }

    double res{};
    bool result{};
    std::string True_False{};
    int i  = 3;
    while (i < vec.size())
    {
        if(vec[i] == "*") {        
           res =  std::stod(Eval(vec[i - 1], table)) * std::stod(Eval(vec[i + 1], table));
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);
           std::string tmp_st = std::to_string(res);
           while (tmp_st.back() == '0') {
                tmp_st.pop_back();
           }
           if (tmp_st.back() == '.'){
                tmp_st.pop_back();
           }
           vec.insert(vec.begin() + i - 1, tmp_st);
           continue;
        }
        if(vec[i] == "/") {        
           res =  std::stod(Eval(vec[i - 1], table)) / std::stod(Eval(vec[i + 1], table));
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);
           std::string tmp_st = std::to_string(res);
           while (tmp_st.back() == '0') {
                tmp_st.pop_back();
           }          
           if (tmp_st.back() == '.'){
                tmp_st.pop_back();
           }
           vec.insert(vec.begin() + i - 1, tmp_st);
           continue;
        }

        i++;
    }

    i = 3;
    while (i < vec.size())
    {
        if(vec[i] == "+") {   
           res =  std::stod(Eval(vec[i - 1], table)) + std::stod(Eval(vec[i + 1], table));
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);
           std::string tmp_st = std::to_string(res);
           while (tmp_st.back() == '0') {
                tmp_st.pop_back();
           }          
           if (tmp_st.back() == '.'){
                tmp_st.pop_back();
           }
           vec.insert(vec.begin() + i - 1, tmp_st);
           continue;
        }

        if(vec[i] == "-") {  
           res =  std::stod(Eval(vec[i - 1], table)) - std::stod(Eval(vec[i + 1], table));
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);
           std::string tmp_st = std::to_string(res);
           while (tmp_st.back() == '0') {
                tmp_st.pop_back();
           }        
           if (tmp_st.back() == '.'){
                tmp_st.pop_back();
           }  
           vec.insert(vec.begin() + i - 1, tmp_st);
           continue;
        }
        ++i;
    }

    i = 3;
    while (i < vec.size())
    {
        if(vec[i] == "!=") {   
           result =  std::stod(Eval(vec[i - 1], table)) != std::stod(Eval(vec[i + 1], table));
           if (result == 0) {
               True_False  = "false";
           }else{
                True_False = "true";
           }
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);
           vec.insert(vec.begin() + i - 1, True_False);
           continue;
        }

        if(vec[i] == "<=") {          
           result =  std::stod(Eval(vec[i - 1], table)) <= std::stod(Eval(vec[i + 1], table));
           if (result == 0) {
               True_False  = "false";
           }else{
                True_False = "true";
           }
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);
           vec.insert(vec.begin() + i - 1, True_False);
           continue;
        }

        if(vec[i] == ">=") {           
           result =  std::stod(Eval(vec[i - 1], table)) >= std::stod(Eval(vec[i + 1], table));
           if (result == 0) {
               True_False  = "false";
           }else{
                True_False = "true";
           }
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);         
           vec.insert(vec.begin() + i - 1, True_False);
           continue;
        }

        if(vec[i] == "<") {
           result =  std::stod(Eval(vec[i - 1], table)) < std::stod(Eval(vec[i + 1], table));
           if (result == 0) {
               True_False  = "false";
           }else{
                True_False = "true";
           }
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);         
           vec.insert(vec.begin() + i - 1, True_False);
           continue;
        }

        if(vec[i] == ">") {   
           result = std::stod(Eval(vec[i - 1], table)) > std::stod(Eval(vec[i + 1], table));
           if (result == 0) {
               True_False  = "false";
           }else{
                True_False = "true";
           }
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);        
           vec.insert(vec.begin() + i - 1, True_False);
           continue;
        }
        ++i;
    }   
    
}

std::string Syntax::Eval(std::string unresolved_val, Table& table)
{    
    for (size_t i = 0; i < table.Tab.size(); i++) {
        if (unresolved_val == table.Tab[i].name) {
            return table.Tab[i].value;
        }       
    }
    return unresolved_val;
}

void Syntax::resolve_if_expr(std::vector<std::string>& vec, Table& table)
{

    bool res{};
    bool result{};
    std::string True_False{};
    int i  = 1;
    while (i < vec.size())
    {
        if(vec[i] == "*") {        
           res =  std::stod(Eval(vec[i - 1], table)) * std::stod(Eval(vec[i + 1], table));
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);
        //    std::string tmp_st = std::to_string(res);
        //    while (tmp_st.back() == '0') {
        //         tmp_st.pop_back();
        //    }          
           vec.insert(vec.begin() + i - 1, std::to_string(res));
        }
        if(vec[i] == "/") {        
           res =  std::stod(Eval(vec[i - 1], table)) / std::stod(Eval(vec[i + 1], table));
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);
        //    std::string tmp_st = std::to_string(res);
        //    while (tmp_st.back() == '0') {
        //         tmp_st.pop_back();
        //    }          
           vec.insert(vec.begin() + i - 1, std::to_string(res));
        }

        ++i;
    }

    i = 1;
    while (i < vec.size())
    {
        if(vec[i] == "+") {   
           res =  std::stod(Eval(vec[i - 1], table)) + std::stod(Eval(vec[i + 1], table));
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);
        //    std::string tmp_st = std::to_string(res);
        //    while (tmp_st.back() == '0') {
        //         tmp_st.pop_back();
        //    }          
           vec.insert(vec.begin() + i - 1, std::to_string(res));
        }
    
        if(vec[i] == "-") {  
           res =  std::stod(Eval(vec[i - 1], table)) - std::stod(Eval(vec[i + 1], table));
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);
        //    std::string tmp_st = std::to_string(res);
        //    while (tmp_st.back() == '0') {
        //         tmp_st.pop_back();
        //    }          
           vec.insert(vec.begin() + i - 1, std::to_string(res));
        }
        ++i;
    }

    i = 1;
    while (i < vec.size())
    {
        if(vec[i] == "!=") {   
           result =  std::stod(Eval(vec[i - 1], table)) != std::stod(Eval(vec[i + 1], table));
           if (result == 0) {
               True_False  = "false";
           }else{
                True_False = "true";
           }
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);
           vec.insert(vec.begin() + i - 1, True_False);
        }

        if(vec[i] == "==") {   
           result =  std::stod(Eval(vec[i - 1], table)) == std::stod(Eval(vec[i + 1], table));
           if (result == 0) {
               True_False  = "false";
           }else{
                True_False = "true";
           }
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);
           vec.insert(vec.begin() + i - 1, True_False);
        }

        if(vec[i] == "<=") {          
           result =  std::stod(Eval(vec[i - 1], table)) <= std::stod(Eval(vec[i + 1], table));
           if (result == 0) {
               True_False  = "false";
           }else{
                True_False = "true";
           }
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);
           vec.insert(vec.begin() + i - 1, True_False);
        }

        if(vec[i] == ">=") {           
           result =  std::stod(Eval(vec[i - 1], table)) >= std::stod(Eval(vec[i + 1], table));
           if (result == 0) {
               True_False  = "false";
           }else{
                True_False = "true";
           }
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);         
           vec.insert(vec.begin() + i - 1, True_False);
        }

        if(vec[i] == "<") {
           result =  std::stod(Eval(vec[i - 1], table)) < std::stod(Eval(vec[i + 1], table));
           if (result == 0) {
               True_False  = "false";
           }else{
                True_False = "true";
           }
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);         
           vec.insert(vec.begin() + i - 1, True_False);
        }

        if(vec[i] == ">") {   
           result = std::stod(Eval(vec[i - 1], table)) > std::stod(Eval(vec[i + 1], table));
           if (result == 0) {
               True_False  = "false";
           }else{
                True_False = "true";
           }
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);        
           vec.insert(vec.begin() + i - 1, True_False);
        }
        ++i;
    }   

    // for (size_t i = 0; i < vec.size(); i++) {
    //     if (vec[i] == "}"){
    //         IF_stack.pop_back();
    //         return;
    //     }
    // }
}

std::string Syntax::if_else_Eval(std::string unresolved_val, If_Else& if_else_table, Table& table)
{   

    for (size_t i = 0; i < if_else_table.Tab.size(); i++) { //ete localum ka uremn da veradarcru
        if (unresolved_val == if_else_table.Tab[i].name) {
            return if_else_table.Tab[i].value;
        }
    }
    for (size_t i = 0; i < table.Tab.size(); i++) {// ays depqum globalum nayi ete ka veradarcru
        if (unresolved_val == table.Tab[i].name) {
            return table.Tab[i].value;
        }
    }
       
    return unresolved_val;
}

void Syntax::resolve_if_body_variable(std::vector<std::string>& vec, Table& table, If_Else& if_else_table)
{   
    bool flag1 = false;
    if (vec.size() == 3) {
        for (size_t i = 0; i < if_else_table.Tab.size(); i++) {
            if (vec[2] == if_else_table.Tab[i].name) {
                vec[2] =  if_else_table.Tab[i].value;
                flag1 = true;// ete ifi tablum kar apa veradarcnum e true
            }            
   
        }  
    }
    if (vec.size() == 3 && flag1 == false) {
        for (size_t i = 0; i < table.Tab.size(); i++) {
            if (vec[2] == table.Tab[i].name) {
                vec[2] =  table.Tab[i].value;
            }            
   
        } 
    }
    
    double res{};
    bool result{};
    std::string True_False{};
    int i  = 3;
    while (i < vec.size())
    {
        if(vec[i] == "*") { 
           res =  std::stod(if_else_Eval(vec[i - 1], if_else_table, table)) * std::stod(if_else_Eval(vec[i + 1], if_else_table, table));
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);
           std::string tmp_st = std::to_string(res);
           while (tmp_st.back() == '0') {
                tmp_st.pop_back();
           }      
           if (tmp_st.back() == '.'){
                tmp_st.pop_back();
           }    
           vec.insert(vec.begin() + i - 1, tmp_st);
           //i -= 2;
           continue;
        }
        if(vec[i] == "/") {     
           res =  std::stod(if_else_Eval(vec[i - 1],if_else_table, table)) / std::stod(if_else_Eval(vec[i + 1],if_else_table, table));
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);
           std::string tmp_st = std::to_string(res);
           while (tmp_st.back() == '0') {
                tmp_st.pop_back();
           }          
           if (tmp_st.back() == '.'){
                tmp_st.pop_back();
           }
           vec.insert(vec.begin() + i - 1, tmp_st);
           continue;
        }

        i++;
    }

    i = 3;
    while (i < vec.size())
    {
        if(vec[i] == "+") {   
           res =  std::stod(if_else_Eval(vec[i - 1],if_else_table, table)) + std::stod(if_else_Eval(vec[i + 1],if_else_table, table));
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);
           std::string tmp_st = std::to_string(res);
           while (tmp_st.back() == '0') {
                tmp_st.pop_back();
           }          
           if (tmp_st.back() == '.'){
                tmp_st.pop_back();
           }
           vec.insert(vec.begin() + i - 1, tmp_st);
           continue;
        }
        

        if(vec[i] == "-") {  
           res =  std::stod(if_else_Eval(vec[i - 1],if_else_table, table)) - std::stod(if_else_Eval(vec[i + 1],if_else_table, table));
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);
           std::string tmp_st = std::to_string(res);
           while (tmp_st.back() == '0') {
                tmp_st.pop_back();
           }   
           if (tmp_st.back() == '.'){
                tmp_st.pop_back();
           }       
           vec.insert(vec.begin() + i - 1, tmp_st);
           continue;
        }
        i++;
    }

    i = 3;
    while (i < vec.size())
    {
        if(vec[i] == "!=") {   
           result =  std::stod(if_else_Eval(vec[i - 1],if_else_table, table)) != std::stod(if_else_Eval(vec[i + 1],if_else_table, table));
           if (result == 0) {
               True_False  = "false";
           }else{
                True_False = "true";
           }
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);
           vec.insert(vec.begin() + i - 1, True_False);
           continue;
        }

        if(vec[i] == "<=") {          
           result =  std::stod(if_else_Eval(vec[i - 1],if_else_table, table)) <= std::stod(if_else_Eval(vec[i + 1],if_else_table, table));
           if (result == 0) {
               True_False  = "false";
           }else{
                True_False = "true";
           }
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);
           vec.insert(vec.begin() + i - 1, True_False);
           continue;
        }

        if(vec[i] == ">=") {           
           result =  std::stod(if_else_Eval(vec[i - 1],if_else_table, table)) >= std::stod(if_else_Eval(vec[i + 1],if_else_table, table));
           if (result == 0) {
               True_False  = "false";
           }else{
                True_False = "true";
           }
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);         
           vec.insert(vec.begin() + i - 1, True_False);
           continue;
        }

        if(vec[i] == "<") {
           result =  std::stod(if_else_Eval(vec[i - 1],if_else_table, table)) < std::stod(if_else_Eval(vec[i + 1],if_else_table, table));
           if (result == 0) {
               True_False  = "false";
           }else{
                True_False = "true";
           }
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);         
           vec.insert(vec.begin() + i - 1, True_False);
           continue;
        }

        if(vec[i] == ">") {   
           result = std::stod(if_else_Eval(vec[i - 1],if_else_table, table)) > std::stod(if_else_Eval(vec[i + 1],if_else_table, table));
           if (result == 0) {
               True_False  = "false";
           }else{
                True_False = "true";
           }
           vec.erase(vec.begin() + i - 1, vec.begin() + i + 2);        
           vec.insert(vec.begin() + i - 1, True_False);
           continue;
        }
        ++i;
    }   
    
}

Syntax::~Syntax()
{}