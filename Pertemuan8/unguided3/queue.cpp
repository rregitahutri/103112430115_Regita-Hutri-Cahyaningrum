#include "queue.h"
#include <iostream>
using namespace std;

bool isEmptyQueue(queue Q){
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(queue Q){
    return (Q.tail + 1) % MAKSIMAL == Q.head;
}

void CreateQueue(queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

void enqueue(queue &Q, int x){
    if(isFullQueue(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmptyQueue(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAKSIMAL;
        }
        Q.info[Q.tail] = x;
    }
}
void dequeue(queue &Q){
    if(isEmptyQueue(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(Q.head == Q.tail){ 
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAKSIMAL; 
        }
    }
}

void printInfo(queue Q){
    cout << Q.head << " - " << Q.tail << " | ";

    if(isEmptyQueue(Q)){
        cout << "empty queue" << endl;
        return;
    }

    int i = Q.head;
    while (true) {
        cout << Q.info[i];

        if (i == Q.tail) break;

        cout << " ";
        i = (i + 1) % MAKSIMAL;
    }

    cout << endl;
}
