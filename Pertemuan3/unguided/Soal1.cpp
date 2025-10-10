#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    string nim;
    int nilaiUTS;
    int nilaiUAS;
    int nilaiTugas;
    float nilaiAkhir;
};

float nilaiAkhir(mahasiswa mhs){
    return 0.3 * mhs.nilaiUTS + 0.4 * mhs.nilaiUAS + 0.3 * mhs.nilaiTugas;
} 

void inputMhs(mahasiswa &mhs){
    cout << "Masukkan Nama: ";
    cin >> mhs.nama;
    cout << "Masukkan NIM: ";
    cin >> mhs.nim;
    cout << "Masukkan Nilai UTS: ";
    cin >> mhs.nilaiUTS;
    cout << "Masukkan Nilai UAS: ";
    cin >> mhs.nilaiUAS;
    cout << "Masukkan Nilai Tugas: ";
    cin >> mhs.nilaiTugas;

    mhs.nilaiAkhir = nilaiAkhir(mhs);
}

void outputMhs(mahasiswa mhs[], int n){
    cout << "\n=== Daftar Nilai Mahasiswa ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama        : " << mhs[i].nama << endl;
        cout << "NIM         : " << mhs[i].nim << endl;
        cout << "Nilai UTS   : " << mhs[i].nilaiUTS << endl;
        cout << "Nilai UAS   : " << mhs[i].nilaiUAS << endl;
        cout << "Nilai Tugas : " << mhs[i].nilaiTugas << endl;
        cout << "Nilai Akhir : " << mhs[i].nilaiAkhir << endl;
        cout << "-----------------------------";
    }
    cout << endl;
}

int main(){
    mahasiswa mhs[10];
    int n;

    cout << "Masukan data mahasiswa (max 10): ";
    cin >> n;

    if (n > 10) {
        cout << "Maksimal hanya bisa input 10 data mahasiswa." << endl;
        return 0;
    } else{
        for (int i = 0; i < n; i++) {
            cout << "\nData Mahasiswa ke-" << i + 1 << endl;
            inputMhs(mhs[i]);
        }
    }

    outputMhs(mhs, n);
    return 0;
}