#ifndef LISTANGKA_H
#define LISTANGKA_H
#define Nil NULL

#include<iostream>
using namespace std;

struct angka{
    int num;
};

typedef angka dataAngka;

typedef struct node *address;

struct node{
    dataAngka isidata;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(int num);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
int nbList(linkedlist List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

void FindNodeByData(linkedlist list, int data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, int nilaiMin);

int sumList(linkedlist List);
int subList(linkedlist List);
int multipleList(linkedlist List);

#endif