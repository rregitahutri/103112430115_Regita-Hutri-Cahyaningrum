#include <iostream>
#include <iomanip> 
#include "QueuePengiriman.h"

using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    int pilihan;
    Paket tempPaket;

    do {
        cout << "\n--- Komaniya Ekspress ---" << endl;
        cout << "1. Input Data Paket" << endl;
        cout << "2. Hapus Data Paket" << endl;
        cout << "3. Tampilkan queue paket" << endl;
        cout << "4. Hitung Total Biaya Pengiriman" << endl; //Bagian B
        cout << "Pilihan anda : ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            if (isFull(Q)) {
                cout << "Antrian Penuh!" << endl;
            } else {
                cout << "\n-- Masukkan Data Paket --" << endl;
                cout << "Kode Resi    : "; cin >> tempPaket.KodeResi;
                cout << "Nama Pengirim: "; cin >> tempPaket.NamaPengirim;
                cout << "Berat (kg)   : "; cin >> tempPaket.BeratBarang;
                cout << "Tujuan       : "; cin >> tempPaket.Tujuan;
                enQueue(Q, tempPaket);
            }
            break;

        case 2:
            deQueue(Q);
            break;

        case 3:
            viewQueue(Q);
            break;

        case 4: //Bagian B
            cout << "\nTotal Biaya Pengiriman Semua Paket: Rp. " 
                 << fixed << setprecision(0) << TotalBiayaPengiriman(Q) << endl;
            break;

        default:
            cout << "Pilihan tidak valid." << endl;
        }

    } while (pilihan != 0);

    return 0;
}