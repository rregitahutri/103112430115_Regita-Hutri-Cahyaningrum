# <h1 align="center">Laporan Praktikum Modul 10 - Tree (Bagian Pertama)</h1>
<p align="center">Regita Hutri Cahyaningrum - 103112430115</p>

## Dasar Teori
Struktur data jenis pohon (tree) merupakan salah satu bentuk struktur data tidak linier yang penting dalam pemrograman dan pemrosesan data. Menurut Adzkiya, pohon dalam struktur data didefinisikan sebagai kumpulan simpul (nodes) yang memiliki satu simpul akar (root) dan simpul-simpul anak (child), di mana simpul anak dapat memiliki anak lagi secara berjenjang. Jika pohon biner memenuhi aturan bahwa setiap simpul kiri memuat nilai (key) lebih kecil dari simpul induk (parent), dan setiap simpul kanan memuat nilai lebih besar, maka pohon itu disebut Binary Search Tree (BST).

Penggunaan BST juga memungkinkan implementasi struktur data lain. Misalnya, Adzkiya menunjukkan bahwa BST dapat digunakan untuk merepresentasikan Priority Queue, yaitu antrian terurut berdasarkan prioritas sehingga operasi enqueue/dequeue dapat berjalan lebih efisien dibanding implementasi sederhana linear. 

Kajian lain menunjukkan bahwa struktur data tree dapat diadaptasi secara luas, tidak hanya di program berbasis konsol, tapi juga dalam aplikasi berbasis web. Misalnya, studi oleh Agustin dkk. menunjukkan bahwa data tree dapat diterapkan untuk mendesain sistem navigasi atau struktur konten pada sebuah blog/web sebagai media pembelajaran sehingga tree bukan hanya untuk penyimpanan data, tetapi juga untuk representasi hirarkis konten. 

Konsep rekursi sangat relevan dalam implementasi struktur data tree maupun fungsi matematika seperti faktorial. Dalam kode C++ sebelumnya, fungsi faktorial menggunakan rekursi: memanggil dirinya sendiri hingga mencapai base case (angka 0 atau 1). Pendekatan ini analog dengan definisi pohon karena struktur tree bersifat rekursif secara alami: tiap subtree dari sebuah node bisa dianggap sebagai pohon lagi. Dengan demikian, operasi traversal tree (misalnya insert, search, delete) atau operasi komputasi seperti faktorial bisa diimplementasikan elegan menggunakan rekursi.

Karena itu, ketika kita mengimplementasikan BST (seperti di kode BST), setiap insertion / search / deletion dapat dilakukan secara rekursif (atau iteratif), dan struktur data tetap memenuhi sifat BST (nilai anak kiri < parent < anak kanan). Selanjutnya, jika ingin membangun fitur kompleks seperti priority queue, traversal, perhitungan size / height / depth, maka BST + rekursi memungkinkan implementasi yang lebih modular, efisien, dan mudah dikembangkan — sesuai prinsip struktur data modern seperti yang dibahas di literatur [1] dan [2].

Terakhir — adopsi struktur data tree di domain non-konvensional (misalnya aplikasi web/blog) menunjukkan fleksibilitas konsep ini; bukan hanya untuk algoritma “back-end”, tetapi juga untuk representasi logika navigasi, konten, atau data hirarkis dalam GUI/web. Ini relevan jika ingin menerapkan data structure pada proyek seperti aplikasi atau sistem informasi.

### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 

### 1. Rekursif untuk Menghitung Faktorial

```C++
using namespace std;
#include <iostream>

long int faktorial(long int a) {
    if (a == 0 || a == 1) {
        return 1;
    } else {
        return a * faktorial(a - 1);
    }
}

int main() {
    long int n;
    cout << "Masukkan sebuah angka: ";
    cin >> n;

    long int hasil = faktorial(n);
    cout << "Faktorial dari " << n << " adalah " << hasil << endl;

    return 0;
}
```
Program yang mengimplementasikan perhitungan faktorial menggunakan fungsi rekursif, yaitu fungsi yang memanggil dirinya sendiri untuk menyelesaikan tugas. Fungsi faktorial ini dibangun berdasarkan dua kriteria utama rekursif. Pertama, terdapat kondisi khusus (base case) di mana jika nilai input a adalah 0 atau 1, fungsi akan berhenti memanggil dirinya dan mengembalikan nilai 1. Kedua, terdapat langkah pemanggilan diri pada blok else, di mana fungsi mengembalikan hasil perkalian a dengan faktorial(a - 1). Dalam fungsi main, program meminta input bilangan dari pengguna, memprosesnya melalui fungsi rekursif tersebut, dan menampilkan hasil akhirnya ke layar.

### 2. Binary Search Tree (BST)

##### Source Code bst.h
```C++
#ifndef BST_H
#define BST_H
#define Nil NULL
#include <iostream>
using namespace std;

typedef struct BST *node;

struct BST {
    int angka;
    node left;
    node right;
};

typedef node BinTree;

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif
```
##### Source Code bst.cpp
```C++
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){ //tengah - kiri - kanan atau root - child kiri - child kanan
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){ //kiri - tengah - kanan atau child kiri - root - child kanan
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){ //kiri - kanan - tengah atau child kiri - child kanan - root
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}
```
##### Source Code main.cpp
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```
Pada file bst.h, didefinisikan struktur BST (node) yang menampung data integer serta pointer ke anak kiri dan kanan, beserta prototipe fungsi-fungsi ADT (Abstract Data Type). Logika utama terdapat pada file bst.cpp, di mana fungsi insertNode bekerja secara rekursif menempatkan angka yang lebih kecil di kiri dan lebih besar di kanan, sementara fungsi deleteNode menangani tiga skenario penghapusan (node daun, node dengan satu anak, dan node dengan dua anak menggunakan teknik successor). Selain itu, terdapat fitur traversal (PreOrder, InOrder, PostOrder) untuk menelusuri tree, serta fungsi pencarian searchByData yang cukup mendetail karena menampilkan informasi tambahan seperti parent dan sibling dari data yang dicari.

Pada bagian antarmuka di file main.cpp, program menyediakan menu interaktif menggunakan perulangan do-while dan switch-case. Menu ini memungkinkan pengguna untuk melakukan operasi dasar BST secara dinamis, seperti menambah node, menghapus node, mencari data, melihat ukuran (size) dan tinggi (height) tree, serta menampilkan nilai ekstrem (most-left dan most-right). Struktur ini memudahkan pengujian fungsi-fungsi BST secara langsung melalui input konsol.

## Unguided 

### 1. Buatlah ADT Binary Search Tree menggunakan Linked list di dalam file “bstree.h”. Buatlah implementasi ADT Binary Search Tree pada file “bstree.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”.

##### Source Code bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);
void inOrder(address root);
void preOrder(address root);
void postOrder(address root);
bool deleteNode(address &root, infotype x);

#endif
```
##### Source Code bstree.cpp
```C++
#include "bstree.h"
#include <iostream>

using namespace std;

bool isEmpty(address root) {
    return root == Nil;
}

void createTree(address &root) {
    root = Nil;
}

address alokasi(infotype x) {
    address nodeBaru = new Node;
    if (nodeBaru != Nil) {
        nodeBaru->info = x;
        nodeBaru->left = Nil;
        nodeBaru->right = Nil;
    }
    return nodeBaru;
}

void dealokasi(address nodeHapus) {
    delete nodeHapus;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
        if (root != Nil) {
        }
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        }
        else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    } else {
        if (root->info == x) {
            return root;
        } else if (x < root->info) {
            return findNode(x, root->left);
        } else {
            return findNode(x, root->right);
        }
    }
}

void preOrder(address root) {
    if (root != Nil) {
        cout << root->info << " - ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) {
    if (root != Nil) {
        inOrder(root->left);
        cout << root->info << " - ";
        inOrder(root->right);
    }
}

void postOrder(address root) {
    if (root != Nil) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " - ";
    }
}

address mostRight(address root) {
    address temp = root;
    while (temp != Nil && temp->right != Nil) {
        temp = temp->right;
    }
    return temp;
}

address mostLeft(address root) {
    address temp = root;
    while (temp != Nil && temp->left != Nil) {
        temp = temp->left;
    }
    return temp;
}

bool deleteNode(address &root, infotype x) {
    if (root == Nil) {
        return false; 
    }

    if (x < root->info) {
        return deleteNode(root->left, x);
    } else if (x > root->info) {
        return deleteNode(root->right, x);
    } else {
        address temp;

        if (root->left == Nil) {
            temp = root;
            root = root->right;
            dealokasi(temp);
            return true;
        } else if (root->right == Nil) {
            temp = root;
            root = root->left;
            dealokasi(temp);
            return true;
        }

        temp = mostLeft(root->right);
        
        root->info = temp->info;

        return deleteNode(root->right, temp->info);
    }
}

int size(address root) {
    if (root == Nil) {
        return 0;
    } else {
        return 1 + size(root->left) + size(root->right);
    }
}

int height(address root) {
    if (root == Nil) {
        return -1;
    } else {
        int hl = height(root->left);
        int hr = height(root->right);
        
        if (hl > hr) return 1 + hl;
        else return 1 + hr;
    }
}
```
##### Source Code main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;
int main() {
    cout << "Hello World!" << endl;
    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    inOrder(root);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan10/output/Soal1.png)

Pada file header, didefinisikan struktur data abstrak (ADT) berupa struct Node yang memiliki pointer ke anak kiri (left) dan anak kanan (right), serta menyimpan data integer (infotype). Definisi ini memungkinkan pointer address digunakan untuk menghubungkan antar-node secara dinamis di memori.

Logika utama program terdapat pada file bstree.cpp yang menerapkan pendekatan rekursif untuk hampir semua operasinya. Fungsi insertNode bertugas menyisipkan data baru dengan aturan BST, yaitu menempatkan nilai yang lebih kecil ke subtree kiri dan nilai yang lebih besar ke subtree kanan. Selain itu, terdapat fungsi traversal (preOrder, inOrder, postOrder) untuk menelusuri tree, serta fungsi deleteNode yang memiliki logika khusus untuk menangani penghapusan node—baik itu leaf, node dengan satu anak, maupun node dengan dua anak (menggunakan teknik penggantian nilai dengan successor atau node terkecil di subtree kanan). Fungsi utilitas lain seperti size dan height juga disediakan untuk menghitung jumlah node dan kedalaman tree.

Terakhir, file main.cpp berfungsi untuk menguji kebenaran implementasi ADT tersebut. Dimulai dengan inisialisasi root yang kosong (Nil), program kemudian memasukkan serangkaian angka (1, 2, 6, 4, 5, 3, 6, 7) ke dalam tree. Perlu diperhatikan bahwa karena logika insertNode hanya menangani kondisi lebih besar (>) atau lebih kecil (<), angka "6" yang dimasukkan kedua kali akan diabaikan (tidak masuk sebagai duplikat). Program diakhiri dengan memanggil fungsi inOrder, yang akan mencetak seluruh data yang tersimpan di dalam tree secara berurutan (sorted) dari nilai terkecil hingga terbesar ke layar konsol.

### 2. Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.
### ➢ fungsi hitungJumlahNode( root:address ) : integer
### /* fungsi mengembalikan integer banyak node yang ada di dalam BST*/
### ➢ fungsi hitungTotalInfo( root:address, start:integer ) : integer
### /* fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST*/
### ➢ fungsi hitungKedalaman( root:address, start:integer ) : integer
### /* fungsi rekursif mengembalikan integer kedalaman maksimal dari binary tree */

##### Source Code bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);
void inOrder(address root);
void preOrder(address root);
void postOrder(address root);
bool deleteNode(address &root, infotype x);

int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);

#endif
```
##### Source Code bstree.cpp
```C++
#include "bstree.h"
#include <iostream>

using namespace std;

bool isEmpty(address root) {
    return root == Nil;
}

void createTree(address &root) {
    root = Nil;
}

address alokasi(infotype x) {
    address nodeBaru = new Node;
    if (nodeBaru != Nil) {
        nodeBaru->info = x;
        nodeBaru->left = Nil;
        nodeBaru->right = Nil;
    }
    return nodeBaru;
}

void dealokasi(address nodeHapus) {
    delete nodeHapus;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        }
        else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

address findNode(infotype x, address root) {
    if (root != Nil) {
        if (root->info == x) {
            return root;
        } else if (x < root->info) {
            return findNode(x, root->left);
        } else {
            return findNode(x, root->right);
        }
    } else {
        return Nil;
    }
}

void preOrder(address root) {
    if (root != Nil) {
        cout << root->info << " - ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) {
    if (root != Nil) {
        inOrder(root->left);
        cout << root->info << " - ";
        inOrder(root->right);
    }
}

void postOrder(address root) {
    if (root != Nil) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " - ";
    }
}

address mostRight(address root) {
    address temp = root;
    while (temp != Nil && temp->right != Nil) {
        temp = temp->right;
    }
    return temp;
}

address mostLeft(address root) {
    address temp = root;
    while (temp != Nil && temp->left != Nil) {
        temp = temp->left;
    }
    return temp;
}

bool deleteNode(address &root, infotype x) {
    if (root == Nil) {
        return false; 
    }

    if (x < root->info) {
        return deleteNode(root->left, x);
    } else if (x > root->info) {
        return deleteNode(root->right, x);
    } else {
        address temp;

        if (root->left == Nil) {
            temp = root;
            root = root->right;
            dealokasi(temp);
            return true;
        } else if (root->right == Nil) {
            temp = root;
            root = root->left;
            dealokasi(temp);
            return true;
        }

        temp = mostLeft(root->right);
        
        root->info = temp->info;

        return deleteNode(root->right, temp->info);
    }
}

int size(address root) {
    if (root == Nil) {
        return 0;
    } else {
        return 1 + size(root->left) + size(root->right);
    }
}

int height(address root) {
    if (root == Nil) {
        return -1;
    } else {
        int hl = height(root->left);
        int hr = height(root->right);
        
        if (hl > hr) return 1 + hl;
        else return 1 + hr;
    }
}

int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0; 
    } else {
        return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
    }
}

int hitungTotalInfo(address root, int start) {
    if (root == Nil) {
        return 0;
    } else {
        return root->info + hitungTotalInfo(root->left, start) + hitungTotalInfo(root->right, start);
    }
}

int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return start -1;
    } else {
        int kedalamanKiri = hitungKedalaman(root->left, start + 1);
        int kedalamanKanan = hitungKedalaman(root->right, start + 1);
        
        if (kedalamanKiri > kedalamanKanan) {
            return kedalamanKiri;
        } else {
            return kedalamanKanan;
        }
    }
}
```
##### Source Code main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;
int main() {
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    inOrder(root);
    
    cout<<"\nkedalaman : "<<hitungKedalaman(root,1)<<endl;
    cout<<"jumlah Node : "<<hitungJumlahNode(root)<<endl;
    cout<<"total : "<<hitungTotalInfo(root, 0)<<endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan10/output/Soal2.png)

Pada file implementasi, selain fungsi dasar seperti penyisipan (insertNode) dan traversal, terdapat tiga fungsi rekursif utama untuk analisis statistik tree. Pertama, fungsi hitungJumlahNode bekerja dengan menjumlahkan angka 1 (untuk node saat ini) dengan hasil rekursif dari subtree kiri dan kanan, sehingga menghasilkan total simpul yang ada. Kedua, fungsi hitungTotalInfo mengakumulasikan nilai integer (info) yang tersimpan di setiap node dengan cara menjumlahkan nilai node saat ini dengan total nilai dari anak-anaknya. Ketiga, fungsi hitungKedalaman bertugas mencari tinggi maksimum tree; fungsi ini membawa parameter start yang terus bertambah 1 setiap kali rekursi turun ke level berikutnya, kemudian membandingkan kedalaman subtree kiri dan kanan untuk mengambil nilai terbesar. Pada main.cpp, tree dibentuk dengan urutan angka tertentu (1, 2, 6, 4, 5, 3, 7) yang menghasilkan kedalaman 5 level (jika dimulai dari 1), lalu hasil perhitungan jumlah node, total nilai, dan kedalaman tersebut ditampilkan ke layar.

### 3. Print tree secara pre-order dan post-order.

##### Source Code main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;
int main() {
    // cout << "Hello World" << endl;
    address root = Nil;
    // insertNode(root,1);
    // insertNode(root,2);
    // insertNode(root,6);
    // insertNode(root,4);
    // insertNode(root,5);
    // insertNode(root,3);
    // insertNode(root,6);
    // insertNode(root,7);
    // inOrder(root);
    
    // cout<<"\nkedalaman : "<<hitungKedalaman(root,1)<<endl;
    // cout<<"jumlah Node : "<<hitungJumlahNode(root)<<endl;
    // cout<<"total : "<<hitungTotalInfo(root, 0)<<endl;

    // Nomor 3
    insertNode(root, 6); // Root utama
    insertNode(root, 4); // Root subtree kiri
    insertNode(root, 7); // Root subtree kanan
    insertNode(root, 2); 
    insertNode(root, 5); 
    insertNode(root, 1); 
    insertNode(root, 3);
    cout << "\n=== HASIL ===" << endl;

    cout << "Pre-Order  : ";
    preOrder(root);
    cout << endl;

    cout << "In-Order   : ";
    inOrder(root);
    cout << endl;

    cout << "Post-Order : ";
    postOrder(root);
    cout << endl;
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan10/output/Soal3.png)

Pada nomor ini, hanya perlu mengedit bagian main.cpp nya saja. Data dimasukkan dengan urutan 6, 4, 7, 2, 5, 1, dan 3 untuk memastikan angka 6 menjadi root utama dan cabang-cabangnya terbentuk seimbang, berbeda dengan kode sebelumnya yang menghasilkan tree lurus (skewed). Setelah tree terbentuk, program mengeksekusi fungsi Pre-order yang mengunjungi node dengan urutan Root-Left-Right (hasil: 6-4-2-1-3-5-7) , In-order yang mengurutkan nilai secara menaik (hasil: 1-2-3-4-5-6-7) , dan Post-order yang mengunjungi node dengan urutan Left-Right-Root (hasil: 1-3-2-5-4-7-6).

## Kesimpulan
Binary Search Tree (BST) merupakan metode penyimpanan data non-linier yang efektif untuk merepresentasikan hubungan hierarkis. Penerapan konsep rekursif terbukti sangat krusial dan alami dalam menangani operasi-operasi BST, mulai dari proses insertion, pencarian, hingga perhitungan statistik properti pohon seperti jumlah node, total nilai, dan kedalaman (height). Implementasi Abstract Data Type (ADT) menggunakan linked list memungkinkan pengelolaan memori yang dinamis dan modular. Selain itu, pemahaman mendalam mengenai berbagai metode traversal (Pre-order, In-order, dan Post-order) memberikan fleksibilitas dalam menelusuri dan mengolah data sesuai urutan logika yang dibutuhkan. Secara keseluruhan, kombinasi struktur BST dan algoritma rekursif menawarkan efisiensi yang lebih tinggi dalam manajemen data dibandingkan struktur linier sederhana.

## Referensi
[1] Adzkiya, Muhammad Hanif. (2018). Implementasi Binary Search Tree pada Struktur Data Priority Queue dalam Bahasa C. Institut Teknologi Bandung. Diakses melalui https://informatika.stei.itb.ac.id/~rinaldi.munir/Matdis/2018-2019/Makalah/Makalah-Matdis-2018-087.pdf
<br>[2] Agustin, Serly; Permana, Arifin Yusuf; Fazri, Hari Noer; Daffa H, M. Rahssyal; Robi, Mohammad; Firmansyah, Ricky. (2022). IMPLEMENTASI STRUKTUR DATA TREE PADA WEB BLOG SEBAGAI MEDIA PEMBELAJARAN. Jurnal Informatika dan Teknologi Komputer (JITEK), 2(2), 206–212. DOI: 10.55606/jitek.v2i2.316