#include <iostream>
#include <iomanip>
#include "QueuePengiriman.h"

using namespace std;

bool isEmpty(QueueEkspedisi Q) {
    return (Q.Tail == -1);
}

bool isFull(QueueEkspedisi Q) {
    return (Q.Tail == MAX - 1);
}

void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

void enQueue(QueueEkspedisi &Q, Paket data) {
    if (isFull(Q)) {
        cout << "[Full] Antrian penuh! Paket " << data.NamaPengirim << " ditolak." << endl;
    } else {
        if (isEmpty(Q)) {
            Q.Head = 0;
        }
        Q.Tail++;
        Q.dataPaket[Q.Tail] = data;
        cout << "Berhasil input paket: " << data.NamaPengirim << endl;
    }
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "[Empty] Antrian kosong, tidak ada yang bisa dihapus." << endl;
    } else {
        Paket temp = Q.dataPaket[Q.Head];
        
        for (int i = Q.Head; i < Q.Tail; i++) {
            Q.dataPaket[i] = Q.dataPaket[i + 1];
        }
        
        Q.Tail--;
        
        if (Q.Tail == -1) {
            Q.Head = -1;
        }
        
        cout << "Dequeue sukses. Paket " << temp.NamaPengirim << " (" << temp.KodeResi << ") telah diproses." << endl;
    }
}

void viewQueue(QueueEkspedisi Q) {
    cout << "\n--- DAFTAR ANTRIAN PAKET ---" << endl;
    if (isEmpty(Q)) {
        cout << "(Antrian Kosong)" << endl;
    } else {
        for (int i = Q.Head; i <= Q.Tail; i++) {
            cout << i + 1 << ". Resi: " << Q.dataPaket[i].KodeResi << endl
                 << "Pengirim: " << Q.dataPaket[i].NamaPengirim << endl
                 << "Berat: " << Q.dataPaket[i].BeratBarang << "kg" << endl
                 << "Tujuan: " << Q.dataPaket[i].Tujuan << endl;
                 cout << "----------------------------" << endl;
        }
    }
}

float TotalBiayaPengiriman(QueueEkspedisi Q) {
    float total = 0;
    if (!isEmpty(Q)) {
        for (int i = Q.Head; i <= Q.Tail; i++) {
            total += (Q.dataPaket[i].BeratBarang * 8250);
        }
    }
    return total;
}