#include "TypeController.h"
#include "../../Table/Table.h"

TypeController::TypeController(std::vector<std::string>& vec, Table& table)
{
    
    resolveDeclaration(vec, table);
}

TypeController::TypeController(std::vector<std::string>& vec, If_Else& if_else_table, Table& table)
{
    
    resolve_if_Declaration(vec, if_else_table, table);
}

TypeController::TypeController(Table& table, std::vector<std::string>& w_line, While& while_table)
{
    resolve_while_Declaration(table, w_line, while_table);
}
void TypeController::resolveDeclaration(std::vector<std::string>& vec, Table& table)
{   

    if (digits.find(vec[2].front()) != std::string::npos && vec[2].find(".") != std::string::npos) { // Check if the character is found in the digits string
        Table::Table_Info temp_vec;
        for (size_t i = 0; i < table.Tab.size(); i++) {
            if (vec[0] == table.Tab[i].name){
                table.Tab.erase(table.Tab.begin() + i);
            }   
        } 
        temp_vec.name = vec[0];
        temp_vec.value = vec[2];
        temp_vec.type = "double";
        table.Tab.push_back(temp_vec);       
        
    }
    else if(digits.find(vec[2].front()) != std::string::npos && vec[2].find(".") == std::string::npos) {
        Table::Table_Info temp_vec;
        for (size_t i = 0; i < table.Tab.size(); i++) {
            if (vec[0] == table.Tab[i].name){
                table.Tab.erase(table.Tab.begin() + i);
            }    
        } 
        temp_vec.value = vec[2];
        temp_vec.name = vec[0];
        temp_vec.type = "int";
        table.Tab.push_back(temp_vec);
    }
    else if(vec[2] == "true" || vec[2] == "false") {
        Table::Table_Info temp_vec;
        for (size_t i = 0; i < table.Tab.size(); i++) {
            if (vec[0] == table.Tab[i].name){
                table.Tab.erase(table.Tab.begin() + i);
            }
            
        } 
        temp_vec.value = vec[2];
        temp_vec.name = vec[0];
        temp_vec.type = "bool";
        table.Tab.push_back(temp_vec);
    }
    else if(symStr.find(vec[2].front() != std::string::npos)) {
        Table::Table_Info temp_vec;
        for (size_t i = 0; i < table.Tab.size(); i++) {
            if (vec[0] == table.Tab[i].name){
                table.Tab.erase(table.Tab.begin() + i);
            }
            
        } 
        temp_vec.value = vec[2];
        temp_vec.name = vec[0];
        temp_vec.type = "string";
        table.Tab.push_back(temp_vec);
    }
    else if(vec[0].find("[") != std::string::npos) {
        Table::Table_Info temp_vec;
        for (size_t i = 0; i < table.Tab.size(); i++) {
            if (vec[0] == table.Tab[i].name){
                table.Tab.erase(table.Tab.begin() + i);
            }
            
        } 
        //value-n piti grvi
        int i = 0;
        while (vec[0][i] != '[') {
            temp_vec.name +=  vec[0][i];
            ++i;
        }
        temp_vec.type = "array";
        table.Tab.push_back(temp_vec);
        
    }else {
         
    }
    
}

void TypeController::resolve_if_Declaration(std::vector<std::string>& vec, If_Else& if_else_table, Table& table)
{

    if (digits.find(vec[2].front()) != std::string::npos && vec[2].find(".") != std::string::npos) { // Check if the character is found in the digits string
        If_Else::Table_Info temp_vec;
        for (size_t i = 0; i < if_else_table.Tab.size(); i++) {
            if (vec[0] == if_else_table.Tab[i].name){
                if_else_table.Tab.erase(if_else_table.Tab.begin() + i);
            }   
        } 
        temp_vec.name = vec[0];
        temp_vec.value = vec[2];
        temp_vec.type = "double";
        if_else_table.Tab.push_back(temp_vec);       
        
    }
    else if(digits.find(vec[2].front()) != std::string::npos && vec[2].find(".") == std::string::npos) {
        If_Else::Table_Info temp_vec;
        for (size_t i = 0; i < if_else_table.Tab.size(); i++) {
            if (vec[0] == if_else_table.Tab[i].name){
                if_else_table.Tab.erase(if_else_table.Tab.begin() + i);
            }    
        } 
        temp_vec.value = vec[2];
        temp_vec.name = vec[0];
        temp_vec.type = "int";
        if_else_table.Tab.push_back(temp_vec);
    }
    else if(vec[2] == "true" || vec[2] == "false") {
        If_Else::Table_Info temp_vec;
        for (size_t i = 0; i < if_else_table.Tab.size(); i++) {
            if (vec[0] == if_else_table.Tab[i].name){
                if_else_table.Tab.erase(if_else_table.Tab.begin() + i);
            }
            
        } 
        temp_vec.value = vec[2];
        temp_vec.name = vec[0];
        temp_vec.type = "bool";
        if_else_table.Tab.push_back(temp_vec);
    }
    else if(symStr.find(vec[2].front() != std::string::npos)) {
        If_Else::Table_Info temp_vec;
        for (size_t i = 0; i < if_else_table.Tab.size(); i++) {
            if (vec[0] == if_else_table.Tab[i].name){
                if_else_table.Tab.erase(if_else_table.Tab.begin() + i);
            }
            
        } 
        temp_vec.value = vec[2];
        temp_vec.name = vec[0];
        temp_vec.type = "string";
        if_else_table.Tab.push_back(temp_vec);
    }
    else if(vec[0].find("[") != std::string::npos) {
        If_Else::Table_Info temp_vec;
        for (size_t i = 0; i < if_else_table.Tab.size(); i++) {
            if (vec[0] == if_else_table.Tab[i].name){
                if_else_table.Tab.erase(if_else_table.Tab.begin() + i);
            }
            
        } 
        //value-n piti grvi
        int i = 0;
        while (vec[0][i] != '[') {
            temp_vec.name +=  vec[0][i];
            ++i;
        }
        temp_vec.type = "array";
        if_else_table.Tab.push_back(temp_vec);
        
    }
}

void TypeController::resolve_while_Declaration(Table& table, std::vector<std::string>& vec, While& while_table)
{
    if (digits.find(vec[2].front()) != std::string::npos && vec[2].find(".") != std::string::npos) { // Check if the character is found in the digits string
        If_Else::Table_Info temp_vec;
        for (size_t i = 0; i < table.Tab.size(); i++) {
            if (vec[0].front() == '~' && vec[1] == table.Tab[i].name){
                temp_vec.name = table.Tab[i].name;
                temp_vec.value = vec[3];
                temp_vec.type = "double";
                table.Tab.push_back(temp_vec);
                table.Tab.erase(table.Tab.begin() + i);

                return;

            }
        }
        for (size_t i = 0; i < while_table.Tab.size(); i++) {
            if (vec[0] == while_table.Tab[i].name){
                while_table.Tab.erase(while_table.Tab.begin() + i);
            }   
        } 
        temp_vec.name = vec[0];
        temp_vec.value = vec[2];
        temp_vec.type = "double";
        while_table.Tab.push_back(temp_vec);       
        
    }
    else if(digits.find(vec[2].front()) != std::string::npos && vec[2].find(".") == std::string::npos) {
        If_Else::Table_Info temp_vec;
        for (size_t i = 0; i < table.Tab.size(); i++) {
            if (vec[0].front() == '~' && vec[1] == table.Tab[i].name){
                temp_vec.name = table.Tab[i].name;
                temp_vec.value = vec[3];
                temp_vec.type = "int";
                table.Tab.push_back(temp_vec);
                table.Tab.erase(table.Tab.begin() + i);
                return;

            }
        }
        for (size_t i = 0; i < while_table.Tab.size(); i++) {
            if (vec[0] == while_table.Tab[i].name){
                while_table.Tab.erase(while_table.Tab.begin() + i);
            }    
        } 
        temp_vec.value = vec[2];
        temp_vec.name = vec[0];
        temp_vec.type = "int";
        while_table.Tab.push_back(temp_vec);
    }
    else if(vec[2] == "true" || vec[2] == "false") {
        If_Else::Table_Info temp_vec;
        for (size_t i = 0; i < table.Tab.size(); i++) {
            if (vec[0].front() == '~' && vec[1] == table.Tab[i].name){
                temp_vec.name = table.Tab[i].name;
                temp_vec.value = vec[3];
                temp_vec.type = "bool";
                table.Tab.push_back(temp_vec);
                table.Tab.erase(table.Tab.begin() + i);

                return;

            }
        }
        for (size_t i = 0; i < while_table.Tab.size(); i++) {
            if (vec[0] == while_table.Tab[i].name){
                while_table.Tab.erase(while_table.Tab.begin() + i);
            }
            
        } 
        temp_vec.value = vec[2];
        temp_vec.name = vec[0];
        temp_vec.type = "bool";
        while_table.Tab.push_back(temp_vec);
    }
    else if(symStr.find(vec[2].front() != std::string::npos)) {
        If_Else::Table_Info temp_vec;
        for (size_t i = 0; i < table.Tab.size(); i++) {
            if (vec[0].front() == '~' && vec[1] == table.Tab[i].name){
                temp_vec.name = table.Tab[i].name;
                temp_vec.value = vec[3];
                temp_vec.type = "string";
                table.Tab.push_back(temp_vec);
                table.Tab.erase(table.Tab.begin() + i);

                return;

            }
        }
        for (size_t i = 0; i < while_table.Tab.size(); i++) {
            if (vec[0] == while_table.Tab[i].name){
                while_table.Tab.erase(while_table.Tab.begin() + i);
            }
            
        } 
        temp_vec.value = vec[2];
        temp_vec.name = vec[0];
        temp_vec.type = "string";
        while_table.Tab.push_back(temp_vec);
    }
    else if(vec[0].find("[") != std::string::npos) {
        If_Else::Table_Info temp_vec;
        for (size_t i = 0; i < while_table.Tab.size(); i++) {
            if (vec[0] == while_table.Tab[i].name){
                while_table.Tab.erase(while_table.Tab.begin() + i);
            }
            
        } 
        //value-n piti grvi
        int i = 0;
        while (vec[0][i] != '[') {
            temp_vec.name +=  vec[0][i];
            ++i;
        }
        temp_vec.type = "array";
        while_table.Tab.push_back(temp_vec);
        
    }
}

TypeController::~TypeController()
{}