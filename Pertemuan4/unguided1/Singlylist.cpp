#include "Singlylist.h"

void createList(linkedList &L) {
    L.first = Nil;
}

address alokasi(int x) {
    address P = new node;
    P->info.num = x;
    P->next = Nil;
    return P;
}

bool isEmpty(linkedList L) {
    return (L.first == Nil);
}

void insertFirst(linkedList &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void insertLast(linkedList &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfter(linkedList &L, address Prec, address P) {
    if (Prec != Nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void printInfo(linkedList L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info.num << " ";
        P = P->next;
    }
    cout << endl;
}
