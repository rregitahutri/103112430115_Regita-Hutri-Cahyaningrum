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
