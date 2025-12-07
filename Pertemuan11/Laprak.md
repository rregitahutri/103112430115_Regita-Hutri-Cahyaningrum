# <h1 align="center">Laporan Praktikum Modul 13 - MULTI LINKED LIST</h1>
<p align="center">Regita Hutri Cahyaningrum - 103112430115 </p>

## Dasar Teori

Struktur data merupakan elemen fundamental dalam pengembangan perangkat lunak, khususnya dalam manajemen data dinamis. Menurut Sofianti dkk., dalam konteks pengelolaan data mahasiswa, dua struktur data yang umum dibandingkan adalah Array dan Linked List. Array menawarkan keunggulan berupa akses elemen secara langsung (random access) melalui indeks, sehingga sangat efisien ketika data bersifat statis dan jarang berubah. Namun, ketika data harus sering diubah disisipkan, dihapus, atau direstrukturisasi array menjadi kurang fleksibel karena memerlukan pergeseran elemen. Sementara itu, linked list memungkinkan penambahan dan penghapusan elemen tanpa harus memindahkan seluruh elemen lain, berkat pointer yang menghubungkan tiap node. Dengan demikian, linked list lebih cocok untuk data yang dinamis dan berubah-ubah. 

Lebih lanjut, penelitian oleh Setiyawan dkk. menunjukkan bahwa ketika struktur data seperti Stack diimplementasikan menggunakan linked list vs array, dua pendekatan ini menonjolkan kelebihan yang berbeda: array unggul dalam kecepatan eksekusi untuk data statis, sedangkan linked list unggul dalam fleksibilitas ukuran dan alokasi memori dinamis di saat data bersifat variabel. Ini menegaskan bahwa pemilihan struktur data sebaiknya disesuaikan dengan karakteristik dan kebutuhan aplikasi. 

Contoh penerapan nyata dari linked list dapat dilihat pada implementasi sistem antrean (queue) dan manajemen daftar belanja. Dalam studi oleh Sahid dkk., linked list digunakan untuk membangun sistem antrean berbasis FIFO di aplikasi web layanan print mahasiswa. Struktur linked list mempermudah penambahan data baru di akhir antrean dan penghapusan data di awal antrean tanpa overhead besar sesuatu yang sulit dicapai jika menggunakan array dalam skenario dengan jumlah data yang sering berubah. 

Demikian pula, Sipayung dkk. menunjukkan bahwa linked list cocok untuk aplikasi yang membutuhkan manajemen daftar dengan operasi dinamis dalam kasus mereka, aplikasi daftar belanja pintar. Dengan linked list, aplikasi mampu mendukung penambahan item, penghapusan item, dan pengelompokan prioritas (immediate vs later), sehingga pengguna bisa dengan mudah menambah, menghapus, atau memprioritaskan item tanpa mengganggu struktur keseluruhan daftar. 

Dengan demikian, teori dan hasil dari penelitian-penelitian ini mendukung keputusan implementasi struktur data berbasis linked list terutama dalam situasi di mana data bersifat dinamis dan sering mengalami perubahan, seperti pada daftar menu restoran, klasifikasi hewan, atau sistem dengan operasi insert/delete/search/update.

## Guided 

### 1. Implementasi Multi Linked List untuk Manajemen Data Kategori dan Menu Makanan Restoran

#### mll.h
```C++
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataMakanan {
    string idMakanan;
    string namaMakanan;
    float harga;
};

struct KategoriMakanan {
    string idKategori;
    string namaKategori;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataMakanan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    KategoriMakanan isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk);
bool isEmptyAnak(listAnak LAnak);
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent);
void deleteFirstParent(listInduk &LInduk);
void deleteLastParent(listInduk &LInduk);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void findParentByID(listInduk &LInduk, string IDCari);
void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori);

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild);
void deleteFirstChild(listAnak &LAnak);
void deleteLastChild(listAnak &LAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga);

//operasi print
void printStrukturMLL(listInduk &LInduk);
void printListInduk(listInduk &LInduk);
void printListAnak(listInduk &LInduk, NodeParent nodeInduk);

//operasi hapus list
void hapusListInduk(listInduk &LInduk);
void hapusListAnak(listAnak &LAnak);

#endif
```

#### mll.cpp
```C++
#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk){
    if(LInduk.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyAnak(listAnak LAnak){
    if(LAnak.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListInduk(listInduk &LInduk) {
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak) {
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idKategori = idKategori;
    nodeBaruParent->isidata.namaKategori = namaKategori;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idMakanan = idMakanan;
    nodeBaruChild->isidata.namaMakanan = namaMakanan;
    nodeBaruChild->isidata.harga = harga;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak) {
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeInduk) {
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan pertama di list Induk!" << endl;
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent) {
    if(nodePrevParent == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevParent == LInduk.last){
            insertLastParent(LInduk, nodeBaruParent);
            return;
        } else {
            nodeBaruParent->next = nodePrevParent->next;
            nodeBaruParent->prev = nodePrevParent;
            (nodePrevParent->next)->prev = nodeBaruParent;
            nodePrevParent->next = nodeBaruParent;
            cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam list induk setelah node parent "<< nodePrevParent->isidata.namaKategori << endl;
        }
    }
}

void deleteFirstParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.first;
        if (LInduk.first == LInduk.last) { // KASUS KHUSUS 1 ELEMEN
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.first = LInduk.first->next;
            LInduk.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node pertama list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteLastParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.last;
        if (LInduk.first == LInduk.last) {
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.last = LInduk.last->prev;
            nodeHapus->prev = NULL;
            LInduk.last->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node terakhir list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->isidata.namaKategori << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findParentByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        int index = 1;
        int ketemu = false;
        while(nodeBantu != NULL){
            if(nodeBantu->isidata.idKategori == IDCari){
                cout << "Data ID parent ditemukan pada list induk posisi ke-" << index << "!" << endl;
                cout << "ID : " << nodeBantu->isidata.idKategori << endl;
                cout << "Posisi dalam list induk : posisi ke-" << index << endl;
                cout << "Nama Kategori : " << nodeBantu->isidata.namaKategori << endl;
                ketemu = true;
                break;
            } else {
                nodeBantu = nodeBantu->next;
                index++;
            }
        }
        if(!ketemu){
            cout << "Data ID parent tidak ditemukan didalam list induk!" << endl;
        }
    }
}

void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        bool ketemu = false;
        while (nodeBantu != NULL) {
            if (nodeBantu->isidata.idKategori == IDCari) {
                // Proses Update
                nodeBantu->isidata.namaKategori = newNamaKategori;
                cout << "Update Parent Berhasil!" << endl;
                cout << "Node parent dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                cout << "Nama Kategori baru  : " << newNamaKategori << endl;
                ketemu = true;
                break; 
            } else {
                nodeBantu = nodeBantu->next;
            }
        }
        if (!ketemu) {
            cout << "Parent dengan ID " << IDCari << " tidak ditemukan" << endl;
        }
    }
}

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->next = LAnak.first;
        LAnak.first->prev = nodeBaruChild;
        LAnak.first = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan pertama di list Anak!" << endl;
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild) {
    if(nodePrevChild == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevChild == LAnak.last){
            insertLastChild(LAnak, nodeBaruChild);
            return;
        } else {
            nodeBaruChild->next = nodePrevChild->next;
            nodeBaruChild->prev = nodePrevChild;
            (nodePrevChild->next)->prev = nodeBaruChild;
            nodePrevChild->next = nodeBaruChild;
            cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam list anak setelah node child "<< nodePrevChild->isidata.namaMakanan << endl;
        }
    }
}

void deleteFirstChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.first;
        if (LAnak.first == LAnak.last) { // KASUS KHUSUS 1 ELEMEN
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.first = LAnak.first->next;
            LAnak.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node pertama list anak berhasil dihapus!" << endl;
    }
}

void deleteLastChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.last;
        if (LAnak.first == LAnak.last) {
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.last = LAnak.last->prev;
            nodeHapus->prev = NULL;
            LAnak.last->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node terakhir list anak berhasil dihapus!" << endl;
    }
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(isEmptyAnak(LAnak) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->isidata.namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->isidata.idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaKategori << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idKategori << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama kategori : " << nodeBantuParent->isidata.namaKategori << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        bool ketemu = false;
        // Loop Parent (karena child ada di dalam parent)
        while (nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            // Loop Child
            while (nodeBantuChild != NULL) {
                if (nodeBantuChild->isidata.idMakanan == IDCari) {
                    // Proses Update
                    nodeBantuChild->isidata.namaMakanan = newNamaMakanan;
                    nodeBantuChild->isidata.harga = newHarga;
                    cout << "Update Child Berhasil!" << endl;
                    cout << "Lokasi : Ada di dalam Parent " << nodeBantuParent->isidata.namaKategori << endl;
                    cout << "Node child dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                    cout << "Nama Makanan Baru  : " << newNamaMakanan << endl;
                    cout << "Harga Baru : " << newHarga << endl;
                    ketemu = true;
                    break; // Break loop child
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                }
            }
            if (ketemu){
                break; // Break loop parent jika sudah ketemu di dalam
            } else {
                nodeBantuParent = nodeBantuParent->next;
            }
        }
        if (!ketemu) {
            cout << "Child dengan ID " << IDCari << " tidak ditemukan di parent manapun." << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "      Harga : " << nodeBantuChild->isidata.harga << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

void printListInduk(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk Kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int index = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << index << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            index++;
        }
    }
}

void printListAnak(listInduk &LInduk, NodeParent nodeInduk) {
    if(isEmptyInduk(LInduk) == true || nodeInduk == NULL){
        cout << "List induk kosong atau node induk tidak valid!" << endl;
    } else {
        NodeChild nodeBantuChild = nodeInduk->L_Anak.first;
        if(nodeBantuChild == NULL) {
            cout << "node parent " << nodeInduk->isidata.namaKategori << " tidak memiliki list anak!" << endl;
        } else {
            cout << "=== List Anak Node Parent " << nodeInduk->isidata.namaKategori << " ===" << endl;
            int index = 1;
            while(nodeBantuChild != NULL) {
                cout << "Child " << index << " :" << endl;
                cout << "ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                cout << "---------------------------" << endl;
                nodeBantuChild = nodeBantuChild->next;
                index++;
            }
        }
    }
}

//operasi hapus list
void hapusListInduk(listInduk &LInduk) {
    NodeParent nodeBantu = LInduk.first;
    while(nodeBantu != NULL) {
        NodeParent nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        //panggil prosedur hapusListAnak() untuk menghapus child-child nya
        hapusListAnak(nodeHapus->L_Anak);
        dealokasiNodeParent(nodeHapus);
    }
    LInduk.first = LInduk.last = NULL;
}

void hapusListAnak(listAnak &LAnak) {
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}
```
#### main.cpp
```C++
#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Inisialisasi List
    listInduk L;
    createListInduk(L);
    cout << "=== MENU RESTORAN DIBUAT ===" << endl << endl;

    // 2. Membuat Data Parent (Kategori Makanan)
    // Kita simpan pointer-nya agar mudah memasukkan anak nanti
    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);
    
    cout << endl;
 
    // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu
    
    // --> Isi Kategori Makanan Berat (K01)
    NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
    insertFirstChild(Kat1->L_Anak, Mkn1);

    NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
    insertLastChild(Kat1->L_Anak, Mkn2);

    // --> Isi Kategori Minuman (K02)
    NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
    insertLastChild(Kat2->L_Anak, Min1);
    
    NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
    insertFirstChild(Kat2->L_Anak, Min2);

    // --> Isi Kategori Dessert (K03)
    NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
    insertLastChild(Kat3->L_Anak, Des1);
    cout << endl;

    cout << "=== TAMPILAN AWAL MENU ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    // 4. Test Pencarian (Find)
    cout << "=== TEST PENCARIAN ===" << endl;
    findParentByID(L, "K02"); // Cari Kategori Minuman
    cout << "---------------------------" << endl;
    findChildByID(L, "M01");  // Cari Nasi Goreng
    cout << "---------------------------" << endl;
    findChildByID(L, "X99");  // Cari data ngawur (harus not found)
    cout << "---------------------------" << endl;
    cout << endl;

    // 5. Test Update Data
    cout << "=== TEST UPDATE ===" << endl;
    // Update Nama Kategori (Parent)
    // Mengubah "Dessert" menjadi "Makanan Penutup"
    updateDataParentByID(L, "K03", "Makanan Penutup");
    cout << "---------------------------" << endl;
    
    // Update Data Makanan (Child)
    // Mengubah "Nasi Goreng Spesial" jadi "Nasgor Gila", harga naik jadi 28000
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
    cout << "---------------------------" << endl;
    
    cout << "\n=== SETELAH UPDATE ===" << endl;
    // Kita cek apakah data berubah
    printListInduk(L); // Cek nama kategori saja
    cout << endl;
    printListAnak(L, Kat1); // Cek list anak di kategori 1
    cout << endl;

    // 6. Test Penghapusan (Delete)
    cout << "=== TEST DELETE ===" << endl;
    
    // Hapus Child: Hapus Jus Alpukat (D02) dari Minuman
    cout << "> Menghapus Child D02..." << endl;
    deleteFirstChild(Kat2->L_Anak); 
    
    // Hapus Parent: Hapus Kategori Dessert/Makanan Penutup (K03)
    // DeleteLastParent akan menghapus elemen terakhir (K03)
    cout << "> Menghapus Parent Terakhir (K03)..." << endl;
    deleteLastParent(L); 

    cout << "\n=== TAMPILAN AKHIR MENU ===" << endl;
    printStrukturMLL(L);

    return 0;
}
```

#### Penjelasan

Program ini menunjukkan cara kerja Multi Linked List untuk mengelola data menu restoran, di mana "Kategori Makanan" menjadi Parent dan "Menu Makanan" menjadi Child. Struktur datanya terdiri dari dua jenis node: nodeParent dengan pointer next, prev, dan pointer ke list anak (L_Anak), serta nodeChild yang memuat informasi menu. Program mendukung operasi dasar seperti menambah kategori dan menu, melakukan pencarian bertingkat (mencari ID parent terlebih dahulu lalu ID child di dalamnya), serta melakukan update data. Bagian penting dari program ini adalah fungsi deleteParent yang menerapkan penghapusan menyeluruh; ketika sebuah kategori dihapus, seluruh menu di dalam kategori tersebut dibersihkan dahulu melalui hapusListAnak sebelum node parent dilepas dari memori

## Unguided 

### 1. Buatlah ADT Multi Linked List sebagai berikut didalam file “MultiLL.h”

#### MultiLL.h
```C++
#ifndef MultiLL_H
#define MultiLL_H

#include <iostream>
#include <string>

using namespace std;

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

//isEmpty & create list
bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

//alokasi & dealokasi
NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeChild(NodeChild &NChild);
void deallocNodeParent(NodeParent &NParent);

//operasi pada parent
void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

//operasi pada child
void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

//operasi print
void printMLLStructure(listParent &LParent);

//operasi hapus list
void deleteListChild(listChild &LChild);

#endif
```
#### MultiLL.cpp
```C++
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
```
#### main.cpp
```C++
#include "MultiLL.h"
#include <iostream>
using namespace std;

int main() {

    // 1. Inisialisasi List Parent (Golongan Hewan)
    listParent L;
    createListParent(L);

    // 2. Membuat Data Parent (Golongan Hewan)
    NodeParent G1 = allocNodeParent("G001", "Aves");
    insertFirstParent(L, G1);

    NodeParent G2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(L, G2);

    NodeParent G3 = allocNodeParent("G003", "Pisces");
    insertLastParent(L, G3);

    NodeParent G4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(L, G4);

    NodeParent G5 = allocNodeParent("G005", "Reptil");
    insertLastParent(L, G5);

    cout << endl;

    // 3. Memasukkan Child (Data Hewan) ke Parent tertentu

    // ---- Golongan Aves (G001)
    NodeChild H1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertFirstChild(G1->L_Child, H1);

    NodeChild H2 = allocNodeChild("AV002", "Bebek", "Air", true, 2);
    insertLastChild(G1->L_Child, H2);

    // ---- Golongan Mamalia (G002)
    NodeChild R1 = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
    insertFirstChild(G2->L_Child, R1);

    NodeChild R2 = allocNodeChild("M003", "Gorila", "Hutan", false, 160);
    insertLastChild(G2->L_Child, R2);
    
    NodeChild R3 = allocNodeChild("M002", "Kucing", "Darat", false, 4);
    insertLastChild(G2->L_Child, R3);

    // ---- Golongan Amfibi (G004)
    NodeChild B1 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertFirstChild(G4->L_Child, B1);

    printMLLStructure(L);
    cout << endl;
    
    return 0;
}
```

#### Output Unguided 1

![Screenshot Output Unguided 1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan11/output/Soal1.png)

#### Penjelasan

Program membentuk struktur klasifikasi hewan berbasis hierarki, dengan "Golongan Hewan" sebagai Parent dan masing-masing spesies hewan sebagai Child. ADT MultiLL didefinisikan dalam header untuk deklarasi struktur, sedangkan implementasinya berada dalam file sumber terpisah. Memori dialokasikan secara dinamis menggunakan allocNodeParent dan allocNodeChild. Penyusunan struktur dilakukan melalui insertLastParent dan insertLastChild yang menghubungkan setiap node menjadi list ganda pada dua level. Ketika printMLLStructure dipanggil, program menampilkan daftar hewan yang telah tersusun rapi di bawah kategori golongannya masing-masing.

### 2. Tambahkan prosedur searchHewanByEkor(input/output LParent : listParent, input tail : Boolean) yang digunakan untuk melakukan operasi SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan denganmenelusuri list child yang ada pada masing-masing node parent). Kemudian panggil prosedur tersebut pada main.cpp. 

#### mll.h
```C++
#ifndef MLL_SOAL2_H
#define MLL_SOAL2_H

#include <iostream>
#include <string>
using namespace std;

struct golonganHewan { string idGolongan; string namaGolongan; };
struct dataHewan { string idHewan; string namaHewan; string habitat; bool ekor; float bobot; };
typedef struct nodeParent *adrParent;
typedef struct nodeChild *adrChild;
struct nodeChild { dataHewan info; adrChild next; adrChild prev; };
struct listChild { adrChild first; adrChild last; };
struct nodeParent { golonganHewan info; adrParent next; adrParent prev; listChild L_Child; };
struct listParent { adrParent first; adrParent last; };

void createListParent(listParent &L);
void createListChild(listChild &L);
adrParent allocNodeParent(string idGol, string namaGol);
adrChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void insertLastParent(listParent &L, adrParent P);
void insertLastChild(listChild &L, adrChild P);
void printMLLStructure(listParent L);

void searchHewanByEkor(listParent L, bool tail);

#endif
```

#### mll.cpp
```C++
#include "mll.h"

void createListParent(listParent &L) { L.first = NULL; L.last = NULL; }
void createListChild(listChild &L) { L.first = NULL; L.last = NULL; }
adrParent allocNodeParent(string idGol, string namaGol) {
    adrParent P = new nodeParent; P->info.idGolongan = idGol; P->info.namaGolongan = namaGol;
    P->next = NULL; P->prev = NULL; createListChild(P->L_Child); return P;
}
adrChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    adrChild P = new nodeChild; P->info.idHewan = idHwn; P->info.namaHewan = namaHwn;
    P->info.habitat = habitat; P->info.ekor = tail; P->info.bobot = weight;
    P->next = NULL; P->prev = NULL; return P;
}
void insertLastParent(listParent &L, adrParent P) {
    if (L.first == NULL) { L.first = P; L.last = P; } else { P->prev = L.last; L.last->next = P; L.last = P; }
}
void insertLastChild(listChild &L, adrChild P) {
    if (L.first == NULL) { L.first = P; L.last = P; } else { P->prev = L.last; L.last->next = P; L.last = P; }
}
void printMLLStructure(listParent L) {
    adrParent P = L.first; int i = 1;
    while (P != NULL) {
        cout << "Parent " << i << " (" << P->info.namaGolongan << ")" << endl;
        adrChild C = P->L_Child.first;
        if(C==NULL) cout << "(kosong)" << endl;
        while (C != NULL) { cout << " - " << C->info.namaHewan << endl; C = C->next; }
        P = P->next; i++; cout << endl;
    }
}

void searchHewanByEkor(listParent L, bool tail) {
    adrParent P = L.first;
    int idxParent = 1;
    while (P != NULL) {
        adrChild C = P->L_Child.first;
        int idxChild = 1;
        while (C != NULL) {
            if (C->info.ekor == tail) {
                cout << "Data ditemukan pada list anak dari node parent " 
                     << P->info.namaGolongan << " pada posisi ke-" << idxParent << "!" << endl;
                cout << "--- Data Child ---" << endl;
                cout << "ID Child      : " << C->info.idHewan << endl;
                cout << "Posisi        : posisi ke-" << idxChild << endl;
                cout << "Nama Hewan    : " << C->info.namaHewan << endl;
                cout << "Habitat       : " << C->info.habitat << endl;
                cout << "Ekor          : " << C->info.ekor << endl;
                cout << "Bobot         : " << C->info.bobot << endl;
                cout << "--------------------------" << endl;
                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent     : " << P->info.idGolongan << endl;
                cout << "Posisi        : posisi ke-" << idxParent << endl;
                cout << "Nama Golongan : " << P->info.namaGolongan << endl;
                cout << "--------------------------" << endl << endl;
            }
            C = C->next;
            idxChild++;
        }
        P = P->next;
        idxParent++;
    }
}
```

#### main.cpp
```C++
#include "mll.h"

int main() {
    listParent LP;
    createListParent(LP);

    adrParent P1 = allocNodeParent("G001", "Aves"); insertLastParent(LP, P1);
    adrParent P2 = allocNodeParent("G002", "Mamalia"); insertLastParent(LP, P2);
    insertLastParent(LP, allocNodeParent("G003", "Pisces"));
    adrParent P4 = allocNodeParent("G004", "Amfibi"); insertLastParent(LP, P4);
    insertLastParent(LP, allocNodeParent("G005", "Reptil"));

    insertLastChild(P1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(P1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2.0));
    insertLastChild(P2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200.0));
    insertLastChild(P2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160.0));
    insertLastChild(P2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4.0));
    insertLastChild(P4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    cout << "=== OUTPUT SOAL 2 (SEARCH EKOR FALSE) ===" << endl;
    searchHewanByEkor(LP, false);

    return 0;
}
```

#### Output Unguided 2

![Screenshot Output Unguided 2](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan11/output/Soal2.png)

#### Penjelasan

Unguided 2 berfokus pada pencarian hewan berdasarkan kondisi boolean, yaitu menemukan hewan yang tidak memiliki ekor (tail == false). Prosedur searchHewanByEkor bekerja dengan traversal bersarang: loop utama mengiterasi seluruh Parent (Golongan Hewan), sementara loop dalam menelusuri semua Child pada setiap parent. Pada loop dalam inilah kondisi if (C->info.ekor == tail) diperiksa. Jika cocok, program menampilkan data hewan sekaligus kategori induknya, sehingga pencarian tetap akurat meskipun data tersebar di berbagai parent.

### 3.Lakukan operasi DELETE dengan menghapus node G004 yang ada pada list parent (list child dari node tersebut juga terhapus), kemudian lakukan lagi operasi PRINT dengan memanggil prosedur printMLLStructure(). Sehingga bentuk dari multi linkedlistnya berubah menjadi seperi ini :

#### mll.h
```C++
#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *adrParent;
typedef struct nodeChild *adrChild;

struct nodeChild {
    dataHewan info;
    adrChild next;
    adrChild prev;
};

struct listChild {
    adrChild first;
    adrChild last;
};

struct nodeParent {
    golonganHewan info;
    adrParent next;
    adrParent prev;
    listChild L_Child;
};

struct listParent {
    adrParent first;
    adrParent last;
};

void createListParent(listParent &L);
void createListChild(listChild &L);

adrParent allocNodeParent(string idGol, string namaGol);
adrChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void insertLastParent(listParent &L, adrParent P);
void insertLastChild(listChild &L, adrChild P);

void deleteParent(listParent &L, string idGol); 
void printMLLStructure(listParent L);           

#endif
```

#### mll.cpp
```C++
#include "mll.h"

void createListParent(listParent &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListChild(listChild &L) {
    L.first = NULL;
    L.last = NULL;
}

adrParent allocNodeParent(string idGol, string namaGol) {
    adrParent P = new nodeParent;
    P->info.idGolongan = idGol;
    P->info.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

adrChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    adrChild P = new nodeChild;
    P->info.idHewan = idHwn;
    P->info.namaHewan = namaHwn;
    P->info.habitat = habitat;
    P->info.ekor = tail;
    P->info.bobot = weight;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertLastParent(listParent &L, adrParent P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertLastChild(listChild &L, adrChild P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void deleteListChild(listChild &L) {
    adrChild P = L.first;
    while (P != NULL) {
        adrChild temp = P;
        P = P->next;
        delete temp; 
    }
    L.first = NULL;
    L.last = NULL;
}

void deleteParent(listParent &L, string idGol) {
    adrParent P = L.first;
    while (P != NULL && P->info.idGolongan != idGol) {
        P = P->next;
    }

    if (P != NULL) {
        deleteListChild(P->L_Child);

        if (P == L.first && P == L.last) { 
            L.last = NULL;
        } else if (P == L.first) { 
            L.first = P->next;
            L.first->prev = NULL;
        } else if (P == L.last) { 
            L.last = P->prev;
            L.last->next = NULL;
        } else { 
            P->prev->next = P->next;
            P->next->prev = P->prev;
        }
        delete P; 
    }
}

void printMLLStructure(listParent L) {
    adrParent P = L.first;
    int i = 1;

    while (P != NULL) {
        cout << "Parent " << i << endl;
        cout << "ID Golongan : " << P->info.idGolongan << endl;
        cout << "Nama Golongan : " << P->info.namaGolongan << endl;

        if (P->L_Child.first == NULL) {
            cout << "(tidak ada child)" << endl;
        } else {
            adrChild C = P->L_Child.first;
            int j = 1;
            while (C != NULL) {
                cout << "- Child " << j << ":" << endl;
                cout << "  ID Hewan : " << C->info.idHewan << endl;
                cout << "  Nama Hewan : " << C->info.namaHewan << endl;
                cout << "  Habitat : " << C->info.habitat << endl;
                cout << "  Ekor : " << C->info.ekor << endl;
                cout << "  Bobot : " << C->info.bobot << endl;
                C = C->next;
                j++;
            }
        }
        if (P->next != NULL) cout << endl; 
        
        P = P->next;
        i++;
    }
    cout << endl;
}
```
#### main.cpp
```C++
#include "mll.h"

int main() {
    listParent LP;
    createListParent(LP);

    adrParent P1 = allocNodeParent("G001", "Aves");
    insertLastParent(LP, P1);
    insertLastChild(P1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(P1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2.0));

    adrParent P2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LP, P2);
    insertLastChild(P2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200.0));
    insertLastChild(P2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160.0));
    insertLastChild(P2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4.0));

    insertLastParent(LP, allocNodeParent("G003", "Pisces"));

    adrParent P4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(LP, P4);
    insertLastChild(P4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    insertLastParent(LP, allocNodeParent("G005", "Reptil"));

    deleteParent(LP, "G004");

    printMLLStructure(LP);

    return 0;
}
```

#### Output Unguided 3

![Screenshot Output Unguided 3](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan11/output/Soal3.png)

#### Penjelasan

Pada Unguided 3, fokusnya adalah operasi penghapusan node parent tertentu misalnya golongan "Amfibi" dengan ID "G004" dari struktur Multi Linked List. Fungsi deleteParent menjaga konsistensi memori dengan terlebih dahulu memanggil deleteListChild untuk menghapus semua child yang dimiliki parent tersebut. Setelah list anak dikosongkan, pointer next dan prev dari parent di sekitarnya disesuaikan untuk memutus hubungan node target, kemudian memori parent didealokasi. Dengan demikian, rangkaian list tetap tersusun rapi (Aves → Mamalia → Pisces → Reptil) dan bebas dari sisa data yang tidak diperlukan.

## Kesimpulan

Implementasi Multi Linked List pada program ini berhasil digunakan untuk mengelola data kategori makanan sebagai node induk (parent) dan data makanan sebagai node anak (child) melalui struktur list ganda yang saling terhubung. Seluruh fungsi utama seperti penambahan, pencarian, pencetakan, serta penghapusan data pada level induk maupun anak telah berjalan sesuai dengan konsep dasar multi linked list, termasuk mekanisme traversal dan manajemen memori untuk mencegah kebocoran data. Dengan demikian, program mampu menampilkan hubungan hierarkis antara kategori dan item makanan secara terstruktur, serta memastikan bahwa setiap operasi yang dilakukan tetap konsisten, efisien, dan sesuai dengan prinsip pengolahan data berbasis linked list.

## Referensi

[1] H. A. Sofianti, Y. V. Manullang, N. A. Tampubolon, L. H. Naibaho, & I. Gunawan, “Implementasi Struktur Data Array dan Linked List Dalam Pengelolaan Data Mahasiswa,” Menulis: Jurnal Penelitian Nusantara, 2025. 
<br>[2] R. D. Setiyawan, D. Hermawan, A. F. Abdillah, A. Mujayanah, & R. Vindua, “Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List,” JUTECH: Journal Education and Technology, Vol. 5, No. 2, 2024. 
<br>[3] S. Sahid, F. Sahnadi Pasaribu, M. M. F. Simanullang, & M. R. Lubis, “Implementasi Queue Berbasis Linked List pada Aplikasi Web Manajemen Antrian Print Mahasiswa,” Jurnal Ilmu Komputer dan Informatika, Vol. 2 No. 2, 2025.
<br>[4] J. G. Sipayung, D. Syafitri, M. F. E. Yuri, & R. A. H. Sihombing, “Pengembangan Aplikasi Belanja Pintar Berbasis Linked List dengan Fitur Checklist dan Prioritas,” Jurnal Ilmu Komputer dan Informatika, 2025.