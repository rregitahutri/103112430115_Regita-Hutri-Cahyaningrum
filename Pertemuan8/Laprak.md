# <h1 align="center">Laporan Praktikum Modul 8 - Queue</h1>
<p align="center">Regita Hutri Cahyaningrum - 103112430115</p>

## Dasar Teori
Pengembangan sistem informasi memiliki peran penting dalam mendukung proses bisnis serta meningkatkan efektivitas dan efisiensi kinerja organisasi. Sistem informasi yang dirancang dengan baik dapat membantu proses pengolahan data, penyimpanan, serta penyajian informasi secara cepat dan akurat sehingga mampu mendukung pengambilan keputusan. Dalam proses pengembangan sistem, analisis kebutuhan, perancangan fitur, serta pemilihan metode pengembangan menjadi aspek yang sangat krusial agar sistem yang dihasilkan benar-benar relevan dengan kebutuhan pengguna [1].

Selain itu, teknologi informasi juga berperan sebagai alat untuk mempermudah aktivitas manusia dalam berbagai bidang, seperti pendidikan, pelayanan publik, dan bisnis. Penerapan aplikasi berbasis web maupun mobile mampu mengotomatisasi proses manual yang sebelumnya memerlukan waktu lebih lama dan rentan kesalahan. Penggunaan sistem berbasis komputer juga mendorong akurasi data dan kemudahan akses oleh pengguna dimana saja dan kapan saja [2]. Metode penelitian seperti observasi, wawancara, serta studi literatur sering digunakan dalam pengumpulan data untuk merancang sistem yang tepat sasaran. Model pengembangan perangkat lunak tertentu, seperti waterfall atau prototyping, kerap dipilih untuk memastikan pembangunan sistem berjalan terstruktur.

Di sisi lain, penerapan sistem informasi pada instansi atau organisasi membutuhkan pengelolaan data yang baik agar kualitas informasi tetap terjaga. Data yang dikelola harus valid, akurat, dan dapat dipertanggungjawabkan. Sistem yang dibangun perlu memperhatikan aspek keamanan, integritas, serta ketersediaan data agar dapat diandalkan dalam mendukung kegiatan operasional [3]. Penggunaan database yang terstruktur, perancangan antarmuka yang mudah dipahami, serta alur penggunaan sistem yang efisien merupakan faktor keberhasilan implementasi sistem informasi.

Modernisasi layanan organisasi melalui digitalisasi juga dapat meningkatkan kualitas pelayanan kepada masyarakat. Dengan memanfaatkan teknologi informatika, proses-proses seperti pendaftaran, penyimpanan data, monitoring, hingga pelaporan dapat dilakukan secara cepat dan transparan. Pemanfaatan aplikasi terkomputerisasi membantu mengurangi beban administrasi manual dan memberi nilai tambah dalam bentuk peningkatan produktivitas kerja serta kepuasan pengguna [4].

## Guided 

### 1. Implementasi ADT Queue Menggunakan Linked List untuk Manajemen Antrian Nama

##### Source Code queue.h
```C++
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
```

##### Source Code queue.cpp
```C++
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(Queue Q) {
    return Q.head == nullptr;
}

bool isFull(Queue) {
    return false;
}

void enQueue(Queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(Queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(Queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}
```

##### Source Code main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    Queue Q;
    createQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
```
Program ini mengimplementasikan struktur data Queue menggunakan linked list, di mana proses penambahan data (enqueue) dilakukan pada bagian belakang antrian dan penghapusan data (dequeue) dilakukan pada bagian depan. Queue dianggap selalu dapat menampung data baru karena linked list tidak memiliki batasan ukuran seperti array. Fungsi‐fungsi yang disediakan meliputi pembuatan queue, pengecekan kondisi kosong, penambahan elemen, penghapusan elemen, menampilkan seluruh isi queue, dan menghapus seluruh elemen queue. Program utama menguji operasi‐operasi tersebut dengan menambahkan beberapa nama ke dalam antrian, menampilkan isinya, menghapus beberapa elemen, dan kemudian menampilkan hasil akhirnya. Program ini cocok digunakan untuk memodelkan sistem antrian dinamis yang memerlukan fleksibilitas tanpa batas kapasitas.

### 2. Implementasi ADT Queue Menggunakan Array Statis dengan Tiga Mekanisme: Alternatif 1, Alternatif 2, dan Alternatif 3

##### Source Code queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue {
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q); //terbentuk queue dengan head = -1 dan tail = -1
void CreateQueue(queue &Q);
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```
##### Source Code queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }
```
##### Source Code main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```
Program ini mengimplementasikan ADT Queue menggunakan array statis berukuran tetap, dengan fokus utama pada Alternatif 1, yaitu mekanisme head tetap diam dan tail bergerak setiap kali elemen dimasukkan. Pada metode ini, proses enqueue sederhana, tetapi dequeue membutuhkan penggeseran elemen ke kiri untuk menjaga agar elemen terdepan tetap berada di posisi head. Selain Alternatif 1, program juga menyediakan contoh implementasi Alternatif 2 dan Alternatif 3 melalui kode komentar: Alternatif 2 menggunakan mekanisme head dan tail sama-sama bergerak tanpa penggeseran elemen, sedangkan Alternatif 3 menerapkan konsep queue melingkar (circular queue) di mana head dan tail dapat kembali ke posisi awal ketika array masih memiliki ruang kosong. Ketiga mekanisme ini menunjukkan bagaimana perilaku dan efisiensi queue dapat berbeda meskipun menggunakan struktur data dasar yang sama. Program utama menguji operasi enqueue, dequeue, dan viewQueue pada Alternatif 1 untuk memperlihatkan perubahan keadaan queue setelah beberapa operasi dilakukan.

## Unguided 

### 1. Buatlah ADT Queue menggunakan ARRAY (tertera dalam soal) di dalam file “queue.h”. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).

##### Source Code queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue {
    int info[MAKSIMAL];
    int head;
    int tail;
};

void CreateQueue(queue &Q);
bool isEmptyQueue(queue Q); //terbentuk queue dengan head = -1 dan tail = -1
bool isFullQueue(queue Q);
void enqueue(queue &Q, int x);
void dequeue(queue &Q);
void printInfo(queue Q);

#endif
```
##### Source Code queue.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

bool isEmptyQueue(queue Q){
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(queue Q){
    return (Q.tail == MAKSIMAL - 1);
}

void CreateQueue(queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

void enqueue(queue &Q, int x){
    if(isFullQueue(Q)){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmptyQueue(Q)){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

void dequeue(queue &Q){
    if(isEmptyQueue(Q)){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = 0; i < Q.tail; i++){
            Q.info[i] = Q.info[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

void printInfo(queue Q){
    cout << Q.head << " - " << Q.tail << " | ";

    if(isEmptyQueue(Q)){
        cout << "empty queue" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i];
            if(i < Q.tail) cout << " ";
        }
        cout << endl;
    }
}
```
##### Source Code main.cpp
```C++
#include "queue.h"
#include <iostream>

int main() {
    cout << "Hello World!" << endl;

    queue Q;
    CreateQueue(Q);

    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;

    printInfo(Q);

    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);

    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    enqueue(Q,4); printInfo(Q);

    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan8/output/Soal1.png)

Implementasi diatas menggunakan array yang bekerja dengan konsep bahwa head tetap berada di indeks 0, sehingga setiap operasi dequeue harus menggeser seluruh elemen ke kiri satu posisi. Queue dinyatakan kosong ketika head dan tail bernilai -1, dan dinyatakan penuh ketika tail mencapai indeks maksimum array. Pada operasi enqueue, elemen baru ditambahkan pada posisi tail + 1, sementara pada dequeue, elemen pertama dihapus dengan menggeser seluruh elemen sehingga elemen berikutnya selalu kembali ke posisi indeks 0. Mekanisme ini sederhana tetapi kurang efisien karena proses penggeseran terjadi setiap kali dequeue. Fungsi printInfo menampilkan posisi head–tail serta daftar elemen yang sedang berada dalam antrian sehingga memudahkan dalam memantau perubahan isi queue selama program berjalan.

### 2. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

##### Source Code queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue {
    int info[MAKSIMAL];
    int head;
    int tail;
};

void CreateQueue(queue &Q);
bool isEmptyQueue(queue Q); //terbentuk queue dengan head = -1 dan tail = -1
bool isFullQueue(queue Q);
void enqueue(queue &Q, int x);
void dequeue(queue &Q);
void printInfo(queue Q);

#endif
```
##### Source Code queue.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

bool isEmptyQueue(queue Q){
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(queue Q){
    return (Q.tail == MAKSIMAL - 1);
}

void CreateQueue(queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

void enqueue(queue &Q, int x){
    if(isFullQueue(Q)){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmptyQueue(Q)){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

void dequeue(queue &Q){
    if(isEmptyQueue(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        Q.head++;
        if(Q.head > Q.tail){ 
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

void printInfo(queue Q){
    cout << Q.head << " - " << Q.tail << " | ";

    if(isEmptyQueue(Q)){
            cout << "empty queue" << endl;
        } else {
            for(int i = Q.head; i <= Q.tail; i++){
                cout << Q.info[i];
                if(i < Q.tail) cout << " ";
            }
        cout << endl;
    }
}
```
##### Source Code main.cpp
```C++
#include "queue.h"
#include <iostream>

int main() {
    cout << "Hello World!" << endl;

    queue Q;
    CreateQueue(Q);

    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;

    printInfo(Q);

    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);

    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    enqueue(Q,4); printInfo(Q);

    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan8/output/Soal2.png)

Program diatas menggunakan array statis di mana baik head maupun tail akan terus bertambah seiring proses enqueue dan dequeue tanpa kembali ke awal. Queue dianggap kosong ketika head dan tail bernilai -1, dan dianggap penuh ketika tail mencapai indeks maksimum array. Pada proses enqueue, elemen ditambahkan di posisi tail + 1, sedangkan pada dequeue, elemen dihapus dengan menggeser head satu langkah ke kanan. Jika setelah penghapusan posisi head melewati tail, queue kembali ke kondisi kosong. Metode ini bekerja sederhana namun memiliki kelemahan karena ruang kosong di awal array tidak dapat digunakan kembali. Fungsi printInfo menampilkan posisi head–tail beserta isi queue yang sedang aktif, sehingga seluruh proses antrian dapat dipantau dengan jelas.

### 3. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

##### Source Code queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue {
    int info[MAKSIMAL];
    int head;
    int tail;
};

void CreateQueue(queue &Q);
bool isEmptyQueue(queue Q); //terbentuk queue dengan head = -1 dan tail = -1
bool isFullQueue(queue Q);
void enqueue(queue &Q, int x);
void dequeue(queue &Q);
void printInfo(queue Q);

#endif
```
##### Source Code queue.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

bool isEmptyQueue(queue Q){
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(queue Q){
    return (Q.tail + 1) % MAKSIMAL == Q.head;
}

void CreateQueue(queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

void enqueue(queue &Q, int x){
    if(isFullQueue(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmptyQueue(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAKSIMAL;
        }
        Q.info[Q.tail] = x;
    }
}
void dequeue(queue &Q){
    if(isEmptyQueue(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(Q.head == Q.tail){ 
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAKSIMAL; 
        }
    }
}

void printInfo(queue Q){
    cout << Q.head << " - " << Q.tail << " | ";

    if(isEmptyQueue(Q)){
        cout << "empty queue" << endl;
        return;
    }

    int i = Q.head;
    while (true) {
        cout << Q.info[i];

        if (i == Q.tail) break;

        cout << " ";
        i = (i + 1) % MAKSIMAL;
    }

    cout << endl;
}
```
##### Source Code main.cpp
```C++
#include "queue.h"
#include <iostream>

int main() {
    cout << "Hello World!" << endl;

    queue Q;
    CreateQueue(Q);

    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;

    printInfo(Q);

    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);

    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    enqueue(Q,4); printInfo(Q);

    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan8/output/Soal3.png)

Kode diatas adalah implementasi Queue Alternatif 3 (head dan tail berputar / circular queue) menggunakan konsep antrian yang memanfaatkan array melingkar sehingga posisi head dan tail akan kembali ke indeks 0 ketika mencapai batas array. Ketika melakukan enqueue, elemen baru dimasukkan ke posisi (tail + 1) % MAKSIMAL, sementara ketika dequeue, elemen dihapus dengan menggeser head ke (head + 1) % MAKSIMAL. Kondisi kosong ditandai dengan head == -1 dan tail == -1, sedangkan kondisi penuh terjadi ketika tail + 1 modulo ukuran array sama dengan head. Dengan mekanisme ini, ruang pada array dapat digunakan kembali meskipun elemen di awal sudah dikeluarkan, sehingga lebih efisien dibanding queue linear. Output program menunjukkan proses memasukkan dan mengeluarkan elemen sambil memperlihatkan posisi head–tail yang berputar sesuai karakteristik circular queue.

## Kesimpulan
Pada praktikum ini, kamu berhasil mengimplementasikan struktur data Queue menggunakan dua pendekatan utama: linked list dan array statis. Implementasi linked list memberikan fleksibilitas tanpa batasan ukuran, sedangkan array statis memperlihatkan tiga mekanisme antrian berbeda:

##### 1. Alternatif 1 (head diam, tail bergerak) – mudah dipahami, tetapi operasi dequeue kurang efisien karena perlu menggeser elemen.
##### 2. Alternatif 2 (head & tail bergerak) – lebih efisien tanpa penggeseran, namun ruang kosong di awal array tidak dapat digunakan kembali.
##### 3. Alternatif 3 (circular queue) – paling optimal karena memanfaatkan seluruh ruang array secara melingkar tanpa pemborosan.

## Referensi
[1] Trijayanti, A., Aulia, I., Khairunisa, N., Purba, F. A., & Gunawan, I. (2025). Implementasi Struktur Data Antrian Queue dalam Sistem Penjadwalan Proses pada Sistem Operasi. Jurnal Publikasi Teknik Informatika, 4(2), 48–53. Diakses melalui https://doi.org/10.55606/jupti.v4i2.4170
<br>[2] Simbolon, A. P. H., Sagala, K. F., Tanjung, M. R. A., Zai, T. S. W., & Ramadhani, F. (2024). “Implementasi Sistem Pengelolaan Pesanan Menu Restoran Berbasis Stack dan Queue.” bit-Tech, 7(2), 484–493. Diakses melalui https://doi.org/10.32877/bt.v7i2.1867
<br>[3] Aini, S. N., & Kurniawan, R. (2025). Sistem Antrian Pasien Berbasis Web Dengan Algoritma Circular Queue Pada Klinik Pratama Rawat Inap Ar-Razi. CESS (Journal of Computer Engineering, System and Science), 10(2), 666–678. Diakses melalui https://doi.org/10.24114/cess.v10i2.67447
<br>[4] Hariputra, R. P., Putra, S. D., & Sumijan, (2022). Analisis Sistem Antrian dalam Meningkatkan Efektivitas Pelayanan Menggunakan Metode Accidental Sampling. JSisfotek, 4(2), 70–75. Diakses melalui https://doi.org/10.37034/jsisfotek.v4i2.127