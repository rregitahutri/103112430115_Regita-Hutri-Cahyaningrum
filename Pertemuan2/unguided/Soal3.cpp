#include <iostream>
using namespace std;

int cariMinimum(int arr[], int ukuran){
    int MIN = arr[0];
    for(int i = 1; i < ukuran; i++){
        if(arr[i] < MIN){
            MIN = arr[i];
        }
    }
    return MIN;
}

int cariMaximum(int arr[], int ukuran){
    int MAX = arr[0];
    for(int i = 1; i < ukuran; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void hitungRataRata(int arr[], int ukuran, float &rataRata){
    int total = 0;
    for(int i = 0; i < ukuran; i++){
        total += arr[i];
    }
    rataRata = 1.0 * total / ukuran;
}
int main(){
    int arrA[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int pilihMenu;
    cout << "--- Menu Program Array ---" << endl;
    cout << "1. Tampilkan isi array" << endl;
    cout << "2. cari nilai maksimum" << endl;
    cout << "3. cari nilai minimum" << endl;
    cout << "4. Hitung nilai rata - rata" << endl;

    cout << "Pilih menu (1-4): ";
    cin >> pilihMenu;
    switch(pilihMenu){
        case 1:
            cout << "Isi array: ";
            for(int i = 0; i < 10; i++){
                cout << arrA[i] << " ";
            }
            cout << endl;
            break;
        case 2:
            cout << "Nilai maksimum: " << cariMaximum(arrA, 10) << endl;
            break;
        case 3:
            cout << "Nilai minimum: " << cariMinimum(arrA, 10) << endl;
            break;
        case 4:
            float rataRata;
            hitungRataRata(arrA, 10, rataRata);
            cout << "Nilai rata-rata: " << rataRata << endl;
            break;
        default:
            cout << "Menu yang dipilih tdk ada ya maniezzz" << endl;
    }
    return 0;
}