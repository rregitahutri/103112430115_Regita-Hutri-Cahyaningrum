#include <iostream>
#include <iomanip>
#include "SLLInventory.h"

using namespace std;

float hitungHargaAkhir(Product P) {
    return P.HargaSatuan * (1.0 - (P.DiskonPersen / 100.0));
}

bool isEmpty(List L) {
    return L.head == NULL;
}

void createList(List &L) {
    L.head = NULL;
}

address allocate(Product P) {
    address newNode = new Node;
    if (newNode != NULL) {
        newNode->info = P;
        newNode->next = NULL;
    }
    return newNode;
}

void deallocate(address p) {
    delete p;
}

void insertFirst(List &L, Product P) {
    address newNode = allocate(P);
    if (newNode != NULL) {
        newNode->next = L.head;
        L.head = newNode;
    }
}

void insertLast(List &L, Product P) {
    address newNode = allocate(P);
    if (newNode != NULL) {
        if (isEmpty(L)) {
            insertFirst(L, P);
        } else {
            address temp = L.head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void insertAfter(List &L, address Q, Product P) {
    if (Q != NULL) {
        address newNode = allocate(P);
        if (newNode != NULL) {
            newNode->next = Q->next;
            Q->next = newNode;
        }
    }
}

void deleteFirst(List &L, Product &P) {
    if (!isEmpty(L)) {
        address temp = L.head;
        P = temp->info;
        L.head = L.head->next;
        deallocate(temp);
    }
}

void deleteLast(List &L, Product &P) {
    if (!isEmpty(L)) {
        if (L.head->next == NULL) {
            deleteFirst(L, P);
        } else {
            address prev = NULL;
            address curr = L.head;
            while (curr->next != NULL) {
                prev = curr;
                curr = curr->next;
            }
            P = curr->info;
            prev->next = NULL;
            deallocate(curr);
        }
    }
}

void deleteAfter(List &L, address Q, Product &P) {
    if (Q != NULL && Q->next != NULL) {
        address temp = Q->next;
        P = temp->info;
        Q->next = temp->next;
        deallocate(temp);
    }
}

void updateAtPosition(List &L, int posisi, Product dataBaru) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
        return;
    }
    address temp = L.head;
    int counter = 1;
    bool found = false;

    while (temp != NULL) {
        if (counter == posisi) {
            temp->info = dataBaru;
            found = true;
            break;
        }
        temp = temp->next;
        counter++;
    }
    if (found) cout << "Data posisi " << posisi << " berhasil diupdate." << endl;
    else cout << "Posisi " << posisi << " tidak ditemukan." << endl;
}

void viewList(List L) {
    cout << "\n====== DAFTAR PRODUK ======" << endl;
    if (isEmpty(L)) {
        cout << "List Kosong." << endl;
        return;
    }
    address temp = L.head;
    int i = 1;
    while (temp != NULL) {
        float finalPrice = hitungHargaAkhir(temp->info);
        cout << i << ". Nama: " << temp->info.Nama << endl
             << " SKU: " << temp->info.SKU << endl
             << " Jml: " << temp->info.Jumlah << endl
             << " Harga: " << temp->info.HargaSatuan << endl
             << " Diskon: " << temp->info.DiskonPersen << "%" << endl
             << " HargaAkhir: " << finalPrice << endl;
        temp = temp->next;
        i++;
        cout << "-----------------------------" << endl;
    }
}

void searchByFinalPriceRange(List L, float minPrice, float maxPrice) {
    cout << "\n=== SEARCH RANGE (" << minPrice << " - " << maxPrice << ") ===" << endl;
    if (isEmpty(L)) { 
        cout << "List Kosong." << endl; return; 
    }
    address temp = L.head;
    int i = 1;
    bool found = false;
    while (temp != NULL) {
        float finalPrice = hitungHargaAkhir(temp->info);
        if (finalPrice >= minPrice && finalPrice <= maxPrice) {
            cout << "Posisi " << i << ": " << temp->info.Nama << endl
                 << "HargaAkhir: " << finalPrice << endl;
            found = true;
        }
        temp = temp->next;
        i++;
    }
    if (!found) cout << "Tidak ada produk dalam rentang harga tersebut." << endl;
}

//Bagian B
void MaxHargaAkhir(List L) {
    cout << "\n=== PRODUK HARGA AKHIR TERTINGGI ===" << endl;
    if (isEmpty(L)) return;

    float maxVal = -1.0;
    address temp = L.head;
    while (temp != NULL) {
        float currentPrice = hitungHargaAkhir(temp->info);
        if (currentPrice > maxVal) maxVal = currentPrice;
        temp = temp->next;
    }

    temp = L.head;
    int i = 1;
    while (temp != NULL) {
        float currentPrice = hitungHargaAkhir(temp->info);
        if (currentPrice == maxVal) {
            cout << "Posisi " << i << ": "
                 << temp->info.Nama << endl
                 << "HargaAkhir: " << maxVal << endl;
        }
        temp = temp->next;
        i++;
    }
}