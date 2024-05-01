#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void compile (void) __attribute__ ((constructor));

void compile(void) {
    system("g++ ./main.cpp ./Tokenizing/Tokenizing.cpp ./Tokenizing/Table.cpp ./Tokenizing/Keyword.cpp -o a.out");
}

int main(void) {
    system("./a.out test.msv");
    return 0;
}