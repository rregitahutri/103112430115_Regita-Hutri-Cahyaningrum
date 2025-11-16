#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue {
    int info[MAKSIMAL];
    int head;
    int tail;
};

void CreateQueue(queue &Q);
bool isEmptyQueue(queue Q); //terbentuk queue dengan head = -1 dan tail = -1
bool isFullQueue(queue Q);
void enqueue(queue &Q, int x);
void dequeue(queue &Q);
void printInfo(queue Q);

#endif