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