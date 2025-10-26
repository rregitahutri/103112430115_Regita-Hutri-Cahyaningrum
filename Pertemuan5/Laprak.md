# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">Regita Hutri Cahyaningrum - 103112430115</p>

## Dasar Teori
Struktur data linked list merupakan salah satu bentuk struktur data dinamis yang digunakan untuk menyimpan sekumpulan data yang saling terhubung melalui pointer. Setiap elemen pada linked list disebut node, yang terdiri dari dua bagian utama yaitu data dan pointer penunjuk ke node berikutnya. Kelebihan utama dari linked list adalah kemampuannya dalam melakukan manipulasi data secara fleksibel, seperti menambah, menghapus, maupun memperbarui (update) elemen tanpa perlu menggeser elemen lainnya seperti pada array [1].

Pada single linked list, setiap node hanya memiliki satu pointer yang menunjuk ke node berikutnya, sehingga akses data bersifat searah dari awal hingga akhir. Operasi seperti insert, delete, dan update sering digunakan untuk mengelola data dalam sistem yang membutuhkan perubahan dinamis, misalnya pada pengelolaan data mahasiswa, antrian, dan basis data sederhana [2]. Dalam proses update, pointer tidak perlu diubah selama struktur urutan node tetap sama — hanya nilai data di node tertentu yang diperbarui, menjadikan single linked list efisien dalam perubahan isi data [3].

Selain itu, linked list juga digunakan untuk meningkatkan efisiensi memori karena alokasi ruang dilakukan secara dinamis menggunakan pointer. Hal ini menjadikan linked list unggul dibanding array dalam kasus di mana jumlah data tidak diketahui secara pasti atau sering berubah [4]. Struktur ini juga menjadi dasar dalam pengembangan algoritma yang lebih kompleks seperti stack, queue, maupun representasi graf. Oleh karena itu, pemahaman terhadap operasi dasar seperti insert, delete, dan update pada linked list sangat penting dalam perancangan sistem berbasis data dinamis [1][3].

## Guided 

### 1. Singly Linked List Update

##### Source Code listBuah.h
```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```
##### Source Code listBuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```
##### Source Code main.cpp
```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program di atas merupakan implementasi Singly Linked List dalam bahasa C++ untuk mengelola data buah yang berisi nama, jumlah, dan harga. Struktur data yang digunakan terdiri dari node (penyimpan data dan pointer ke node berikutnya) dan linkedlist (penunjuk ke node pertama). Pada program ini terdapat berbagai operasi dasar linked list, seperti createList untuk membuat list kosong, alokasi dan dealokasi untuk manajemen memori node, serta operasi insert dan delete (menambah dan menghapus node di awal, tengah, atau akhir list). Selain itu, terdapat fitur update untuk mengubah data pada node pertama, terakhir, atau setelah node tertentu, serta searching untuk mencari data berdasarkan nama buah, alamat node, atau rentang harga. Fungsi printList menampilkan isi list, nbList menghitung jumlah node, dan deleteList menghapus seluruh isi list. Program utama (main.cpp) mendemonstrasikan semua fungsi tersebut secara berurutan — mulai dari pembuatan list, penambahan data buah, pembaruan data, pencarian, penghapusan sebagian maupun seluruh node, hingga menampilkan hasil akhir.

## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “ListAngka.h”. Kemudian buatlah implementasi function & procedure tersebut pada file “listAngka.cpp”. Kemudian lakukan hal berikut pada file “main.cpp” sehingga memberikan output sesuai contoh.

##### Source Code listAngka.h
```C++
#ifndef LISTANGKA_H
#define LISTANGKA_H
#define Nil NULL

#include<iostream>
using namespace std;

struct angka{
    int num;
};

typedef angka dataAngka;

typedef struct node *address;

struct node{
    dataAngka isidata;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(int num);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
int nbList(linkedlist List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);

#endif
```
##### Source Code listAngka.cpp
```C++
#include "listAngka.h"
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
}

address alokasi(int num) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.num = num;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah angka " << nodePrev->isidata.num << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << nodeBantu->isidata.num << " - ";
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}
```
##### Source Code main.cpp
```C++
#include "listAngka.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF, nodeAb = Nil;
    createList(List);

    dataAngka dtAngka;

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(List, nodeB);
    insertLast(List, nodeA);
    insertAfter(List, nodeD, nodeB);
    insertFirst(List, nodeC);
    insertLast(List, nodeE);
    insertFirst(List, nodeF);

    cout << "DATA ANGKA AWAL" << endl;
    printList(List);
    // cout << "jumlah node : " << nbList(List) << endl;
    cout << endl << endl;

    delAfter(List, nodeB, nodeC);

    cout << "ISI LIST SETELAH DELETE AFTER" << endl;
    printList(List);
    // cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
### Output Unguided 1 :
![Screenshot Output Unguided 1_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan5/output/Unguided1.png)

Program tersebut merupakan implementasi Singly Linked List dalam bahasa C++ yang berfungsi untuk menyimpan dan mengelola data angka secara dinamis. Setiap elemen list disimpan dalam node yang berisi data (num) dan pointer (next) untuk menunjuk ke node berikutnya. Melalui fungsi-fungsi seperti insertFirst, insertLast, dan insertAfter, program dapat menambahkan node di awal, akhir, atau setelah node tertentu, sedangkan delAfter digunakan untuk menghapus node setelah node yang ditentukan. Pada bagian main.cpp, beberapa node dibuat dan dimasukkan ke dalam list dengan berbagai posisi, kemudian salah satu node dihapus menggunakan delAfter. Hasilnya, program menampilkan isi list sebelum dan sesudah penghapusan untuk menunjukkan perubahan struktur data secara dinamis.

### 1a. Buatlah procedure updateFirst, updateLast, dan updateAfter.
### Kemudian pada “main.cpp” lakukanlah :
### ➢ Update data 40 menjadi 50
### ➢ Update data 8 menjadi 29
### ➢ Update data 33 menjadi 45
### ➢ Update data 18 menjadi 20
### ➢ Tampilkan seluruh list setelah diupdate

##### Source Code listAngka.h
```C++
#ifndef LISTANGKA_H
#define LISTANGKA_H
#define Nil NULL

#include<iostream>
using namespace std;

struct angka{
    int num;
};

typedef angka dataAngka;

typedef struct node *address;

struct node{
    dataAngka isidata;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(int num);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
int nbList(linkedlist List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

#endif
```
##### Source Code listAngka.cpp
```C++
#include "listAngka.h"
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
}

address alokasi(int num) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.num = num;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah angka " << nodePrev->isidata.num << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << nodeBantu->isidata.num << " - ";
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//update
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Masukkan angka : ";
        cin >> List.first->isidata.num;
        cout << endl << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Masukkan angka : ";
        cin >> nodeBantu->isidata.num;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "Masukkan update data node setelah node " << nodePrev->isidata.num << " : " << endl;
            cout << "Masukkan angka : ";
            cin >> nodeBantu->isidata.num;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```
##### Source Code main.cpp
```C++
#include "listAngka.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF, nodeAb = Nil;
    createList(List);

    dataAngka dtAngka;

    nodeA = alokasi(29);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(45);
    nodeF = alokasi(50);

    insertFirst(List, nodeB);
    insertLast(List, nodeA);
    insertAfter(List, nodeD, nodeB);
    insertFirst(List, nodeC);
    insertLast(List, nodeE);
    insertFirst(List, nodeF);

    printList(List);
    cout << endl;

    updateFirst(List);
    updateAfter(List, nodeD);
    updateLast(List);
    updateAfter(List, nodeF);

    delAfter(List, nodeB, nodeC);

    cout << endl;
    printList(List);
    cout << endl;

    return 0;
}
```
### Output Unguided 1a :

##### Output
![Screenshot Output Unguided 2_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan5/output/Unguided1a.png)

Program ini merupakan pengembangan dari implementasi Singly Linked List dengan penambahan fitur update data pada node. Terdapat tiga prosedur utama, yaitu updateFirst untuk memperbarui data pada node pertama, updateLast untuk memperbarui node terakhir, dan updateAfter untuk mengubah data pada node setelah node tertentu. Pada file main.cpp, beberapa node angka dibuat dan disusun ke dalam list menggunakan fungsi insert. Setelah itu dilakukan proses pembaruan data sesuai instruksi, yaitu mengganti nilai 40 menjadi 50, 8 menjadi 29, 33 menjadi 45, dan 18 menjadi 20. Program kemudian menampilkan seluruh isi list yang telah diperbarui, memperlihatkan bahwa data di dalam linked list dapat dimodifikasi secara dinamis tanpa perlu membuat ulang struktur list.

### 1b. Buatlah procedure SearchByData, SearchByAddress, dan SearchByRange.
### Kemudian pada “main.cpp” lakukanlah :
### ➢ Mencari data nilai 20
### ➢ Mencari data nilai 55
### ➢ Mencari data alamat nodeB
### ➢ Mencari data alamat nodeA
### ➢ Mencari data dengan nilai minimal 40

##### Source Code listAngka.h
```C++
#ifndef LISTANGKA_H
#define LISTANGKA_H
#define Nil NULL

#include<iostream>
using namespace std;

struct angka{
    int num;
};

typedef angka dataAngka;

typedef struct node *address;

struct node{
    dataAngka isidata;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(int num);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
int nbList(linkedlist List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

void FindNodeByData(linkedlist list, int data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, int nilaiMin);

#endif
```
##### Source Code listAngka.cpp
```C++
#include "listAngka.h"
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
}

address alokasi(int num) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.num = num;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah angka " << nodePrev->isidata.num << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << nodeBantu->isidata.num << " - ";
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//update
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Masukkan angka : ";
        cin >> List.first->isidata.num;
        cout << endl << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Masukkan angka : ";
        cin >> nodeBantu->isidata.num;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "Masukkan update data node setelah node " << nodePrev->isidata.num << " : " << endl;
            cout << "Masukkan angka : ";
            cin >> nodeBantu->isidata.num;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void FindNodeByData(linkedlist list, int data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.num == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByRange(linkedlist list, int nilaiMin) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Data diatas nilai " << nilaiMin << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float cariAngka = nodeBantu->isidata.num;
            if(cariAngka >= nilaiMin) {
                cout << "Data ditemukan pada posisi ke-" << posisi << ", nilai : " << nodeBantu->isidata.num << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```
##### Source Code main.cpp
```C++
#include "listAngka.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF, nodeAb = Nil;
    createList(List);

    dataAngka dtAngka;

    nodeA = alokasi(29);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(45);
    nodeF = alokasi(50);

    insertFirst(List, nodeB);
    insertLast(List, nodeA);
    insertAfter(List, nodeD, nodeB);
    insertFirst(List, nodeC);
    insertLast(List, nodeE);
    insertFirst(List, nodeF);

    printList(List);
    cout << endl;

    updateFirst(List);
    updateAfter(List, nodeD);
    updateLast(List);
    updateAfter(List, nodeF);

    delAfter(List, nodeB, nodeC);

    cout << endl;
    printList(List);
    cout << endl;

    FindNodeByData(List, 20);
    FindNodeByData(List, 55);
    FindNodeByAddress(List, nodeB);
    FindNodeByAddress(List, nodeA);
    FindNodeByRange(List, 40);

    return 0;
}
```
### Output Unguided 1b :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan5/output/Unguided1b.png)

Program di atas merupakan implementasi linked list satu arah menggunakan bahasa C++. Struktur node menyimpan data berupa angka dan penunjuk ke node berikutnya. Berbagai fungsi disediakan untuk mengelola list, seperti menambah data di awal, tengah, dan akhir (insertFirst, insertAfter, insertLast), menghapus node tertentu (delAfter), serta menampilkan isi list (printList).

Selain itu, program juga memiliki fitur pencarian data menggunakan tiga prosedur utama: FindNodeByData untuk mencari berdasarkan nilai, FindNodeByAddress untuk mencari berdasarkan alamat memori node, dan FindNodeByRange untuk menampilkan semua data yang lebih besar atau sama dengan nilai tertentu. Pada fungsi main(), beberapa node dibuat, dimasukkan ke dalam list, kemudian dilakukan proses update, penghapusan, serta pencarian sesuai instruksi.

### 1c. Lakukanlah operasi aritmetika penjumlahan, pengurangan, dan perkalian terhadap semua data yang ada didalam list tersebut! Untuk penjumlahan nilai awal adalah 0, untuk pengurangan nilai awal adalah nilai node pertama (first), untuk perkalian nilai awal adalah 1.

##### Source Code listAngka.h
```C++
#ifndef LISTANGKA_H
#define LISTANGKA_H
#define Nil NULL

#include<iostream>
using namespace std;

struct angka{
    int num;
};

typedef angka dataAngka;

typedef struct node *address;

struct node{
    dataAngka isidata;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(int num);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
int nbList(linkedlist List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

void FindNodeByData(linkedlist list, int data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, int nilaiMin);

int sumList(linkedlist List);
int subList(linkedlist List);
int multipleList(linkedlist List);

#endif
```
##### Source Code listAngka.cpp
```C++
#include "listAngka.h"
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
}

address alokasi(int num) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.num = num;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah angka " << nodePrev->isidata.num << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << nodeBantu->isidata.num << " - ";
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//update
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Masukkan angka : ";
        cin >> List.first->isidata.num;
        cout << endl << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Masukkan angka : ";
        cin >> nodeBantu->isidata.num;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "Masukkan update data node setelah node " << nodePrev->isidata.num << " : " << endl;
            cout << "Masukkan angka : ";
            cin >> nodeBantu->isidata.num;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void FindNodeByData(linkedlist list, int data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.num == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByRange(linkedlist list, int nilaiMin) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Data diatas nilai " << nilaiMin << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float cariAngka = nodeBantu->isidata.num;
            if(cariAngka >= nilaiMin) {
                cout << "Data ditemukan pada posisi ke-" << posisi << ", nilai : " << nodeBantu->isidata.num << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}

int sumList(linkedlist List) {
    int total = 0;
    address p = List.first;
    while (p != Nil) {
        total = total + p->isidata.num;
        p = p->next;
    }
    return total;
}

int subList(linkedlist List) {
    if (isEmpty(List)) {
        return 0;
    } else {
        address p = List.first;
        int total = 0;
        while (p != Nil) {
            total += p->isidata.num;
            p = p->next;
        }
        p = List.first;
        int hasil = p->isidata.num - total;

        return hasil;
    }
}


int multipleList(linkedlist List) {
    if (isEmpty(List)) {
        return 0;
    } else {
        int total = 1;
        address p = List.first;
        while (p != Nil) {
            total = total * p->isidata.num;
            p = p->next;
        }
        return total;
    }
}
```
##### Source Code main.cpp
```C++
#include "listAngka.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF, nodeAb = Nil;
    createList(List);

    dataAngka dtAngka;

    nodeA = alokasi(29);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(45);
    nodeF = alokasi(50);

    insertFirst(List, nodeB);
    insertLast(List, nodeA);
    insertAfter(List, nodeD, nodeB);
    insertFirst(List, nodeC);
    insertLast(List, nodeE);
    insertFirst(List, nodeF);

    printList(List);
    cout << endl;

    updateFirst(List);
    updateAfter(List, nodeD);
    updateLast(List);
    updateAfter(List, nodeF);

    delAfter(List, nodeB, nodeC);

    cout << endl;
    printList(List);
    cout << endl;

    FindNodeByData(List, 20);
    FindNodeByData(List, 55);
    FindNodeByAddress(List, nodeB);
    FindNodeByAddress(List, nodeA);
    FindNodeByRange(List, 40);

    cout << "Total penjumlahan : " << sumList(List) << endl;
    cout << "Total pengurangan : " << subList(List) << endl;
    cout << "Total perkalian   : " << multipleList(List) << endl;

    return 0;
}
```
### Output Unguided 1c :

##### Output
![Screenshot Output Unguided 3_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan5/output/Unguided1c.png)

Program di atas merupakan implementasi struktur data linked list dalam bahasa C++ yang menyimpan data bertipe integer. Setiap elemen list disimpan dalam node yang berisi nilai (num) dan pointer next untuk menunjuk node berikutnya. Fungsi-fungsi dasar seperti createList, alokasi, insertFirst, insertLast, insertAfter, delAfter, dan printList digunakan untuk mengelola penambahan, penghapusan, serta penampilan isi list. Selain itu, terdapat fungsi-fungsi pencarian (FindNodeByData, FindNodeByAddress, dan FindNodeByRange) untuk menemukan node berdasarkan data, alamat, atau nilai tertentu.
Fungsi aritmetika sumList, subList, dan multipleList digunakan untuk melakukan operasi matematika terhadap semua elemen dalam list. Pada sumList, semua data dijumlahkan dengan nilai awal 0; pada subList, operasi dimulai dari node pertama lalu dikurangi dengan total seluruh data dalam list; dan pada multipleList, semua data dikalikan dengan nilai awal 1. Hasil operasi tersebut kemudian ditampilkan di fungsi main() sebagai total penjumlahan, pengurangan, dan perkalian data dalam list.

## Kesimpulan
Kesimpulannya, singly linked list merupakan struktur data dinamis yang efisien untuk menyimpan dan memanipulasi data secara fleksibel, termasuk proses update tanpa perlu menggeser elemen lain. Proses update dilakukan dengan mengganti nilai pada node tertentu tanpa mengubah struktur pointer, sehingga efisien dalam penggunaan memori dan waktu. Dengan fitur ini, singly linked list sangat cocok digunakan dalam sistem yang membutuhkan perubahan data secara terus-menerus, seperti pengelolaan data mahasiswa atau aplikasi berbasis antrian.

## Referensi
[1] Mbejo, Maria T., et al. (2025). Analisis Struktur Data Linked List Dalam Pengolahan Data Mahasiswa. Diakses melalui https://rcf-indonesia.org/jurnal/index.php/jsit/article/view/591/418

<br>[2] Wijoyo, Agung, et al. (2024). Perbandingan Struktur Linked List dan Array dalam Manajemen Memori. Diakses melalui https://jurnalmahasiswa.com/index.php/jriin/article/view/957/756

<br>[3] International Journal of Computer Science and Mobile Computing (IJCSMC). (2022). Implementation of Single Linked List Data Structure in Dynamic Data Management. Diakses melalui https://ijcsmc.com/docs/papers/July2022/V11I7202208.pdf?

<br>[4] Scribd. (2020). Jurnal Linked List. Diakses melalui https://www.scribd.com/doc/144549239/Jurnal-Linked-List?