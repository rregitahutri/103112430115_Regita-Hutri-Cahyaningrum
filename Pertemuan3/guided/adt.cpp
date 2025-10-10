#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    float nilai1, nilai2;
};

void inputMhs(mahasiswa &m){
    cout << "Masukkan nama: "; 
    cin >> m.nama;
    cout << "Masukkan nilai 1: "; 
    cin >> m.nilai1;
    cout << "Masukkan nilai 2: "; 
    cin >> m.nilai2;
}

float rata2(mahasiswa m){
    return (m.nilai1 + m.nilai2) / 2;
}

int main(){
    mahasiswa mhs; //pemanggilan struct (ADT)
    inputMhs(mhs); //pemanggilan procedure
    cout << "Rata rata : " << rata2(mhs) << endl; //pemanggilan function
    return 0;
}