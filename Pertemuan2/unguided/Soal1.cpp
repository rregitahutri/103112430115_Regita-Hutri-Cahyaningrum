#include <iostream>
using namespace std;

void tampilkanHasil(int arr[3][3]){ //void = procedure. ini fungsi untuk menampilkan hasil
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int arrB[3][3] = {
        {1, 3, 5},
        {2, 4, 6},
        {7, 8, 9}
    };
    int arrC[3][3] = {0};
    int arrD[3][3] = {0};
    int arrE[3][3] = {0};

    //penjumlahan matriks 3x3
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    //pengurangan matriks 3x3
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arrD[i][j] = arrA[i][j] - arrB[i][j];
        }
    }

    //perkalian matriks 3x3
    for(int i = 0; i < 3; i++){         //perulangan baris
        for(int j = 0; j < 3; j++){     //perulangan kolom
            for(int k = 0; k < 3; k++){ //perulangan perkalian
                arrE[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Matriks A: " << endl;
    tampilkanHasil(arrA);
    cout << endl;
    cout << "Matriks B: " << endl;
    tampilkanHasil(arrB);
    cout << endl;

    cout << "Hasil penjumlahan matriks A + B: " << endl;
    tampilkanHasil(arrC);
    cout << endl;

    cout << "Hasil pengurangan matriks A - B: " << endl;
    tampilkanHasil(arrD);

    cout << endl;
    cout << "Hasil perkalian matriks A * B: " << endl;
    tampilkanHasil(arrE);

    return 0;
}