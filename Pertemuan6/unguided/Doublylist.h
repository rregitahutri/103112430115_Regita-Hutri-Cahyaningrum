#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct kendaraan{
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan dataKendaraan;

typedef struct node *address;

struct node{
    dataKendaraan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
bool isNopolExist(linkedlist L, string nopol);
void createList(linkedlist &List);
address alokasi(string nopol, string warna, int thnBuat);
void dealokasi(address &node);
address inputKendaraan();

void insertLast(linkedlist &List, address nodeBaru);
void findByNopol(linkedlist List, string nopol);

void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);

void deleteByNopol(linkedlist &List, string nopol);
void deleteNode(linkedlist &List, address target);

void printList(linkedlist List);

#endif