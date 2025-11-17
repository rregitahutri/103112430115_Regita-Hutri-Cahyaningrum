#include <iostream>
#include <iomanip>
#include "StackMahasiswa.h" 

using namespace std;

float hitungNilaiAkhir(Mahasiswa M) {
    return (0.2 * M.NilaiTugas) + (0.4 * M.NilaiUTS) + (0.4 * M.NilaiUAS);
}

bool isEmpty(StackMahasiswa S) {
    return S.Top == -1;
}

bool isFull(StackMahasiswa S) {
    return S.Top == MAX - 1;
}

void createStack(StackMahasiswa &S) {
    S.Top = -1;
}

void Push(StackMahasiswa &S, Mahasiswa M) {
    if (isFull(S)) {
        cout << "[Error] Stack Penuh! Tidak bisa menambahkan " << M.Nama << endl;
    } else {
        S.Top++;
        S.dataMahasiswa[S.Top] = M;
    }
}

void Pop(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "[Error] Stack Kosong! Tidak bisa Pop." << endl;
    } else {
        Mahasiswa temp = S.dataMahasiswa[S.Top];
        S.Top--;
        cout << "Pop berhasil, data " << temp.Nama << " dihapus." << endl;
    }
}

void Update(StackMahasiswa &S, int posisi, Mahasiswa dataBaru) {
    int index = posisi - 1;
    if (isEmpty(S)) {
        cout << "Stack Kosong." << endl;
    } else if (index < 0 || index > S.Top) {
        cout << "[Error] Posisi " << posisi << " tidak valid." << endl;
    } else {
        S.dataMahasiswa[index] = dataBaru;
        cout << "Update pada posisi " << posisi << " (" << dataBaru.Nama << ")." << endl;
    }
}

void View(StackMahasiswa S) {
    cout << "\n=========== ISI STACK ===========" << endl;
    if (isEmpty(S)) {
        cout << "(Stack Kosong)" << endl;
    } else {
        for (int i = S.Top; i >= 0; i--) {
            float na = hitungNilaiAkhir(S.dataMahasiswa[i]);
            cout << (i + 1) << ". " 
                 << "Nama: " << S.dataMahasiswa[i].Nama << endl
                 << "NIM: " << S.dataMahasiswa[i].NIM << endl
                 << "Nilai Tugas: " << S.dataMahasiswa[i].NilaiTugas << endl
                 << "Nilai UTS: " << S.dataMahasiswa[i].NilaiUTS << endl
                 << "Nilai UAS: " << S.dataMahasiswa[i].NilaiUAS << endl
                 << "Nilai Akhir: " << fixed << setprecision(2) << na << endl;
                 cout << "----------------------------------------" << endl;
        }
    }
}

void SearchNilaiAkhir(StackMahasiswa S, float min, float max) {
    cout << "\n=== SEARCHING (Range NA: " << min << " - " << max << ") ===" << endl;
    bool found = false;
    if (isEmpty(S)) {
        cout << "Stack Kosong." << endl;
        return;
    }
    for (int i = S.Top; i >= 0; i--) {
        float na = hitungNilaiAkhir(S.dataMahasiswa[i]);
        if (na >= min && na <= max) {
            cout << (i + 1) << ". " 
                 << S.dataMahasiswa[i].Nama << " (Nilai Akhir: " << na << ")" << endl;
            found = true;
        }
    }
    if (!found) cout << "Tidak ada data dalam rentang tersebut." << endl;
}

void MaxNilaiAkhir(StackMahasiswa S) {
    cout << "\nMAHASISWA NILAI TERTINGGI:" << endl;
    if (isEmpty(S)) {
        cout << "Stack Kosong." << endl;
        return;
    }
    float maxVal = -1.0;
    int maxIndex = -1;
    for (int i = 0; i <= S.Top; i++) {
        float currentVal = hitungNilaiAkhir(S.dataMahasiswa[i]);
        if (currentVal > maxVal) {
            maxVal = currentVal;
            maxIndex = i;
        }
    }
    cout << "Nama: " << S.dataMahasiswa[maxIndex].Nama << endl;
    cout << "Posisi: " << (maxIndex + 1) << endl;
    cout << "Nilai Akhir: " << maxVal << endl;
}