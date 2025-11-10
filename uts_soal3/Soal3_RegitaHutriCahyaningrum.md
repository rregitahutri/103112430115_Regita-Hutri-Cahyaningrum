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
std::string getStackString(const Stack &S);

#endif
```

### stackGame.cpp

```C++
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
```

### main.cpp

```C++
#include "stackGame.h"
#include <iostream> 
#include <iomanip>

void printTableRow(const std::string &aksi, const Stack &StackAksi, const Stack &StackRedo) {
    std::cout << "| " << std::left << std::setw(8) << aksi;
    
    std::cout << "| " << std::left << std::setw(30) << getStackString(StackAksi);
    std::cout << " Top = " << std::left << std::setw(5) << StackAksi.top;

    std::cout << "| " << std::left << std::setw(30) << getStackString(StackRedo);
    std::cout << " Top = " << std::left << std::setw(5) << StackRedo.top << "|" << std::endl;
}

int main() {
    Stack StackAksi, StackRedo;
    create_stack(StackAksi);
    create_stack(StackRedo);

    // Untuk Header Tabel
    std::cout << "+-" << std::string(8, '-') << "+-" << std::string(42, '-') << "+-" << std::string(42, '-') << "+" << std::endl;
    std::cout << "| " << std::left << std::setw(8) << "Aksi";
    std::cout << "| " << std::left << std::setw(42) << "Stack Aksi";
    std::cout << "| " << std::left << std::setw(42) << "Stack Redo" << "|" << std::endl;
    std::cout << "+-" << std::string(8, '-') << "+-" << std::string(42, '-') << "+-" << std::string(42, '-') << "+" << std::endl;

    kelolaAksi("ATTACK", StackAksi, StackRedo);
    printTableRow("ATTACK", StackAksi, StackRedo);

    kelolaAksi("ATTACK", StackAksi, StackRedo);
    printTableRow("ATTACK", StackAksi, StackRedo);

    kelolaAksi("DEFENSE", StackAksi, StackRedo);
    printTableRow("DEFENSE", StackAksi, StackRedo);

    kelolaAksi("ATTACK", StackAksi, StackRedo);
    printTableRow("ATTACK", StackAksi, StackRedo);

    kelolaAksi("UNDO", StackAksi, StackRedo);
    printTableRow("UNDO", StackAksi, StackRedo);
    
    kelolaAksi("UNDO", StackAksi, StackRedo);
    printTableRow("UNDO", StackAksi, StackRedo);

    kelolaAksi("REDO", StackAksi, StackRedo);
    printTableRow("REDO", StackAksi, StackRedo);
    
    kelolaAksi("DEFENSE", StackAksi, StackRedo);
    printTableRow("DEFENSE", StackAksi, StackRedo);

    std::cout << "+-" << std::string(8, '-') << "+-" << std::string(42, '-') << "+-" << std::string(42, '-') << "+" << std::endl;

    return 0;
}
```

### OUTPUT
![Screenshot Output Unguided 3_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/uts_soal3/output.png)