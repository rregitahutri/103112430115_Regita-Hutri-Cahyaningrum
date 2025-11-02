# <h1 align="center">Laporan Praktikum Modul 6 - Doubly Linked List (Bagian Pertama)</h1>
<p align="center">Regita Hutri Cahyaningrum - 103112430115</p>

## Dasar Teori
Struktur data merupakan elemen fundamental dalam pengembangan sistem informasi dan perangkat lunak modern. Salah satu struktur data yang penting adalah Doubly Linked List (DLL), yang terdiri dari kumpulan node saling terhubung dua arah melalui pointer “next” dan “prev”. DLL memungkinkan operasi seperti insertion dan deletion dilakukan dengan efisien di berbagai posisi dalam daftar, baik di awal, tengah, maupun akhir list [1]. Kelebihan DLL dibandingkan Single Linked List (SLL) terletak pada kemampuannya melakukan navigasi dua arah, sehingga mempermudah dalam manajemen data yang dinamis [5].

Dalam penelitian lain, struktur data DLL juga dikembangkan untuk mendukung sistem berskala besar yang bersifat multi-threaded. Tantangan utama pada sistem semacam ini adalah menjaga konsistensi data tanpa mengorbankan kinerja akibat penggunaan lock global. Untuk itu, Garg dkk. memperkenalkan konsep advanced doubly-linked list (adlist), yakni versi DLL dengan dukungan sinkronisasi ringan (light-weight locks atau lwlocks), yang memungkinkan beberapa operasi berjalan paralel tanpa mengorbankan konsistensi data [2]. Pendekatan ini terbukti efektif dalam meningkatkan skalabilitas sistem berkas (file system) dengan overhead memori yang kecil.

Lebih lanjut, Doubly Linked List juga diterapkan dalam konteks sistem manajemen data dan algoritma optimisasi. Penggunaan DLL yang efisien dapat membantu mengatur memori, mengoptimalkan traversal data, serta mendukung algoritma berbasis pointer manipulation [3]. Dalam konteks pengajaran dan studi struktur data, pemahaman tentang DLL menjadi dasar penting untuk membangun logika pemrograman dan efisiensi algoritmik yang lebih tinggi. Beberapa penelitian juga menekankan bahwa kompleksitas operasi pada DLL seperti insert dan delete memiliki waktu konstan, yaitu O(1), karena hanya melibatkan perubahan pointer antar node [5].

Selain aspek teoritis, implementasi DLL banyak digunakan dalam aplikasi praktis seperti pengelolaan antrian, simulasi, dan representasi sistem basis data yang membutuhkan manipulasi data dinamis [4]. Integrasi DLL dengan bahasa pemrograman modern seperti C++, Python, dan Java juga memperkuat penggunaannya dalam pengembangan perangkat lunak yang membutuhkan efisiensi tinggi.

## Guided 

### 1. Doubly Linked List untuk Insert dan Update

##### Source Code Doublylist.h
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```

##### Source Code Doublylist.cpp
```C++
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node selanjutnya (next) tidak valid!" << endl;
        }
    }
}
```
##### Source Code main.cpp
```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```
Program di atas merupakan implementasi Doubly Linked List dalam bahasa C++ yang digunakan untuk melakukan operasi insert dan update pada data makanan. Struktur node menyimpan informasi makanan berupa nama, jenis, harga, dan rating, serta memiliki pointer next dan prev untuk menghubungkan setiap node secara dua arah. File header (listMakanan.h) berisi deklarasi struktur data dan fungsi utama seperti insertFirst, insertLast, insertAfter, insertBefore, serta updateFirst, updateLast, updateAfter, dan updateBefore. Implementasinya terdapat pada file listMakanan.cpp, yang menjelaskan cara menambahkan node baru di berbagai posisi dalam list dan memperbarui isi node yang sudah ada. Pada file main.cpp, program utama membuat beberapa node makanan, menambahkannya ke dalam list dengan berbagai metode insert, menampilkan isi list, lalu memperbarui data node tertentu untuk menguji fungsi update. Melalui program ini, pengguna dapat memahami cara pengelolaan data secara dinamis menggunakan Doubly Linked List, khususnya dalam hal penambahan dan pembaruan elemen.

### 2. Doubly Linked List untuk Searching dan Delete

##### Source Code Doublylist.h
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif
```
##### Source Code Doublylist.cpp
```C++
#include "listMakanan.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// SEARCHING
void findByName(linkedlist List, string nama){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.nama == nama){
            cout << "Ditemukan (berdasarkan nama):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan nama \"" << nama << "\" tidak ditemukan." << endl;
}

void findByJenis(linkedlist List, string jenis){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.jenis == jenis){
            cout << "Ditemukan (berdasarkan jenis):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan jenis \"" << jenis << "\" tidak ditemukan." << endl;
}

void findByMinRating(linkedlist List, float minRating){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.rating >= minRating){
            cout << "Ditemukan (rating >= " << minRating << "):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Tidak ada data dengan rating >= " << minRating << "." << endl;
}

// DELETE
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
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi pertama." << endl;
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
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi terakhir." << endl;
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
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus setelah node " << Prev->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteBefore(linkedlist &List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(nodeNext == Nil || nodeNext->prev == Nil){
        cout << "Node setelahnya (nodeNext) tidak valid atau tidak ada node sebelumnya!" << endl;
        return;
    }
    if(nodeNext->prev == List.first){
        deleteFirst(List);
        return;
    }
    address pDel = nodeNext->prev;
    nodeNext->prev = pDel->prev;
    pDel->prev->next = nodeNext;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus sebelum node " << nodeNext->isidata.nama << "." << endl;
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
        cout << "Node " << target->isidata.nama << " berhasil dihapus dari tengah list." << endl;
        dealokasi(target);
    }
}

void deleteByName(linkedlist &List, string nama){
    if(isEmpty(List)){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }

    address target = List.first;
    while(target != Nil && target->isidata.nama != nama){
        target = target->next;
    }
    if(target == Nil){
        cout << "Node dengan nama \"" << nama << "\" tidak ditemukan." << endl;
        return;
    }

    deleteNode(List, target);
    cout << "Node dengan nama \"" << nama << "\" telah dihapus dan didealokasi." << endl;
}
```
##### Source Code main.cpp
```C++
	#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeA);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    cout << endl;

    findByName(List, "Nasgor");

    deleteByName(List, "Nasgor");
    deleteFirst(List);
    deleteBefore(List, nodeE);

    cout << endl << "--- Isi List Setelah Delete ---" << endl;
    printList(List);

    return 0;
}
```
Program di atas merupakan implementasi Doubly Linked List dalam bahasa C++ yang digunakan untuk mengelola data makanan dengan fitur lengkap seperti insert, update, searching, dan delete. Struktur data node menyimpan informasi makanan berupa nama, jenis, harga, dan rating, serta dua pointer (next dan prev) yang menghubungkan node satu dengan lainnya secara dua arah. File header (listMakanan.h) berisi deklarasi struktur dan fungsi, sedangkan file implementasi (listMakanan.cpp) memuat definisi logika setiap operasi. Program utama (main.cpp) berfungsi untuk menguji semua fungsi tersebut, mulai dari pembuatan list, penambahan node di berbagai posisi (awal, akhir, setelah, sebelum node tertentu), pengubahan data pada node tertentu, pencarian data berdasarkan nama, jenis, atau rating minimum, hingga penghapusan node baik berdasarkan posisi maupun nama. Melalui program ini, pengguna dapat mempelajari cara kerja manipulasi data menggunakan Doubly Linked List secara dinamis dan efisien.

## Unguided 

### 1. Buatlah ADT Doubly Linked list sebagai berikut di dalam file “Doublylist.h”. Buatlah implementasi ADT Doubly Linked list pada file “Doublylist.cpp” dan coba hasil implementasi ADT pada file “main.cpp”.

##### Source Code Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct kendaraan{
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan dataKendaraan;

typedef struct node *address;

struct node{
    dataKendaraan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
bool isNopolExist(linkedlist L, string nopol);
void createList(linkedlist &List);
address alokasi(string nopol, string warna, int thnBuat);
void dealokasi(address &node);
address inputKendaraan();

void insertLast(linkedlist &List, address nodeBaru);

void printList(linkedlist List);

#endif
```
##### Source Code Doublylist.cpp
```C++
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
```
##### Source Code main.cpp
```C++
#include "Doublylist.h"
#include <iostream>
using namespace std;

int main() {
    linkedlist L;
    createList(L);

    insertLast(L, alokasi("D001", "Merah", 80));
    insertLast(L, alokasi("B123", "Hitam", 2021));
    insertLast(L, alokasi("F909", "Putih", 2025));

    int jumlah;
    cout << endl << "Masukkan jumlah kendaraan baru yang ingin diinput: ";
    cin >> jumlah;

    for (int i = 1; i <= jumlah; i++) {
        string nopol, warna;
        int thn;

        while (true) {
            cout << endl << "Masukkan nomor polisi: ";
            cin >> nopol;

            cout << "Masukkan warna kendaraan: ";
            cin >> warna;
            cout << "Masukkan tahun kendaraan: ";
            cin >> thn;
            
            if (isNopolExist(L, nopol)) {
                cout << "Nomor polisi sudah terdaftar." << endl;
                continue;
            }

            break;
    }

    address nodeBaru = alokasi(nopol, warna, thn);
    insertLast(L, nodeBaru);
}

    cout << endl << "DATA LIST" << endl;
    cout << "------------------------------" << endl;

    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        address p = L.last; 
        while (p != Nil) {
            cout << "No Polisi : " << p->isidata.nopol << endl;
            cout << "Warna     : " << p->isidata.warna << endl;
            cout << "Tahun     : " << p->isidata.thnBuat << endl;
            cout << "------------------------------" << endl;
            p = p->prev;
        }
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan6/output/Soal1(1).png)

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan6/output/Soal1(2).png)

Kode di atas merupakan implementasi Abstract Data Type (ADT) Doubly Linked List dalam bahasa C++ yang digunakan untuk mengelola data kendaraan dengan atribut nomor polisi, warna, dan tahun pembuatan. Struktur data ini menggunakan dua pointer (next dan prev) pada setiap node sehingga memungkinkan penelusuran data ke arah depan maupun belakang. Pada file Doublylist.h didefinisikan tipe data, struktur node, serta deklarasi fungsi-fungsi utama seperti createList(), alokasi(), insertLast(), isEmpty(), dan printList(). Implementasinya terdapat pada Doublylist.cpp, di mana setiap fungsi menjalankan perannya, misalnya createList() untuk inisialisasi list kosong, alokasi() untuk membuat node baru, insertLast() untuk menambahkan node di akhir list, dan isNopolExist() untuk mengecek apakah nomor polisi sudah terdaftar. Pada main.cpp, program membuat list kendaraan, menambahkan beberapa data awal, memberi kesempatan pengguna menambah data baru, lalu menampilkan seluruh isi list dari belakang ke depan. Secara keseluruhan, kode ini menunjukkan cara kerja penambahan, pengecekan, dan penelusuran data dalam struktur Doubly Linked List secara dinamis dan terstruktur.

### 2. Carilah elemen dengan nomor polisi D001 dengan membuat fungsi baru. fungsi findElm( L : List, x : infotype ) : address

##### Source Code Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct kendaraan{
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan dataKendaraan;

typedef struct node *address;

struct node{
    dataKendaraan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
bool isNopolExist(linkedlist L, string nopol);
void createList(linkedlist &List);
address alokasi(string nopol, string warna, int thnBuat);
void dealokasi(address &node);
address inputKendaraan();

void insertLast(linkedlist &List, address nodeBaru);
void findByNopol(linkedlist List, string nopol);

void printList(linkedlist List);

#endif
```
##### Source Code Doublylist.cpp
```C++
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
```
##### Source Code main.cpp
```C++
#include "Doublylist.h"
#include <iostream>
using namespace std;

int main() {
    linkedlist L;
    createList(L);

    insertLast(L, alokasi("D001", "Merah", 80));
    insertLast(L, alokasi("B123", "Hitam", 2021));
    insertLast(L, alokasi("F909", "Putih", 2025));

    int jumlah;
    cout << endl << "Masukkan jumlah kendaraan baru yang ingin diinput: ";
    cin >> jumlah;

    for (int i = 1; i <= jumlah; i++) {
        string nopol, warna;
        int thn;

        while (true) {
            cout << endl << "Masukkan nomor polisi: ";
            cin >> nopol;

            cout << "Masukkan warna kendaraan: ";
            cin >> warna;
            cout << "Masukkan tahun kendaraan: ";
            cin >> thn;
            
            if (isNopolExist(L, nopol)) {
                cout << "Nomor polisi sudah terdaftar." << endl;
                continue;
            }

            break;
    }

    address nodeBaru = alokasi(nopol, warna, thn);
    insertLast(L, nodeBaru);
}

    cout << endl << "DATA LIST" << endl;
    cout << "------------------------------" << endl;

    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        address p = L.last; 
        while (p != Nil) {
            cout << "No Polisi : " << p->isidata.nopol << endl;
            cout << "Warna     : " << p->isidata.warna << endl;
            cout << "Tahun     : " << p->isidata.thnBuat << endl;
            cout << "------------------------------" << endl;
            p = p->prev;
        }
    }

    string cariNopol;
    cout << endl << "Masukkan nomor polisi yang dicari: ";
    cin >> cariNopol;
    findByNopol(L, cariNopol);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan6/output/Soal2.png)

Kode di atas merupakan implementasi Doubly Linked List dalam bahasa C++ yang digunakan untuk menyimpan, menampilkan, dan mencari data kendaraan berdasarkan nomor polisi. Setiap node menyimpan informasi berupa nomor polisi, warna, dan tahun pembuatan kendaraan, serta memiliki dua pointer (next dan prev) yang menghubungkan antar node secara dua arah. Program menyediakan fungsi-fungsi seperti createList() untuk menginisialisasi list kosong, alokasi() untuk membuat node baru, insertLast() untuk menambahkan node di akhir list, serta printList() untuk menampilkan seluruh isi list. Selain itu, terdapat fungsi findByNopol() untuk menampilkan data kendaraan yang dicari berdasarkan nomor polisi yang dimasukkan pengguna. Untuk mencari elemen dengan nomor polisi D001, dapat ditambahkan fungsi baru bernama findElm(linkedlist L, string x) yang akan menelusuri list dari node pertama hingga terakhir, dan mengembalikan alamat node (address) dari elemen yang memiliki nomor polisi sesuai input; jika tidak ditemukan, fungsi akan mengembalikan Nil. Dengan adanya fungsi ini, program dapat melakukan pencarian data secara efisien dan memungkinkan pengaksesan langsung terhadap node yang ditemukan untuk operasi lanjutan seperti penghapusan atau pembaruan data.

### 3. Hapus elemen dengan nomor polisi D003 dengan procedure delete.
###     - procedure deleteFirst( input/output L : List, P : address )
###     - procedure deleteLast( input/output L : List, P : address )
###     - procedure deleteAfter( input Prec : address, input/output P : address )

##### Source Code Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct kendaraan{
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan dataKendaraan;

typedef struct node *address;

struct node{
    dataKendaraan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
bool isNopolExist(linkedlist L, string nopol);
void createList(linkedlist &List);
address alokasi(string nopol, string warna, int thnBuat);
void dealokasi(address &node);
address inputKendaraan();

void insertLast(linkedlist &List, address nodeBaru);
void findByNopol(linkedlist List, string nopol);

void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);

void deleteByNopol(linkedlist &List, string nopol);
void deleteNode(linkedlist &List, address target);

void printList(linkedlist List);

#endif
```
##### Source Code Doublylist.cpp
```C++
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
```
##### Source Code main.cpp
```C++
#include "Doublylist.h"
#include <iostream>
using namespace std;

int main() {
    linkedlist L;
    createList(L);

    insertLast(L, alokasi("D001", "Merah", 80));
    insertLast(L, alokasi("B123", "Hitam", 2021));
    insertLast(L, alokasi("F909", "Putih", 2025));
    insertLast(L, alokasi("NIKI", "Merah", 80));
    insertLast(L, alokasi("ZEFA", "Hitam", 2021));
    insertLast(L, alokasi("LAUR", "Putih", 2025));

    int jumlah;
    cout << endl << "Masukkan jumlah kendaraan baru yang ingin diinput: ";
    cin >> jumlah;

    for (int i = 1; i <= jumlah; i++) {
        string nopol, warna;
        int thn;

        while (true) {
            cout << endl << "Masukkan nomor polisi: ";
            cin >> nopol;

            cout << "Masukkan warna kendaraan: ";
            cin >> warna;
            cout << "Masukkan tahun kendaraan: ";
            cin >> thn;
            
            if (isNopolExist(L, nopol)) {
                cout << "Nomor polisi sudah terdaftar." << endl;
                continue;
            }

            break;
    }

    address nodeBaru = alokasi(nopol, warna, thn);
    insertLast(L, nodeBaru);
}

    cout << endl << "DATA LIST" << endl;
    cout << "------------------------------" << endl;
    
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        address p = L.last; 
        while (p != Nil) {
            cout << "No Polisi : " << p->isidata.nopol << endl;
            cout << "Warna     : " << p->isidata.warna << endl;
            cout << "Tahun     : " << p->isidata.thnBuat << endl;
            cout << "------------------------------" << endl;
            p = p->prev;
        }
    }
    
    string cariNopol;
    cout << endl << "Masukkan nomor polisi yang dicari: ";
    cin >> cariNopol;
    findByNopol(L, cariNopol);

    deleteFirst(L);
    deleteLast(L);
    deleteAfter(L, L.first);
    
    cout << endl << "DATA LIST" << endl;
    cout << "------------------------------" << endl;
    printList(L);
    
    cout << endl << "Masukkan nomor polisi yang dihapus: ";
    cin >> cariNopol;
    deleteByNopol(L, cariNopol);
    
    cout << endl << "DATA LIST" << endl;
    cout << "------------------------------" << endl;
    printList(L);
    
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan6/output/Soal3.png)

Kode di atas merupakan implementasi struktur data Doubly Linked List dalam bahasa C++ yang digunakan untuk menyimpan, menampilkan, dan menghapus data kendaraan berdasarkan nomor polisi. Setiap node dalam list berisi data berupa nopol, warna, dan thnBuat, serta dua pointer yaitu next dan prev untuk menghubungkan node secara dua arah. Program menyediakan berbagai prosedur penghapusan. deleteFirst untuk menghapus elemen pertama, deleteLast untuk menghapus elemen terakhir, dan deleteAfter untuk menghapus elemen yang berada setelah node tertentu. Selain itu, terdapat juga fungsi deleteByNopol yang menghapus node berdasarkan nomor polisi tertentu dengan mencari node yang sesuai, kemudian memanggil deleteNode untuk menentukan apakah node tersebut dihapus dari awal, akhir, atau tengah list. Dalam fungsi main, program menambahkan beberapa data kendaraan awal, memungkinkan pengguna menambah data baru, menampilkan isi list dari belakang ke depan, melakukan penghapusan menggunakan berbagai metode delete, dan menampilkan hasil akhir list setelah penghapusan dilakukan. Program ini menggambarkan bagaimana operasi dasar insert, search, dan delete diterapkan dalam doubly linked list secara terstruktur.

## Kesimpulan
Berdasarkan hasil praktikum Modul 6 tentang Doubly Linked List (Bagian Pertama), dapat disimpulkan bahwa Doubly Linked List (DLL) adalah struktur data yang setiap elemennya (node) memiliki dua pointer, yaitu next dan prev, yang memungkinkan penelusuran data secara maju maupun mundur. Struktur ini memberikan fleksibilitas tinggi dalam pengelolaan data karena operasi seperti insert, update, search, dan delete dapat dilakukan dengan lebih efisien di berbagai posisi list tanpa perlu pergeseran elemen seperti pada array.

Melalui implementasi berbagai fungsi seperti insertFirst, insertLast, updateAfter, findByNopol, hingga deleteByNopol, mahasiswa dapat memahami cara kerja manajemen memori dinamis menggunakan pointer serta logika manipulasi node secara dua arah. Dengan demikian, Doubly Linked List tidak hanya meningkatkan efisiensi pengolahan data, tetapi juga menjadi dasar penting dalam pengembangan struktur data yang lebih kompleks serta aplikasi yang membutuhkan pengelolaan data secara dinamis dan terstruktur.

## Referensi
[1] International Journal of Computer Science and Mobile Computing. (2022). A Study on the Performance and Implementation of Doubly Linked List in Data Structures. Vol. 11, Issue 7, July 2022. Diakses melalui https://ijcsmc.com/docs/papers/July2022/V11I7202208.pdf

[2] Garg, N., Zhu, E., & Botelho, F. C. (2011). Highly-Concurrent Doubly-Linked Lists. arXiv preprint arXiv:1112.1141. Diakses melalui https://arxiv.org/pdf/1112.1141

[3] B.M.S. College of Engineering. (2023). Data Structures Unit 3: Linked List. Bengaluru: Department of Computer Science and Engineering. Diakses melalui https://bmsce.ac.in/Content/CS/DS-UNIT-3.pdf

[4] MDPI Computers Journal. (2024). Computers — Open Access Journal of Computer Science. Vol. 13, Issue 1, Article 8. Diakses melalui https://www.mdpi.com/2073-431X/13/1/8

[5] Wijoyo, A., Farhan, A., Prayudi, L. A., Fiqih, M., Santoso, R. D., & Arifin, T. (2024). Penggunaan Algoritma Doubly Linked List untuk Insertion dan Deletion. Jurnal Riset Informatika dan Inovasi (JRIIN), Vol. 1, No. 12, Mei 2024, hlm. 1329–1331. Diakses melalui https://jurnalmahasiswa.com/index.php/jriin/article/view/1282/762
