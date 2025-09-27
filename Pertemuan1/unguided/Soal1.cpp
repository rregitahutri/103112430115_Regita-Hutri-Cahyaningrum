#include <iostream>
using namespace std;
int main(){
    float x, y;
    cout << "Masukkan angka 1: ";
    cin >> x;
    cout << "Masukkan angka 2: ";
    cin >> y;

    cout << endl << "===== Hasil Operasi Aritmatika =====" << endl;
    //penjumlahan
    cout << "Penjumlahan " << x << " + " << y << " = " << x + y << endl;
    //pengurangan
    cout << "Pengurangan " << x << " - " << y << " = " << x - y << endl;
    //perkalian
    cout << "Perkalian " << x << " * " << y << " = " << x * y << endl;
    //pembagian
    if ( y != 0 ) {
        cout << "Pembagian " << x << " / " << y << " = " << x / y << endl;
    } else {
        cout << "Tidak bisa dibagi dengan 0" << endl;
    }
    

    return 0;
}