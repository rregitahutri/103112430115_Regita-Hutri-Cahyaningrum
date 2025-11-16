#include "queue.h"
#include <iostream>
using namespace std;

bool isEmptyQueue(queue Q){
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(queue Q){
    return (Q.tail == MAKSIMAL - 1);
}

void CreateQueue(queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

void enqueue(queue &Q, int x){
    if(isFullQueue(Q)){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmptyQueue(Q)){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

void dequeue(queue &Q){
    if(isEmptyQueue(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        Q.head++;
        if(Q.head > Q.tail){ 
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

void printInfo(queue Q){
    cout << Q.head << " - " << Q.tail << " | ";

    if(isEmptyQueue(Q)){
            cout << "empty queue" << endl;
        } else {
            for(int i = Q.head; i <= Q.tail; i++){
                cout << Q.info[i];
                if(i < Q.tail) cout << " ";
            }
        cout << endl;
    }
}