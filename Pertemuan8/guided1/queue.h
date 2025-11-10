#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct Queue {
    Node* head;
    Node* tail;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enQueue(Queue &Q, const string &nama);
void deQueue(Queue &Q);
void viewQueue(Queue Q);
void clearQueue(Queue &Q);

#endif