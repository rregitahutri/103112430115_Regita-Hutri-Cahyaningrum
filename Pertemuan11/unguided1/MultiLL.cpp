#include "MultiLL.h"
#include <iostream>
#include <string>
using namespace std;

// isEmpty & create list
bool isEmptyParent(listParent LParent){
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild LChild){
    return (LChild.first == NULL);
}

void createListParent(listParent &LParent){
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild){
    LChild.first = NULL;
    LChild.last = NULL;
}

// Alokasi & Dealokasi
NodeParent allocNodeParent(string idGol, string namaGol){
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight){
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void deallocNodeChild(NodeChild &C){
    if(C != NULL){
        C->next = NULL;
        C->prev = NULL;
        delete C;
        C = NULL;
    }
}

void deallocNodeParent(NodeParent &P){
    if(P != NULL){
        P->next = NULL;
        P->prev = NULL;
        delete P;
        P = NULL;
    }
}

// Operasi Parent
void insertFirstParent(listParent &L, NodeParent P){
    if(isEmptyParent(L)){
        L.first = L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastParent(listParent &L, NodeParent P){
    if(isEmptyParent(L)){
        L.first = L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void deleteFirstParent(listParent &L){
    if(isEmptyParent(L)) return;

    NodeParent del = L.first;

    if(L.first == L.last){
        L.first = L.last = NULL;
    } else {
        L.first = del->next;
        L.first->prev = NULL;
        del->next = NULL;
    }

    deleteListChild(del->L_Child);
    deallocNodeParent(del);
}

void deleteAfterParent(listParent &L, NodeParent Prev){
    if(Prev == NULL || Prev->next == NULL) return;

    NodeParent del = Prev->next;

    Prev->next = del->next;
    if(del->next != NULL){
        del->next->prev = Prev;
    } else {
        L.last = Prev;
    }

    del->next = NULL;
    deleteListChild(del->L_Child);
    deallocNodeParent(del);
}

// Operasi Child
void insertFirstChild(listChild &L, NodeChild C){
    if(isEmptyChild(L)){
        L.first = L.last = C;
    } else {
        C->next = L.first;
        L.first->prev = C;
        L.first = C;
    }
}

void insertLastChild(listChild &L, NodeChild C){
    if(isEmptyChild(L)){
        L.first = L.last = C;
    } else {
        C->prev = L.last;
        L.last->next = C;
        L.last = C;
    }
}

void deleteFirstChild(listChild &L){
    if(isEmptyChild(L)) return;

    NodeChild del = L.first;

    if(L.first == L.last){
        L.first = L.last = NULL;
    } else {
        L.first = del->next;
        L.first->prev = NULL;
        del->next = NULL;
    }

    deallocNodeChild(del);
}

void deleteAfterChild(listChild &L, NodeChild Prev){
    if(Prev == NULL || Prev->next == NULL) return;

    NodeChild del = Prev->next;

    Prev->next = del->next;
    if(del->next != NULL){
        del->next->prev = Prev;
    } else {
        L.last = Prev;
    }

    del->next = NULL;
    deallocNodeChild(del);
}

// Hapus seluruh child
void deleteListChild(listChild &L){
    while(!isEmptyChild(L)){
        deleteFirstChild(L);
    }
}

// Print Struktur MLL
void printMLLStructure(listParent &L){
    if(isEmptyParent(L)){
        cout << "List parent kosong.\n";
        return;
    }

    NodeParent P = L.first;
    int i = 1;

    while(P != NULL){
        cout << "\n=== Parent " << i << " ===\n";
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        NodeChild C = P->L_Child.first;
        int j = 1;

        if(C == NULL){
            cout << "  (Tidak ada child)\n";
        } else {
            while(C != NULL){
                cout << "  - Child " << j << endl;
                cout << "       ID Hewan : " << C->isidata.idHewan << endl;
                cout << "       Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "       Habitat : " << C->isidata.habitat << endl;
                cout << "       Ekor : " << (C->isidata.ekor ? "1" : "0") << endl;
                cout << "       Bobot : " << C->isidata.bobot << endl;
                C = C->next;
                j++;
            }
        }

        P = P->next;
        i++;
    }
}