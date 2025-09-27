#include <iostream>
using namespace std;

struct convertN{
    string satuan[12] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"};

    string puluhan(int n) {
        int puluh = n / 10;
        int sisa  = n % 10;
        string hasil = satuan[puluh] + " puluh";
        
        if (sisa != 0) {
            hasil += " " + satuan[sisa];
        }

        return hasil;
    }

    string convert(int n){
        if (n < 12) {
            return satuan[n];
        } else if (n < 20) {
            return satuan[n - 10] + " belas";
        } else if (n < 100) {
            return puluhan(n);
        } else if (n == 100) {
            return "seratus";
        } else {
            return "Tidak bisa dikonversi. Angka harus di antara 0-100";
        }
    }
};

int main(){
    convertN cn;
    int n;

    cout << "Masukkan angka (0-100): ";
    cin >> n;
    cout << n << " : " << cn.convert(n) << endl;
    
    return 0;
}