#include <iostream>
using namespace std;

void tampilkanArray(int arr[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukar(int *x, int *y){ 
    int temp;
    temp = *x; 
    *x = *y;   
    *y = temp; 
}

int main(){
    int arrA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int arrB[3][3] = {
        {11, 12, 13},
        {14, 15, 16},
        {17, 18, 19}
    };

    cout << "Array A: " << endl;
    tampilkanArray(arrA);
    cout << endl << "Array B: " << endl;
    tampilkanArray(arrB);

    // Pertukaran isi array tanpa pointer/reference
    cout << endl << "=== Pertukaran isi array dengan cara manual ===" << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int temp = arrA[i][j];
            arrA[i][j] = arrB[i][j];
            arrB[i][j] = temp;
        }
    }
    cout << "Array A setelah ditukar: " << endl;
    tampilkanArray(arrA); 
    cout << "Array B setelah ditukar: " << endl;
    tampilkanArray(arrB);
    // Pertukaran isi array A ke B, dan B ke A MENGGUNAKAN POINTER
    cout << endl << "=== Pertukaran isi array menggunakan pointer ===" << endl;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tukar(&arrA[i][j], &arrB[i][j]);
        }
    }

    cout << "Array A setelah ditukar: " << endl;
    tampilkanArray(arrA); 
    cout << "Array B setelah ditukar: " << endl;
    tampilkanArray(arrB);

    return 0;
}