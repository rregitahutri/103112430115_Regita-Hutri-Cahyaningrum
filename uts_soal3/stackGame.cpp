#include "stackGame.h"
#include <iostream> 
#include <sstream>

void create_stack(Stack &S) {
    S.top = -1;
}

bool is_full(const Stack &S) {
    return (S.top == N_STACK - 1);
}

bool is_empty(const Stack &S) {
    return (S.top == -1);
}


void push(Stack &S, const std::string &x) {
    if (is_full(S)) {
        std::cout << "Stack penuh" << std::endl;
    } else {
        S.top++;
        S.info[S.top] = x;
    }
}

void pop(Stack &S, std::string &p) {
    if (is_empty(S)) {
        std::cout << "Stack kosong" << std::endl;
    } else {
        p = S.info[S.top];
        S.top--;
    }
}


void kelolaAksi(const std::string &aksiPemain, Stack &StackAksi, Stack &StackRedo) {
    std::string aksiBatal;

    if (aksiPemain == "ATTACK" || aksiPemain == "DEFENSE") {
        push(StackAksi, aksiPemain);
        create_stack(StackRedo); 
    } 
    else if (aksiPemain == "UNDO") {
        if (!is_empty(StackAksi)) {
            pop(StackAksi, aksiBatal);
            push(StackRedo, aksiBatal);
        }
    } 
    else if (aksiPemain == "REDO") {
        if (!is_empty(StackRedo)) {
            pop(StackRedo, aksiBatal);
            push(StackAksi, aksiBatal);
        }
    }
}


void hitungTotalDamage(Stack &S, int &totalDamage) {
    Stack tempStack;
    create_stack(tempStack);
    std::string aksi;

    totalDamage = 0;

    while (!is_empty(S)) {
        pop(S, aksi);
        if (aksi == "ATTACK") totalDamage += 30;
        else if (aksi == "DEFENSE") totalDamage += 5;
        push(tempStack, aksi);
    }

    while (!is_empty(tempStack)) {
        pop(tempStack, aksi);
        push(S, aksi);
    }
}

void printStack(const Stack &S, const std::string &namaStack) {
    std::cout << namaStack << ": [";
    if (is_empty(S)) {
        std::cout << "kosong";
    } else {
        for (int i = 0; i <= S.top; i++) {
            std::cout << S.info[i];
            if (i < S.top) {
                std::cout << ", "; 
            }
        }
    }
    std::cout << "]" << std::endl;
}

std::string getStackString(const Stack &S) {
    std::stringstream ss;
    ss << "[";
    if (is_empty(S)) {
    } else {
        for (int i = 0; i <= S.top; i++) {
            ss << S.info[i];
            if (i < S.top) {
                ss << " ";
            }
        }
    }
    ss << "]";
    return ss.str(); 
}