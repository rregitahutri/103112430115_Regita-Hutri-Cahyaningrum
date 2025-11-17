#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H

#include <string>
using namespace std;

const int MAX = 5;

struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang;
    string Tujuan;
};

struct QueueEkspedisi {
    Paket dataPaket[MAX];
    int Head;
    int Tail;
};

bool isEmpty(QueueEkspedisi Q);
bool isFull(QueueEkspedisi Q);
void createQueue(QueueEkspedisi &Q);

void enQueue(QueueEkspedisi &Q, Paket data);
void deQueue(QueueEkspedisi &Q);
void viewQueue(QueueEkspedisi Q);

float TotalBiayaPengiriman(QueueEkspedisi Q);

#endif