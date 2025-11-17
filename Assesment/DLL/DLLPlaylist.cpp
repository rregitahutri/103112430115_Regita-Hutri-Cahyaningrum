#include <iostream>
#include <iomanip>
#include "DLLPlaylist.h"

using namespace std;

float getPopularityScore(Song S) {
    return (0.8 * S.PlayCount) + (20.0 * S.Rating);
}

address getAddressAt(List L, int pos) {
    if (isEmpty(L)) return NULL;
    address temp = L.head;
    int i = 1;
    while (temp != NULL && i < pos) {
        temp = temp->next;
        i++;
    }
    return temp;
}

bool isEmpty(List L) {
    return (L.head == NULL && L.tail == NULL);
}

void createList(List &L) {
    L.head = NULL;
    L.tail = NULL;
}

address allocate(Song S) {
    address newNode = new Node;
    if (newNode != NULL) {
        newNode->info = S;
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    return newNode;
}

void deallocate(address P) {
    delete P;
}

void insertFirst(List &L, Song S) {
    address newNode = allocate(S);
    if (newNode != NULL) {
        if (isEmpty(L)) {
            L.head = newNode;
            L.tail = newNode;
        } else {
            newNode->next = L.head;
            L.head->prev = newNode;
            L.head = newNode;
        }
    }
}

void insertLast(List &L, Song S) {
    address newNode = allocate(S);
    if (newNode != NULL) {
        if (isEmpty(L)) {
            insertFirst(L, S);
        } else {
            newNode->prev = L.tail;
            L.tail->next = newNode;
            L.tail = newNode;
        }
    }
}

void insertAfter(List &L, address Q, Song S) {
    if (Q != NULL) {
        if (Q == L.tail) {
            insertLast(L, S);
        } else {
            address newNode = allocate(S);
            if (newNode != NULL) {
                newNode->next = Q->next;
                newNode->prev = Q;
                Q->next->prev = newNode;
                Q->next = newNode;
            }
        }
    }
}

void insertBefore(List &L, address Q, Song S) {
    if (Q != NULL) {
        if (Q == L.head) {
            insertFirst(L, S);
        } else {
            address newNode = allocate(S);
            if (newNode != NULL) {
                newNode->prev = Q->prev;
                newNode->next = Q;
                Q->prev->next = newNode;
                Q->prev = newNode;
            }
        }
    }
}

void deleteFirst(List &L, Song &S) {
    if (!isEmpty(L)) {
        address temp = L.head;
        S = temp->info;
        if (L.head == L.tail) {
            L.head = NULL;
            L.tail = NULL;
        } else {
            L.head = L.head->next;
            L.head->prev = NULL;
        }
        deallocate(temp);
    }
}

void deleteLast(List &L, Song &S) {
    if (!isEmpty(L)) {
        address temp = L.tail;
        S = temp->info;
        if (L.head == L.tail) {
            deleteFirst(L, S);
        } else {
            L.tail = L.tail->prev;
            L.tail->next = NULL;
            deallocate(temp);
        }
    }
}

void deleteAfter(List &L, address Q, Song &S) {
    if (Q != NULL && Q->next != NULL) {
        address temp = Q->next;
        S = temp->info;
        if (temp == L.tail) {
            deleteLast(L, S);
        } else {
            Q->next = temp->next;
            temp->next->prev = Q;
            deallocate(temp);
        }
    }
}

void deleteBefore(List &L, address Q, Song &S) {
    if (Q != NULL && Q->prev != NULL) {
        address temp = Q->prev;
        S = temp->info;
        if (temp == L.head) {
            deleteFirst(L, S);
        } else {
            temp->prev->next = Q;
            Q->prev = temp->prev;
            deallocate(temp);
        }
    } else {
        cout << "Tidak ada node sebelum posisi ini." << endl;
    }
}

void updateAtPosition(List &L, int posisi, Song dataBaru) {
    address target = getAddressAt(L, posisi);
    if (target != NULL) {
        target->info = dataBaru;
        cout << "Update posisi " << posisi << " berhasil." << endl;
    } else {
        cout << "Posisi " << posisi << " tidak ditemukan." << endl;
    }
}

void updateBefore(List &L, address Q, Song dataBaru) {
    if (Q != NULL && Q->prev != NULL) {
        Q->prev->info = dataBaru;
        cout << "Update Before berhasil." << endl;
    } else {
        cout << "Gagal Update Before." << endl;
    }
}

void viewList(List L) {
    cout << "\n--- PLAYLIST LAGU ---" << endl;
    if (isEmpty(L)) {
        cout << "Playlist Kosong." << endl;
        return;
    }
    address temp = L.head;
    int i = 1;
    while (temp != NULL) {
        float popScore = getPopularityScore(temp->info);
        cout << i << ". " << temp->info.Title 
             << " | " << temp->info.Artist
             << " | Play: " << temp->info.PlayCount
             << " | Rate: " << temp->info.Rating
             << " | PopScore: " << fixed << setprecision(1) << popScore << endl;
        temp = temp->next;
        i++;
    }
    cout << "---------------------" << endl;
}

void searchByPopularityRange(List L, float minScore, float maxScore) {
    cout << "\n--- SEARCH (" << minScore << " - " << maxScore << ") ---" << endl;
    if (isEmpty(L)) { cout << "List Kosong." << endl; return; }
    
    address temp = L.head;
    int i = 1;
    bool found = false;
    while (temp != NULL) {
        float score = getPopularityScore(temp->info);
        if (score >= minScore && score <= maxScore) {
            cout << "Posisi " << i << ": " << temp->info.Title 
                 << " (" << score << ")" << endl;
            found = true;
        }
        temp = temp->next;
        i++;
    }
    if (!found) cout << "Tidak ada lagu dalam rentang tersebut." << endl;
}