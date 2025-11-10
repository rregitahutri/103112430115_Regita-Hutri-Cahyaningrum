#ifndef STACKGAME_H
#define STACKGAME_H

#include <iostream>
#include <string>

const int N_STACK = 100; 

struct Stack {
    std::string info[N_STACK]; 
    int top;
};

void create_stack(Stack &S);
bool is_full(const Stack &S); 
bool is_empty(const Stack &S); 
void push(Stack &S, const std::string &x); 
void pop(Stack &S, std::string &p);
void kelolaAksi(const std::string &aksiPemain, Stack &StackAksi, Stack &StackRedo);
void hitungTotalDamage(Stack &S, int &totalDamage);
void printStack(const Stack &S, const std::string &namaStack);
std::string getStackString(const Stack &S);

#endif