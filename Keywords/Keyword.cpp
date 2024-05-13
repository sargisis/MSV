#include "Keywords.h"
#include "../Libraries/Libraries.h"


void Keywords::when(bool condition , Action trueAction , Action falseAction) {
    if (condition) {
        trueAction();
    } else {
        falseAction();
    }

}

void trueAction() {
    std::cout << "Condition is true " << std::endl; 
}

void falseAction() {
    std::cout << "Condition is false " << std::endl; 
}



