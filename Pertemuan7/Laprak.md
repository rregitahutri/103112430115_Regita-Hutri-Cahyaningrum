# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>
<p align="center">Regita Hutri Cahyaningrum - 103112430115</p>

## Dasar Teori
Struktur data merupakan cara untuk mengorganisasi dan menyimpan data agar dapat diakses dan dimodifikasi secara efisien. Salah satu jenis struktur data yang sering digunakan adalah stack, yaitu struktur data yang mengikuti prinsip LIFO (Last In First Out), di mana elemen terakhir yang dimasukkan akan menjadi elemen pertama yang dikeluarkan [1]. Dalam implementasinya, stack dapat dibuat menggunakan array maupun linked list.

Implementasi stack dengan array memiliki kelebihan dalam kemudahan akses dan kecepatan karena menggunakan indeks untuk menyimpan data secara berurutan di memori. Namun, ukuran stack terbatas karena kapasitas array ditentukan di awal deklarasi [2]. Sebaliknya, implementasi stack dengan linked list lebih fleksibel karena setiap elemen (node) dialokasikan secara dinamis menggunakan pointer. Hal ini membuat ukuran stack dapat menyesuaikan kebutuhan memori selama program berjalan [3].

Menurut penelitian dalam Jurnal Sains Informatika Terapan, struktur linked list banyak digunakan untuk menangani data dinamis karena efisiensi alokasi dan kemudahan dalam proses penyisipan maupun penghapusan data [4]. Selain itu, penggunaan array dan linked list pada struktur data stack sering diaplikasikan dalam sistem antrian, undo-redo, konversi notasi, dan pengolahan data yang membutuhkan kontrol urutan operasi tertentu [5].


## Guided 

### 1. Implementasi ADT Stack Menggunakan Linked List

##### Source Code stack.h
```C++
#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```
##### Source Code stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```
##### Source Code main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```

Program ini merupakan implementasi Abstract Data Type (ADT) Stack menggunakan struktur data linked list dalam bahasa C++. Stack bekerja dengan prinsip LIFO (Last In, First Out), di mana elemen terakhir yang dimasukkan akan menjadi yang pertama dikeluarkan. File stack.h mendefinisikan struktur node sebagai elemen stack dan stack sebagai penampung dengan pointer top yang menunjuk ke elemen teratas. Implementasi di stack.cpp mencakup operasi dasar seperti push() untuk menambahkan elemen ke atas stack, pop() untuk menghapus elemen teratas, update() untuk mengubah data pada posisi tertentu, view() untuk menampilkan seluruh isi stack, serta searchData() untuk mencari data tertentu di dalam stack. Program utama (main.cpp) menguji seluruh fungsi tersebut dengan membuat beberapa node, melakukan operasi push dan pop, memperbarui nilai, serta mencari data tertentu. Dengan demikian, program ini memperlihatkan bagaimana stack dapat diimplementasikan secara dinamis menggunakan pointer tanpa batasan ukuran seperti pada array.

### 2. Implementasi ADT Stack Menggunakan Array

##### Source Code stack.h
```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

const int MAX = 10;

struct stackTable {
    int data[MAX];
    int top;
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```
##### Source Code stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s){
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX - 1;
}

void createStack(stackTable &s){
    s.top = -1;
}

void push(stackTable &s, int angka){
    if(isFull(s)){
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan ke dalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    if(posisi <= 0){
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    int idx = s.top - (posisi + 1);
    if(idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke- " << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; --i){
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << "Mencari data " << data << "..." << endl;
    int posisi = -1;
    bool found = false;

    for(int i = s.top; i >= 0; --i){
        if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke- " << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Data " << data << " tidak ditemukan dalam stack!" << endl;
        cout << endl;
    }
}
```
##### Source Code main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    // posisi dihitung dari TOP (1-based index)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```

Program ini merupakan implementasi Abstract Data Type (ADT) Stack menggunakan struktur data array statis di bahasa C++. Stack bekerja berdasarkan prinsip LIFO (Last In, First Out), di mana elemen yang terakhir dimasukkan akan menjadi yang pertama dikeluarkan. Pada file header stack.h, didefinisikan struktur stackTable yang menyimpan elemen stack dalam array data berukuran maksimal MAX = 10 dan variabel top untuk menandai posisi elemen teratas. File implementasi berisi berbagai operasi stack, seperti push() untuk menambah data ke dalam stack, pop() untuk menghapus data teratas, update() untuk mengubah nilai pada posisi tertentu, view() untuk menampilkan isi stack, serta searchData() untuk mencari data tertentu di dalam stack. Program utama (main.cpp) digunakan untuk menguji fungsi-fungsi tersebut dengan serangkaian operasi push, pop, update, dan pencarian data. Secara keseluruhan, program ini menunjukkan cara kerja serta penerapan dasar konsep stack berbasis array dalam pemrograman terstruktur.

## Unguided 

### 1. Buatlah ADT Stack menggunakan ARRAY sesuai soal di dalam file “stack.h”. Buatlah implementasi ADT Stack menggunakan Array pada file “stack.cpp” dan “main.cpp.

##### Source Code stack.h
```C++
#ifndef STACK
#define STACK
#define Nil -1
#define MAX 20

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    int data[MAX];
    int top;
};

bool isEmpty(Stack S);
bool isFull(Stack S);
void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```
##### Source Code stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(Stack S) {
    return S.top == Nil;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

void createStack(Stack &S) {
    S.top = Nil;
}

void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.data[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
        return Nil; 
    } else {
        infotype x = S.data[S.top];
        S.top--;
        return x;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.data[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        Stack temp;
        createStack(temp);
        while (!isEmpty(S)) {
            push(temp, pop(S));
        }
        S = temp;
    }
}
```
##### Source Code main.cpp
```C++
#include "stack.h"

int main() {
    cout << "Hello world!" <<
    endl;
    Stack S;

    createStack(S);

    push(S,3);
    push(S,4);
    push(S,8);

    pop(S);

    push(S,2);
    push(S,3);
    
    pop(S);
    
    push(S,9);
    
    printInfo(S);
    cout<<"balik stack"<<endl;
    
    balikStack(S);
    printInfo(S);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan7/output/Soal1.png)

Program di atas merupakan implementasi ADT Stack menggunakan array statis dengan kapasitas maksimum MAX = 20. Pada file stack.h, didefinisikan struktur Stack yang berisi array data dan variabel top sebagai penunjuk elemen teratas. Fungsi-fungsi dasar seperti isEmpty() dan isFull() digunakan untuk memeriksa kondisi stack kosong atau penuh. Prosedur createStack() menginisialisasi stack agar kosong, sedangkan push() menambahkan elemen ke atas stack jika belum penuh, dan pop() menghapus serta mengembalikan elemen teratas jika tidak kosong. Fungsi printInfo() digunakan untuk menampilkan isi stack dari atas ke bawah, dan balikStack() membalik urutan elemen di dalam stack menggunakan stack sementara. Pada file main.cpp, fungsi-fungsi tersebut diuji dengan beberapa operasi push() dan pop(), kemudian hasilnya ditampilkan sebelum dan sesudah proses pembalikan stack, sehingga memperlihatkan cara kerja prinsip LIFO (Last In, First Out) pada struktur data stack berbasis array.

### 2.  Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer).

##### Source Code stack.h
```C++
#ifndef STACK
#define STACK
#define Nil -1
#define MAX 20

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    int data[MAX];
    int top;
};

bool isEmpty(Stack S);
bool isFull(Stack S);
void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

void pushAscending(Stack &S, infotype x);

#endif
```
##### Source Code stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(Stack S) {
    return S.top == Nil;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

void createStack(Stack &S) {
    S.top = Nil;
}

void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.data[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
        return Nil; 
    } else {
        infotype x = S.data[S.top];
        S.top--;
        return x;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.data[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        Stack temp;
        createStack(temp);
        while (!isEmpty(S)) {
            push(temp, pop(S));
        }
        S = temp;
    }
}

void pushAscending(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
        return;
    }

    Stack temp;
    createStack(temp);

    while (!isEmpty(S) && S.data[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}
```
##### Source Code main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan7/output/Soal2.png)

Program di atas merupakan implementasi ADT Stack dengan penambahan prosedur pushAscending() yang berfungsi untuk memasukkan elemen baru ke dalam stack secara terurut menaik (ascending). File stack.h berisi deklarasi struktur stack, konstanta, serta daftar fungsi yang digunakan. Pada file stack.cpp, fungsi pushAscending() bekerja dengan cara memindahkan sementara elemen-elemen yang lebih besar dari nilai yang akan dimasukkan (x) ke stack sementara (temp), kemudian menambahkan nilai x ke stack utama, dan akhirnya mengembalikan semua elemen dari stack sementara ke stack utama. Dengan cara ini, elemen-elemen dalam stack akan tersusun dari nilai terkecil di bawah hingga nilai terbesar di atas. File main.cpp digunakan untuk menguji program dengan menambahkan beberapa elemen menggunakan pushAscending(), menampilkan isi stack, kemudian membalik urutan stack menggunakan balikStack(). Program ini memperlihatkan penerapan konsep LIFO (Last In, First Out) dengan tambahan logika pengurutan otomatis saat proses penyisipan elemen.

### 3. Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.

##### Source Code stack.h
```C++
#ifndef STACK
#define STACK
#define Nil -1
#define MAX 20

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype data[MAX];
    int top;
};

bool isEmpty(Stack S);
bool isFull(Stack S);
void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif
```
##### Source Code stack.cpp
```C++
#include "stack.h"
#include <iostream>
#include <sstream> // untuk parsing input baris
using namespace std;

bool isEmpty(Stack S) {
    return S.top == Nil;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

void createStack(Stack &S) {
    S.top = Nil;
}

void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.data[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
        return Nil; 
    } else {
        infotype x = S.data[S.top];
        S.top--;
        return x;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.data[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        Stack temp;
        createStack(temp);
        while (!isEmpty(S)) {
            push(temp, pop(S));
        }
        S = temp;
    }
}

void pushAscending(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
        return;
    }

    Stack temp;
    createStack(temp);

    while (!isEmpty(S) && S.data[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    string line;
    getline(cin, line);

    for (char ch : line) {
        if (isdigit(ch)) {
            int num = ch - '0';
            if (!isFull(S)) {
                push(S, num);
            } else {
                cout << "Stack penuh, sisanya diabaikan!" << endl;
                break;
            }
        }
    }
}
```
##### Source Code main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);

    getInputStream(S);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan7/output/Soal3.png)

Program di atas merupakan implementasi Abstract Data Type (ADT) Stack menggunakan bahasa C++ dengan struktur data berbasis array. File stack.h berisi deklarasi tipe data Stack, konstanta, dan seluruh fungsi yang digunakan. File stack.cpp berisi definisi fungsi-fungsi utama seperti createStack() untuk inisialisasi, push() untuk menambah elemen, pop() untuk menghapus elemen teratas, printInfo() untuk menampilkan isi stack, balikStack() untuk membalik urutan stack, serta pushAscending() untuk menambahkan elemen secara berurutan menaik. Fungsi tambahan getInputStream() menggunakan cin.get() secara tidak langsung melalui getline() untuk membaca satu baris input dari pengguna dan memasukkan setiap karakter angka ke dalam stack hingga tombol Enter ditekan. Sementara itu, main.cpp berfungsi sebagai pengujian program dengan membuat stack baru, menerima input pengguna, menampilkan isi stack sebelum dan sesudah dibalik. Program ini menampilkan bagaimana stack bekerja dalam prinsip Last In, First Out (LIFO).

## Kesimpulan
Dari hasil praktikum yang telah dilakukan, dapat disimpulkan bahwa stack merupakan salah satu struktur data linear yang bekerja berdasarkan prinsip LIFO (Last In First Out), di mana elemen terakhir yang dimasukkan akan menjadi yang pertama dikeluarkan. Implementasi stack dapat dilakukan menggunakan array maupun linked list, masing-masing memiliki kelebihan dan kekurangannya.

Implementasi stack berbasis array lebih sederhana dan memiliki akses data yang cepat karena indeks langsung menunjuk ke elemen tertentu. Namun, ukurannya bersifat tetap sehingga tidak fleksibel terhadap perubahan jumlah data. Sedangkan stack berbasis linked list lebih dinamis karena alokasi memori dilakukan secara fleksibel menggunakan pointer, meskipun membutuhkan memori tambahan untuk menyimpan referensi antar node.

Melalui berbagai fungsi seperti push, pop, update, view, dan searchData, program ini memperlihatkan bagaimana operasi dasar stack bekerja dalam pengelolaan data. Selain itu, pengembangan fungsi seperti pushAscending() dan getInputStream() menunjukkan bahwa struktur data stack dapat dimodifikasi untuk mendukung kebutuhan logika yang lebih kompleks. Dengan demikian, pemahaman konsep stack sangat penting sebagai dasar dalam membangun algoritma dan sistem pemrograman yang efisien.

## Referensi
[1] Johnson Sihombing. (2019). Penerapan Stack dan Queue pada Array dan Linked List dalam Java. Jurnal Infokom, Piksi Ganesha, Vol. 7 No. 2.
<br>[2] Universitas Dharma Andalas. (2024). Implementasi Stack dan Array pada Pengurutan Lagu dengan Metode Selection Sort. Jurnal Teknologi dan Sistem Informasi (JTEKSIS), Vol. 9 No. 1. Diakses melalui https://jurnal.unidha.ac.id/index.php/jteksis/article/view/1192/759

<br>[3] Agung Wijoyo, dkk. (2023). Evaluasi Efisiensi Struktur Data Linked List pada Implementasi Sistem Antrian. Jurnal Riset Ilmu Informatika (JRiiN). Diakses melalui https://jurnalmahasiswa.com/index.php/jriin/article/view/1060/678

<br>[4] Nanda Puspitasari, dkk. (2022). Analisis Struktur Data Linked List dalam Pengolahan Data Mahasiswa. Jurnal Sains Informatika Terapan (JSIT), RCF Indonesia. Diakses melalui https://rcf-indonesia.org/home/index.php/jsit/article/view/591/418

<br>[5] Ahmad Ghiyas Ahyar, dkk. (2021). Jurnal Struktur Data – Pembelajaran Array, Linked List, Stack, dan Queue. Scribd. Diakses melalui https://www.scribd.com/document/504317899/JURNAL-Struktur-Data

