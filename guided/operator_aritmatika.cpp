#include <iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "Masukkan angka1 : ";
    cin >> angka1;
    cout << "Masukkan angka2 : ";
    cin >> angka2;

    //penjumlahan
    cout << "penjumlahan : " << angka1 + angka2 << endl;
    //pengurangan
    cout << "pengurangan : " << angka1 - angka2 << endl;
    //perkalian
    cout << "perkalian : " << angka1 * angka2 << endl;
    //pembagian
    cout << "pembagian : " << angka1 / angka2 << endl;
    //modulus
    cout << "modulus : " << angka1 % angka2 << endl;
    
    return 0;
}