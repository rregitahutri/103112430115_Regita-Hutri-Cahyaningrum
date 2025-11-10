### stackGame.h
```C++
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

#endif
```

### stackGame.cpp

```C++
#include "stackGame.h"
#include <iostream> 


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
        create_stack(StackRedo); // Reset redo history
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
```

### main.cpp

```C++
#include "stackGame.h"
#include <iostream> 

int main() {
    Stack StackAksi, StackRedo;
    create_stack(StackAksi);
    create_stack(StackRedo);
    int totalDamage; // Deklarasikan di atas

    std::cout << "--- Program Dimulai ---" << std::endl;
    printStack(StackAksi, "Stack Aksi");
    printStack(StackRedo, "Stack Redo");

    std::cout << "\n--- Aksi 1: ATTACK ---" << std::endl;
    kelolaAksi("ATTACK", StackAksi, StackRedo);
    printStack(StackAksi, "Stack Aksi");
    printStack(StackRedo, "Stack Redo");

    std::cout << "\n--- Aksi 2: ATTACK ---" << std::endl;
    kelolaAksi("ATTACK", StackAksi, StackRedo);
    printStack(StackAksi, "Stack Aksi");
    printStack(StackRedo, "Stack Redo");

    std::cout << "\n--- Aksi 3: DEFENSE ---" << std::endl;
    kelolaAksi("DEFENSE", StackAksi, StackRedo);
    printStack(StackAksi, "Stack Aksi");
    printStack(StackRedo, "Stack Redo");
    
    std::cout << "\n--- Hitung Damage Awal ---" << std::endl;
    hitungTotalDamage(StackAksi, totalDamage);
    std::cout << "Total Damage: " << totalDamage << std::endl; // Harusnya 65

    std::cout << "\n--- Aksi 4: UNDO ---" << std::endl;
    kelolaAksi("UNDO", StackAksi, StackRedo);
    printStack(StackAksi, "Stack Aksi");
    printStack(StackRedo, "Stack Redo");
    hitungTotalDamage(StackAksi, totalDamage);
    std::cout << "Total Damage setelah UNDO: " << totalDamage << std::endl; // Harusnya 60

    std::cout << "\n--- Aksi 5: REDO ---" << std::endl;
    kelolaAksi("REDO", StackAksi, StackRedo);
    printStack(StackAksi, "Stack Aksi");
    printStack(StackRedo, "Stack Redo");
    hitungTotalDamage(StackAksi, totalDamage);
    std::cout << "Total Damage setelah REDO: " << totalDamage << std::endl; // Harusnya 65

    return 0;
}
```

### OUTPUT
![Screenshot Output Unguided 3_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/uts_soal3/output.png)