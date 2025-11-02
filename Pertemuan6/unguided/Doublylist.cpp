#include "Doublylist.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    return (List.first == Nil);
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nopol, string warna, int thnBuat) {
    address nodeBaru = new node;
    nodeBaru->isidata.nopol = nopol;
    nodeBaru->isidata.warna = warna;
    nodeBaru->isidata.thnBuat = thnBuat;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nopol
         << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "No Polisi : " << nodeBantu->isidata.nopol << endl;
            cout << "Warna     : " << nodeBantu->isidata.warna << endl;
            cout << "Tahun     : " << nodeBantu->isidata.thnBuat << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

address inputKendaraan() {
    string nopol, warna;
    int thn;

    cout << "Masukkan nomor polisi: ";
    cin >> nopol;
    cout << "Masukkan warna kendaraan: ";
    cin >> warna;
    cout << "Masukkan tahun pembuatan: ";
    cin >> thn;

    return alokasi(nopol, warna, thn);
}

bool isNopolExist(linkedlist L, string nopol) {
    address p = L.first;
    while (p != Nil) {
        if (p->isidata.nopol == nopol) {
            return true;
        }
        p = p->next;
    }
    return false;
}

void findByNopol(linkedlist List, string nopol){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.nopol == nopol){
            cout << endl;
            cout << "Nomor polisi : " << p->isidata.nopol << endl;
            cout << "Warna        : " << p->isidata.warna << endl;
            cout << "Tahun        : " << p->isidata.thnBuat << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan nama \"" << nopol << "\" tidak ditemukan." << endl;
}

void deleteFirst(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.first;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.first = pDel->next;
        List.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    cout << endl << "Node " << pDel->isidata.nopol << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Node " << pDel->isidata.nopol << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(linkedlist &List, address Prev){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(Prev == Nil || Prev->next == Nil){
        cout << "Node sebelumnya (Prev) tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    if(Prev->next == List.last){
        deleteLast(List);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nopol << " berhasil dihapus setelah node " << Prev->isidata.nopol << "." << endl;
    dealokasi(pDel);
}

void deleteNode(linkedlist &List, address target){
    if(isEmpty(List) == true || target == Nil){
        cout << "Target tidak valid atau list kosong!" << endl;
        return;
    }
    if(target == List.first){
        deleteFirst(List);
    } else if(target == List.last){
        deleteLast(List);
    } else {
        address L = target->prev;
        address R = target->next;
        L->next = R;
        R->prev = L;
        target->next = Nil;
        target->prev = Nil;
        cout << "Node " << target->isidata.nopol << " berhasil dihapus dari tengah list." << endl;
        dealokasi(target);
    }
}

void deleteByNopol(linkedlist &List, string nopol){
    if(isEmpty(List)){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }

    address target = List.first;
    while(target != Nil && target->isidata.nopol != nopol){
        target = target->next;
    }
    if(target == Nil){
        cout << "Node dengan no polisi \"" << nopol << "\" tidak ditemukan." << endl;
        return;
    }

    deleteNode(List, target);
    cout << "Node dengan no polisi \"" << nopol << "\" telah dihapus dan didealokasi." << endl;
}