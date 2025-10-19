# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)</h1>
<p align="center">Regita Hutri Cahyaningrum - 103112430115</p>

## Dasar Teori
Linked list merupakan salah satu struktur data dinamis yang digunakan untuk menyimpan sekumpulan data secara berurutan menggunakan konsep pointer. Setiap elemen (node) pada linked list terdiri dari dua bagian utama, yaitu data dan pointer yang menunjuk ke node berikutnya. Struktur ini berbeda dengan array yang memiliki ukuran tetap karena linked list memungkinkan alokasi dan dealokasi memori secara dinamis selama program berjalan [1].

Secara umum, linked list terbagi menjadi beberapa jenis, yaitu singly linked list, doubly linked list, dan circular linked list. Pada singly linked list, setiap node hanya memiliki satu pointer yang menunjuk ke elemen berikutnya. Struktur ini sederhana namun efisien dalam operasi penyisipan dan penghapusan data karena tidak memerlukan pergeseran elemen seperti pada array [2]. Operasi dasar pada linked list meliputi pembuatan list (create list), penyisipan (insert), penghapusan (delete), penelusuran (traverse), serta pencarian (search).

Salah satu keunggulan utama dari singly linked list adalah efisiensi dalam manajemen memori, karena ukuran list dapat bertambah atau berkurang secara fleksibel sesuai kebutuhan program [3]. Selain itu, proses penyisipan dan penghapusan node memiliki kompleksitas waktu yang lebih baik dibandingkan array ketika dilakukan di awal atau di tengah list, karena tidak memerlukan pergeseran elemen-elemen lain [4]. Namun demikian, kelemahannya terletak pada akses data yang bersifat sekuensial, di mana untuk mencapai elemen tertentu, program harus menelusuri node dari awal hingga elemen yang dimaksud [5].

Beberapa penelitian berfokus pada optimasi kinerja singly linked list, misalnya dengan menambahkan indexing atau multi-level node access agar pencarian data menjadi lebih cepat [1]. Penelitian lainnya membahas perbandingan efisiensi antara linked list dan array dalam hal penggunaan memori dan waktu eksekusi, di mana linked list terbukti lebih unggul untuk operasi yang memerlukan banyak penyisipan atau penghapusan data [5]. Selain itu, dalam konteks sistem paralel dan memori bersama (shared memory systems), linked list juga dapat diimplementasikan dengan pendekatan lock-free untuk menghindari konflik antar-thread tanpa perlu mekanisme penguncian (mutex), sehingga meningkatkan kinerja sistem [4].

Secara keseluruhan, konsep linked list merupakan dasar penting dalam pemrograman berorientasi objek dan manajemen memori dinamis. Struktur ini banyak digunakan dalam berbagai algoritma dan aplikasi seperti manajemen antrian, tumpukan, tabel hash, serta representasi graf dan pohon. Pemahaman tentang operasi dasar dan kompleksitas linked list menjadi pondasi bagi pengembangan struktur data yang lebih kompleks dan efisien di bidang ilmu komputer [2][3].

## Guided 

### 1. Singly Linked List Insert

##### Source Code list.h
```C++
//Header guard digunakan untuk mencegah header yang sama
//di-include lebih dari sekali dalam satu program
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa
typedef struct node *address; //Mendefinisikan alias sddress sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedList { // ini linked listnya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);

#endif
```
##### Source Code list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
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

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```
##### Source Code main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Program di atas merupakan implementasi singly linked list untuk menyimpan data mahasiswa secara dinamis menggunakan pointer. Struktur linkedList memiliki pointer first sebagai penunjuk elemen pertama, sedangkan setiap node berisi data mahasiswa (nama, nim, umur) dan pointer next untuk menghubungkan node berikutnya. Fungsi createList digunakan untuk membuat list kosong, isEmpty memeriksa apakah list kosong, alokasi membuat node baru, dan dealokasi menghapus node dari memori. Prosedur insertFirst, insertAfter, dan insertLast digunakan untuk menambahkan node baru di awal, setelah node tertentu, dan di akhir list. Dalam fungsi main, lima node mahasiswa dibuat dan dimasukkan ke dalam list menggunakan kombinasi ketiga fungsi tersebut, lalu seluruh data mahasiswa ditampilkan menggunakan printList. Program ini menunjukkan bagaimana operasi dasar seperti pembuatan, penyisipan, dan penelusuran data dilakukan pada struktur data linked list secara efisien dengan memanfaatkan konsep pointer dalam bahasa C++.

### 2. Singly Linked List Delete

##### Source Code list.h
```C++
//Header guard digunakan untuk mencegah header yang sama
//di-include lebih dari sekali dalam satu program
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa
typedef struct node *address; //Mendefinisikan alias sddress sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedList { // ini linked listnya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);

void delFirst(linkedList &List);
void delLast(linkedList &List);
void delAfter(linkedList &List, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);

#endif
```
##### Source Code list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
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
void delFirst(linkedList &List){
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List){
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
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
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedList List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedList &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```
##### Source Code main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

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
Program di atas merupakan implementasi singly linked list untuk menyimpan dan mengelola data mahasiswa yang terdiri dari nama, NIM, dan umur. Struktur data linkedList berisi pointer first yang menunjuk ke node pertama, sedangkan setiap node memiliki data mahasiswa dan pointer next yang menghubungkannya ke node berikutnya. Fungsi-fungsi seperti insertFirst, insertAfter, dan insertLast digunakan untuk menambahkan elemen baru di awal, tengah, atau akhir list, sementara fungsi delFirst, delLast, dan delAfter berfungsi untuk menghapus node sesuai posisi yang diinginkan. Selain itu, terdapat fungsi nbList untuk menghitung jumlah node dan printList untuk menampilkan seluruh isi list ke layar. Pada fungsi main, program membuat lima node mahasiswa dan memasukkannya ke dalam list dengan berbagai posisi menggunakan fungsi insert, kemudian menghapus beberapa node dengan fungsi delete, serta menampilkan hasil list yang telah diperbarui. Terakhir, fungsi deleteList digunakan untuk menghapus seluruh isi list dari memori, sehingga program ini memperlihatkan cara kerja dasar operasi penyisipan, penghapusan, penelusuran, dan pengosongan data pada struktur data linked list secara dinamis menggunakan pointer dalam bahasa C++.

## Unguided 

### 1. Buatlah ADT Singly Linked List sebagai berikut di dalam file “Singlylist.h”. Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp". Kemudian buat program utama didalam file “main.cpp” dengan implementasi yang diberikan.

##### Source Code Singlylist.h
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct angka{
    int num;
};

typedef angka dataAngka;
typedef struct node *address;

struct node{
    dataAngka info;
    address next;
};
struct linkedList {
    address first;
};
  
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(int x);
void dealokasi(address &node);
void printInfo(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);

#endif
```
##### Source Code Singlylist.cpp
```C++
#include "Singlylist.h"

void createList(linkedList &L) {
    L.first = Nil;
}

address alokasi(int x) {
    address P = new node;
    P->info.num = x;
    P->next = Nil;
    return P;
}

bool isEmpty(linkedList L) {
    return (L.first == Nil);
}

void insertFirst(linkedList &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void insertLast(linkedList &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfter(linkedList &L, address Prec, address P) {
    if (Prec != Nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void printInfo(linkedList L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info.num << " ";
        P = P->next;
    }
    cout << endl;
}
```
##### Source Code main.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

int main() {
    linkedList L;
    address P1, P2, P3, P4, P5;
    createList(L);

    P1 = alokasi(0);
    insertFirst(L, P1);

    P2 = alokasi(12);
    insertFirst(L, P2);

    P4 = alokasi(9);
    insertFirst(L, P4);

    P5 = alokasi(2);
    insertLast(L, P5);

    cout << "--- ISI LIST AWAL ---" << endl;
    printInfo(L);

    P3 = alokasi(8);
    insertAfter(L, P2, P3);

    cout << "--- ISI LIST SETELAH INSERT AFTER ---" << endl;
    printInfo(L);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan4/output/Soal1.png)

Program di atas merupakan implementasi Abstract Data Type (ADT) Singly Linked List dalam bahasa pemrograman C++. ADT ini digunakan untuk menyimpan sekumpulan data bertipe integer secara dinamis menggunakan konsep pointer, sehingga ukuran list tidak tetap dan dapat berubah sesuai kebutuhan saat program dijalankan. Pada file Singlylist.h, didefinisikan struktur data yang digunakan, yaitu node yang berisi sebuah data (num) bertipe integer dan pointer next yang menunjuk ke node berikutnya. Selain itu, terdapat struktur linkedList yang memiliki pointer first sebagai penunjuk node pertama dalam list. File header ini juga mendeklarasikan berbagai fungsi dan prosedur penting seperti createList, isEmpty, alokasi, dealokasi, insertFirst, insertLast, insertAfter, dan printInfo yang menjadi operasi dasar dalam pengelolaan linked list. Implementasi dari fungsi-fungsi tersebut terdapat dalam file Singlylist.cpp. Fungsi createList digunakan untuk menginisialisasi list kosong, sedangkan alokasi membuat node baru dan mengisi nilai datanya. Fungsi isEmpty memeriksa apakah list kosong atau tidak, dan fungsi insertFirst, insertLast, serta insertAfter digunakan untuk menambahkan node baru di awal, akhir, atau setelah node tertentu dalam list.

Kemudian, fungsi printInfo menampilkan seluruh isi list ke layar dengan cara menelusuri setiap node secara berurutan dari first hingga Nil. Pada file main.cpp, dilakukan proses implementasi ADT tersebut dengan membuat lima node (P1 sampai P5) yang masing-masing dialokasikan nilai tertentu. Beberapa node dimasukkan ke dalam list menggunakan berbagai metode penyisipan insertFirst untuk menambahkan node di awal list, insertLast untuk menambahkan node di akhir list, dan insertAfter untuk menambahkan node setelah node tertentu. Setelah setiap operasi insert dilakukan, program menampilkan isi list untuk menunjukkan hasil perubahan yang terjadi. Melalui kode ini, pengguna dapat memahami konsep dasar operasi penyisipan data dalam singly linked list, cara kerja pointer dalam menghubungkan node secara berantai, serta bagaimana list dapat dikelola secara dinamis tanpa perlu menentukan ukuran array di awal, sehingga sangat efisien untuk pengelolaan data yang jumlahnya dapat berubah-ubah selama eksekusi program.


### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

##### Source Code Singlelist.h
```C++
#ifndef SINGLELIST_H
#define SINGLELIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct angka{
    int num;
};

typedef angka dataAngka;
typedef struct node *address;

struct node{
    dataAngka info;
    address next;
};
struct linkedList {
    address first;
};
  
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(int x);
void dealokasi(address &node);
void printInfo(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);

void deleteFirst(linkedList &List);
void deleteLast(linkedList &List);
void deleteAfter(linkedList &List, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);

#endif
```
##### Source Code Singlelist.cpp
```C++
#include "Singlelist.h"

void createList(linkedList &L) {
    L.first = Nil;
}

address alokasi(int x) {
    address P = new node;
    P->info.num = x;
    P->next = Nil;
    return P;
}

bool isEmpty(linkedList L) {
    return (L.first == Nil);
}

void insertFirst(linkedList &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void insertLast(linkedList &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfter(linkedList &L, address Prec, address P) {
    if (Prec != Nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void printInfo(linkedList L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info.num << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(linkedList &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void deleteLast(linkedList &List){
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
    } else {
        cout << "list kosong" << endl;
    }
}

void deleteAfter(linkedList &List, address nodePrev, address nodeHapus){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { 
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

int nbList(linkedList List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(linkedList &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
}

void dealokasi(address &P) {
    P->next = Nil;
    delete P;
    P = Nil;
}
```
##### Source Code main.cpp
```C++
#include "Singlelist.h"
#include <iostream>
using namespace std;

int main() {
    linkedList L;
    address P1, P2, P3, P4, P5;
    createList(L);

    P1 = alokasi(0);
    insertFirst(L, P1);

    P2 = alokasi(12);
    insertFirst(L, P2);

    P4 = alokasi(9);
    insertFirst(L, P4);

    P5 = alokasi(2);
    insertLast(L, P5);

    P3 = alokasi(8);
    insertAfter(L, P2, P3);

    cout << "--- ISI LIST AWAL ---" << endl;
    printInfo(L);
    cout << endl;
    
    deleteFirst(L);
    deleteLast(L);
    deleteAfter(L, P2, P3);
    cout << "--- ISI LIST SETELAH DELETE FIRST, DELETE LAST, DAN DELETE AFTER ---" << endl;
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);
    cout << endl << "- List Berhasil Terhapus -";
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan4/output/Soal2.png)

Program di atas merupakan pengembangan dari implementasi ADT (Abstract Data Type) Singly Linked List dalam bahasa C++, yang berfungsi untuk mengelola sekumpulan data bertipe integer secara dinamis menggunakan konsep pointer. Pada file Singlelist.h, didefinisikan struktur dasar yang digunakan, yaitu node yang berisi satu data bertipe angka dan pointer next yang menunjuk ke node berikutnya, serta linkedList yang memiliki pointer first untuk menunjukkan node pertama dalam list. File ini juga mendeklarasikan berbagai fungsi penting seperti createList, alokasi, dealokasi, insertFirst, insertAfter, dan insertLast untuk menambahkan elemen ke dalam list. Implementasi seluruh fungsi tersebut terdapat dalam file Singlelist.cpp, di mana createList digunakan untuk menginisialisasi list kosong, alokasi berfungsi membuat node baru, dan dealokasi menghapus node dari memori. Fungsi insertFirst, insertLast, dan insertAfter digunakan untuk menambahkan node baru pada posisi awal, akhir, maupun setelah node tertentu dalam list.

Selanjutnya, bagian terpenting dari program ini adalah operasi penghapusan dan perhitungan jumlah node. Fungsi deleteFirst digunakan untuk menghapus node pertama (yaitu node dengan nilai 9), deleteLast untuk menghapus node terakhir (nilai 2), dan deleteAfter untuk menghapus node setelah node tertentu (menghapus node dengan nilai 8 setelah node bernilai 12). Setelah semua operasi penghapusan dijalankan, fungsi nbList menghitung jumlah node yang tersisa dalam list dengan cara menelusuri setiap node secara berurutan dari awal hingga akhir. Kemudian, fungsi deleteList digunakan untuk menghapus seluruh isi list dari memori agar tidak terjadi kebocoran memori. Pada file main.cpp, semua fungsi tersebut diimplementasikan dengan membuat beberapa node, menambahkannya ke dalam list, lalu menghapus node-node tertentu sesuai instruksi. Setelah operasi selesai, hasil list yang tersisa serta jumlah node ditampilkan ke layar. Secara keseluruhan, program ini menunjukkan cara kerja lengkap struktur data Singly Linked List mulai dari proses penyisipan, penghapusan, penelusuran, hingga pengosongan list secara dinamis menggunakan pointer di C++.

## Kesimpulan
Struktur data linked list memungkinkan pengelolaan data secara dinamis menggunakan konsep pointer, sehingga ukuran list dapat berubah sesuai kebutuhan tanpa pemborosan memori. Melalui operasi dasar seperti insert dan delete, program dapat menambah, menghapus, serta menampilkan data secara efisien tanpa perlu melakukan pergeseran elemen seperti pada array. Dengan demikian, linked list menjadi struktur data yang fleksibel dan efisien untuk berbagai aplikasi yang memerlukan manipulasi data secara dinamis.

## Referensi
[1] Bhatnagar, S. R. (2018). Speeding Up Search in Singly Linked List. International Journal of Computer Applications (IJCA), Vol. 182, No. 18. Diakses melalui https://www.ijcaonline.org/archives/volume182/number18/bhatnagar-2018-ijca-917892.pdf.
<br>[2] Abiew, N. A. K., & Asamoah, D. (2017). Implementing Lock Free Data Structure for Shared-Memory Systems using Linked List. International Journal of Computer Applications (IJCA), Vol. 178, No. 4. Diakses melalui https://www.ijcaonline.org/archives/volume178/number4/abiew-2017-ijca-915806.pdf.
<br>[3] Acharjya, P. P., Koley, S., & Barman, S. (2021). Analysis of the Complexity of Various Linked Lists. Turkish Journal of Computer and Mathematics Education (TURCOMAT). Diakses melalui https://turcomat.org/index.php/turkbilmat/article/view/11883/8697.
<br>[4] Harahap, N., & Purba, D. (2024). Improving Linked List Access using Hybrid Memory Management Techniques. International Journal of Hybrid Information Technology (IJHIT). Diakses melalui https://ijhit.info/index.php/ijhit/article/view/9/9.
<br>[5] Wijoyo, A., Azzahra, A., Nabila, D., Silviana, F., & Lusiyanti. (2024). Perbandingan Struktur Linked List dan Array dalam Manajemen Memori. JRIIN : Jurnal Riset Informatika dan Inovasi, Vol. 4, No. 1. Diakses melalui https://jurnalmahasiswa.com/index.php/jriin/article/view/957/756.   