#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H

#include <string>
using namespace std;

struct Song {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating; // Skala 0.0 - 5.0
};

typedef struct Node* address;

struct Node {
    Song info;
    address prev;
    address next;
};

struct List {
    address head;
    address tail;
};

// Deklarasi Fungsi Helper (Rumus dipindah ke .cpp)
float getPopularityScore(Song S);
address getAddressAt(List L, int pos);

// Deklarasi Fungsi DLL
bool isEmpty(List L);
void createList(List &L);
address allocate(Song S);
void deallocate(address P);

void insertFirst(List &L, Song S);
void insertLast(List &L, Song S);
void insertAfter(List &L, address Q, Song S);
void insertBefore(List &L, address Q, Song S);

void deleteFirst(List &L, Song &S);
void deleteLast(List &L, Song &S);
void deleteAfter(List &L, address Q, Song &S);
void deleteBefore(List &L, address Q, Song &S);

void updateAtPosition(List &L, int posisi, Song dataBaru);
void updateBefore(List &L, address Q, Song dataBaru);
void viewList(List L);
void searchByPopularityRange(List L, float minScore, float maxScore);

#endif