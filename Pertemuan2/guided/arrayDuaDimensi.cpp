#include <iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]){ //void = procedure. ini fungsi untuk menampilkan hasil
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    //penjumlahan matriks 2x2
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan: " << endl;
    tampilkanHasil(arrC);
    cout << endl;

    //perkalian matriks 2x2
    for(int i = 0; i < 2; i++){         //perulangan baris
        for(int j = 0; j < 2; j++){     //perulangan kolom
            for(int k = 0; k < 2; k++){ //perulangan perkalian
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian: " << endl;
    tampilkanHasil(arrD);
    return 0;
}