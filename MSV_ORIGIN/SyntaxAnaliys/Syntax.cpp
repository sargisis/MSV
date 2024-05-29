#include "../Includes/Liabrary.h"
#include "../GeneralTypes/TypeController/TypeController.h"
#include "../Table/Table.h"
#include "Syntax.h"

Syntax::Syntax(std::ifstream& write_obj, Table& table, If_Else& if_else_table, While& while_table, Input& in,  Output& out) // ctor called run function
{
    run(write_obj, table, if_else_table, while_table, in, out);
}

void Syntax::run(std::ifstream& write, Table& table, If_Else& if_else_table, While& while_table, Input& in, Output& out)
{ 
    std::string line; 
    int flag_if = 8;
    //else-i flag = 3
    //if-i flag = 1
    //if-i false-i flag = 2
    //else-i toxeri vrayov ancum = 4
    //while-i true-i flag@ = 5
    //while-i false-i flag@ = 6
    //while-i toxer@ pushback arac en tempory vectori mej = 7

    while(write.good()) { //loop to end file
        std::getline(write, line);

        if (line == "" || line == "{") { //line is empty ++line
            continue;
        }
        
        std::vector<std::string> vec;

        add_space(line);// a=5 --> a = 5, a+5 --> a + 5, 
        vec = Tokenizing(line);// a = 5 ----> [0] = "a" [1] = "=" [2] = "5"
        Syntax_analysis(vec);//valid variable or not
        
        // new added -----

        // Paint

        if ( (vec[0] == "paint") && (vec[1] == ":") && (vec.size() >= 2) )
        {

            out.Paint(vec[2]);
        }
        else if ( (vec[0] == "paint") && (vec[1] != ":") )
        {
            std::cerr << "syntax error: wrong usage of built-in function 'paint'"
            << std::endl << "   Usage: \"paint : \"" << std::endl;
            throw;
        }
        else if ( vec.size() < 2 )
        {
            std::cout << std::endl;
        }


        // Write

        if ( (vec[0] == "write") && (vec[1] == ":") && (vec.size() >= 2) )
        {
            out.Write(vec[2]);
        }
        else if ( (vec[0] == "write") && (vec[1] != ":") )
        {
            std::cerr << "syntax error: wrong usage of built-in function 'write'"
            << std::endl << "   Usage: \"write : \"" << std::endl;
            throw;
        }
        else if ( vec.size() < 2 )
        {
            std::cout << std::endl;
        }


        // ---------------


        //WLOOP begin
        if (vec[0] == "wloop") {
            resolve_if_expr(vec, table);
            if (vec[2] == "true" || vec[2] == "1") {
                IF_stack.push_back("{");
                flag_if = 5;
            }else{
                flag_if = 6;
                continue;
            }
        }
        //wloop falsi depqum petq e mtni EV ANCNI WHENI TOXERI VRAYOV minchev }
        if (flag_if == 6) {
            if (vec[0] == "}") {
                flag_if = 10;
            }
            continue;
        }
        //wloop-i true-i depqum mtnum e ev push_back anum wloop-i sax toxer@ minchev handipi }
        if (flag_if == 5) {  
            if (vec[0] == "wloop") {
                vec = Tokenizing(line);
                set_wline(vec);
                continue;
            }     
            if (vec[0] != "}") {
                set_wline(vec);
                continue;
            }
            set_wline(vec);
            flag_if = 7;  
        }
        //wloop-i marmni katarum
        if (flag_if == 7) {
            // for (size_t i = 0; i < w_line.size(); i++) {
            //     for (size_t j = 0; j < w_line[i].size(); j++){
            //         std::cout << "wline = " << w_line[i][j] << std::endl;
            //     }
            // }
            
            resolve_wloop_body(table, while_table);
            IF_stack.pop_back();
            flag_if = 10;
            continue;
        }
            
    
        

        
        //If_Else begin
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
     
        //wheni falsi depqum petq e mtni EV ANCNI WHENI TOXERI VRAYOV minchev }
        if ((flag_if == 2) && (IF_stack.empty() == true)) {
                if ((vec[0] == "}" && vec[1] == "otherwise") || vec[0] == "}") {
                    IF_stack.push_back("{");
                    flag_if = 3;//scope end
                    continue;
                } 
            continue;
        }
        
        //WHENI TRUE I JAMANAK MTNUM E STEX
        if((flag_if == 1) && (IF_stack.back() == "{")) { // the next if body
            if (vec[0] == "}") {
                IF_stack.pop_back();
                //if_else_table.Tab.clear();
                flag_if = 4;
                continue;
            }
            resolve_if_body_variable(vec, table, if_else_table);
            TypeController object(vec, if_else_table, table);
            continue;
        }
  
        //STEX ETE WHEN@ TRUE E APA MTNUM E ELSE I MEJ EV TOXERI VRAYOV ANCNUM MINCHEV } PAKAGIC U FLAG@ POXUM E 8 VOR SKSI GLOBALI HET ASHXATEL
        if ((vec[0] == "otherwise" || vec[1] == "otherwise") && flag_if == 4) {           
            continue;
        }else if (flag_if == 4) {
            if (vec[0] == "}"){
                flag_if = 10;
            }    
            continue;
        }

        //ete when@ false e
        if (flag_if == 3) {
            if (vec[0] == "}") {
                IF_stack.pop_back();
                //if_else_table.Tab.clear();
                flag_if = 10;
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

std::string Syntax::wloop_Eval(std::string unresolved_val, While& while_table, Table& table)
{
    for (size_t i = 0; i < while_table.Tab.size(); i++) { //ete localum ka uremn da veradarcru
        if (unresolved_val == while_table.Tab[i].name) {
            return while_table.Tab[i].value;
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

void Syntax::resolve_wloop_body(Table& table, While& while_table)
{   
    //size_t w = 1;
    
    std::vector<std::string> line_0;
    for (size_t i = 0; i < w_line[0].size(); i++) {
       line_0.push_back(w_line[0][i]);
    }   

    //return;
    
    bool check_expr = true;
    while (check_expr == true) {
    
    for (size_t l_n = 1; l_n < w_line.size(); l_n++) {

        if (w_line[l_n][0] == "}") {
            check_expr = resolve_wloop_expr(line_0, table);   
            if (check_expr){
                /* code */
            }
            
            return;
        }



        bool flag1 = false;
        if (w_line[l_n].size() == 3) {
            for (size_t i = 0; i < while_table.Tab.size(); i++) {
                if (w_line[l_n][2] == while_table.Tab[i].name) {
                    w_line[l_n][2] =  while_table.Tab[i].value;
                    flag1 = true;// ete ifi tablum kar apa veradarcnum e true
                    TypeController object(table, w_line[l_n], while_table);
                }            
   
            }  
        }
        if (w_line[l_n].size() == 3 && flag1 == false) {
            for (size_t i = 0; i < table.Tab.size(); i++) {
                if (w_line[l_n][2] == table.Tab[i].name) {
                    w_line[l_n][2] =  table.Tab[i].value;
                    TypeController object(table, w_line[l_n], while_table);
                }            
   
            } 
        }

    double res{};
    bool result{};
    std::string True_False{};
    int i  = 3;            

    //     while (i < w_line[l_n].size())
    //     {   
    //         if(w_line[l_n][i] == "*") { 
    //             res =  std::stod(wloop_Eval(w_line[l_n][i - 1], while_table, table)) * std::stod(wloop_Eval(w_line[l_n][i + 1], while_table, table));
    //             w_line[l_n].erase(w_line[l_n].begin() + i - 1, w_line[l_n].begin() + i + 2);
    //             std::string tmp_st = std::to_string(res);
    //             while (tmp_st.back() == '0') {
    //                 tmp_st.pop_back();
    //             }      
    //             if (tmp_st.back() == '.'){
    //                 tmp_st.pop_back();
    //             }    
    //             w_line[l_n].insert(w_line[l_n].begin() + i - 1, tmp_st);
    //             //i -= 2;
    //             continue;
    //         }
    //     if(w_line[l_n][i] == "/") {     
    //        res =  std::stod(wloop_Eval(w_line[l_n][i - 1],while_table, table)) / std::stod(wloop_Eval(w_line[l_n][i + 1],while_table, table));
    //        w_line[l_n].erase(w_line[l_n].begin() + i - 1, w_line[l_n].begin() + i + 2);
    //        std::string tmp_st = std::to_string(res);
    //        while (tmp_st.back() == '0') {
    //             tmp_st.pop_back();
    //        }          
    //        if (tmp_st.back() == '.'){
    //             tmp_st.pop_back();
    //        }
    //        w_line[l_n].insert(w_line[l_n].begin() + i - 1, tmp_st);
    //        continue;
    //     }

    //     i++;
    // }

    i = 3;
    while (i < w_line[l_n].size())
    {
        if(w_line[l_n][i] == "+") {  
           res =  std::stod(wloop_Eval(w_line[l_n][i - 1],while_table, table)) + std::stod(wloop_Eval(w_line[l_n][i + 1],while_table, table)); 
           w_line[l_n].erase(w_line[l_n].begin() + i - 1, w_line[l_n].begin() + i + 2);
           std::string tmp_st = std::to_string(res);
           while (tmp_st.back() == '0') {
                tmp_st.pop_back();
           }          
           if (tmp_st.back() == '.'){
                tmp_st.pop_back();
           }
           w_line[l_n].insert(w_line[l_n].begin() + i - 1, tmp_st);
            
           continue;
        }
        

        if(w_line[l_n][i] == "-") {  
           res =  std::stod(wloop_Eval(w_line[l_n][i - 1],while_table, table)) - std::stod(wloop_Eval(w_line[l_n][i + 1],while_table, table));
           w_line[l_n].erase(w_line[l_n].begin() + i - 1, w_line[l_n].begin() + i + 2);
           std::string tmp_st = std::to_string(res);
           while (tmp_st.back() == '0') {
                tmp_st.pop_back();
           }   
           if (tmp_st.back() == '.'){
                tmp_st.pop_back();
           }       
           w_line[l_n].insert(w_line[l_n].begin() + i - 1, tmp_st);
           continue;
        }
        i++;
    }

    i = 3;
    while (i < w_line[l_n].size())
    {
        if(w_line[l_n][i] == "!=") {   
           result =  std::stod(wloop_Eval(w_line[l_n][i - 1],while_table, table)) != std::stod(wloop_Eval(w_line[l_n][i + 1],while_table, table));
           if (result == 0) {
               True_False  = "false";
           }else{
                True_False = "true";
           }
           w_line[l_n].erase(w_line[l_n].begin() + i - 1, w_line[l_n].begin() + i + 2);
           w_line[l_n].insert(w_line[l_n].begin() + i - 1, True_False);
           continue;
        }

        if(w_line[l_n][i] == "==") {   
           result =  std::stod(wloop_Eval(w_line[l_n][i - 1],while_table, table)) == std::stod(wloop_Eval(w_line[l_n][i + 1],while_table, table));
           if (result == 0) {
               True_False  = "false";
           }else{
                True_False = "true";
           }
           w_line[l_n].erase(w_line[l_n].begin() + i - 1, w_line[l_n].begin() + i + 2);
           w_line[l_n].insert(w_line[l_n].begin() + i - 1, True_False);
           continue;
        }

        if(w_line[l_n][i] == "<=") {          
           result =  std::stod(wloop_Eval(w_line[l_n][i - 1],while_table, table)) <= std::stod(wloop_Eval(w_line[l_n][i + 1],while_table, table));
           if (result == 0) {
               True_False  = "false";
           }else{
                True_False = "true";
           }
           w_line[l_n].erase(w_line[l_n].begin() + i - 1, w_line[l_n].begin() + i + 2);
           w_line[l_n].insert(w_line[l_n].begin() + i - 1, True_False);
           continue;
        }

        if(w_line[l_n][i] == ">=") {           
           result =  std::stod(wloop_Eval(w_line[l_n][i - 1],while_table, table)) >= std::stod(wloop_Eval(w_line[l_n][i + 1],while_table, table));
           if (result == 0) {
               True_False  = "false";
           }else{
                True_False = "true";
           }
           w_line[l_n].erase(w_line[l_n].begin() + i - 1, w_line[l_n].begin() + i + 2);         
           w_line[l_n].insert(w_line[l_n].begin() + i - 1, True_False);
           continue;
        }

        if(w_line[l_n][i] == "<") {
           result =  std::stod(wloop_Eval(w_line[l_n][i - 1],while_table, table)) < std::stod(wloop_Eval(w_line[l_n][i + 1],while_table, table));
           if (result == 0) {
               True_False  = "false";
           }else{
                True_False = "true";
           }
           w_line[l_n].erase(w_line[l_n].begin() + i - 1, w_line[l_n].begin() + i + 2);         
           w_line[l_n].insert(w_line[l_n].begin() + i - 1, True_False);
           continue;
        }

        if(w_line[l_n][i] == ">") {   
           result = std::stod(wloop_Eval(w_line[l_n][i - 1],while_table, table)) > std::stod(wloop_Eval(w_line[l_n][i + 1],while_table, table));
           if (result == 0) {
               True_False  = "false";
           }else{
                True_False = "true";
           }
           w_line[l_n].erase(w_line[l_n].begin() + i - 1, w_line[l_n].begin() + i + 2);        
           w_line[l_n].insert(w_line[l_n].begin() + i - 1, True_False);
           continue;
        }
        ++i;
    }
    
     std::vector<std::string> w_line_vec;
     TypeController object(table, w_line[l_n], while_table);          
     
   } 
 }
}

void Syntax::set_wline(std::vector<std::string> vec)
{
    w_line.push_back(vec);
}

bool Syntax::resolve_wloop_expr(std::vector<std::string> vec, Table& table)
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
           if (vec[i - 1] == "false") {
                return false;
           }else {
               std::cout << vec[i - 1] << std::endl;
                return true;
           }
           
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
               return false;
           }else{
                True_False = "true";
                return true;
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
}


Syntax::~Syntax()
{}