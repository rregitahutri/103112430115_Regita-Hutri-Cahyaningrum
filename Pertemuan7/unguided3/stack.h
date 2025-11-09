#ifndef STACK
#define STACK
#define Nil -1
#define MAX 20

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype data[MAX];
    int top;
};

bool isEmpty(Stack S);
bool isFull(Stack S);
void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif
