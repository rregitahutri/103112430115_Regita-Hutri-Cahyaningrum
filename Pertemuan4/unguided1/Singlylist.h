#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct angka{
    int num;
};

typedef angka dataAngka;
typedef struct node *address;

struct node{
    dataAngka info;
    address next;
};
struct linkedList {
    address first;
};
  
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(int x);
void dealokasi(address &node);
void printInfo(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);

#endif