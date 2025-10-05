# <h1 align="center">Laporan Praktikum Modul 2 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Kedua)</h1>
<p align="center">Regita Hutri Cahyaningrum - 103112430115</p>

## Dasar Teori
Array merupakan struktur data linear yang menyimpan elemen-elemen dalam memori secara berurutan. Dalam C++, array satu dimensi digunakan untuk merepresentasikan vektor, sedangkan array dua dimensi digunakan untuk menyimpan data dalam bentuk matriks. Operasi pada matriks seperti penjumlahan, pengurangan, dan perkalian dapat diimplementasikan dengan perulangan bersarang sesuai dengan kaidah aljabar linear dasar. Hal ini menjadi fondasi penting dalam pemrograman numerik maupun pengolahan data ilmiah [1].

Selain array, C++ menyediakan mekanisme pointer dan reference untuk mengelola data secara efisien. Pointer menyimpan alamat memori suatu variabel dan memungkinkan fungsi memodifikasi data asli melalui dereferensi. Sementara itu, reference merupakan alias dari variabel yang lebih sederhana secara sintaksis, namun tetap efektif untuk melakukan operasi seperti pertukaran nilai. Kedua konsep ini penting karena memberikan fleksibilitas dalam pengolahan data dan penghematan memori program [2].

Penggunaan fungsi dan prosedur juga mendukung modularisasi kode agar lebih terstruktur. Fungsi digunakan untuk mengembalikan nilai, misalnya mencari maksimum dari suatu array, sedangkan prosedur dipakai untuk menjalankan operasi tanpa mengembalikan nilai, misalnya menampilkan isi matriks. Dalam praktiknya, kombinasi array, pointer, reference, fungsi, dan prosedur membantu menyelesaikan berbagai permasalahan komputasi dasar dengan cara yang lebih terorganisir.

Menurut Davies, pengembangan pustaka matriks di C++ perlu mendukung operasi matematis yang efisien dengan menerapkan operator overloading dan optimisasi memori sehingga kode program lebih dekat dengan notasi aljabar formal [1]. Hal ini sejalan dengan penelitian lain yang menekankan bahwa representasi array dan matriks yang tepat akan sangat memengaruhi performa program numerik [2]. Lebih lanjut, Boritov juga menegaskan bahwa pemahaman konsep dasar matriks dalam pemrograman C++ menjadi kunci dalam pengembangan aplikasi ilmiah maupun teknik yang kompleks [3].

## Guided 

### 1. Array Satu Dimensi

```C++
#include <iostream>
using namespace std;

int main(){
    int arr[5];

    for(int i = 0; i < 5; i++){
        cout << "Masukkan value indeks ke-" << i << ": ";
        cin >> arr[i];
    }
    int j = 0;
    while(j < 5){
        cout << "isi indeks ke-" << j << ": " << arr[j] << endl;
        j++;
    }
    return 0;
}
```
Program ini meminta pengguna memasukkan 5 nilai ke dalam array melalui perulangan for. Setelah itu, program menampilkan kembali semua isi array menggunakan perulangan while, dengan menampilkan indeks dan nilai yang tersimpan pada tiap posisi.

### 2. Array Dua Dimensi

```C++
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
```
Program ini melakukan operasi matriks 2x2. Matriks arrA dan arrB dijumlahkan elemen per elemen lalu hasilnya disimpan di arrC. Kemudian, program menghitung perkalian matriks dengan tiga perulangan bersarang dan hasilnya disimpan di arrD. Fungsi tampilkanHasil() digunakan untuk mencetak matriks hasil penjumlahan (arrC) dan perkalian (arrD).

### 3. Pointer

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y){ 
    int temp;
    temp = *x; 
    *x = *y;   
    *y = temp; 
}

int main(){
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Nilai a: " << a << endl;
    cout << "Alamat a: " << &a << endl;
    cout << "Nilai ptr (alamat a): " << ptr << endl;
    cout << "Nilai yang ditunjuk ptr: " << *ptr << endl;

    tukar(&a, &b);
    cout << "Nilai a setelah ditukar: " << a << " dan b = " << b << endl;

    return 0;
}
```
Program ini menggunakan **pointer** untuk menukar nilai variabel. Pointer ptr menunjuk ke alamat a, sehingga bisa menampilkan nilai a melalui dereferensi (*ptr). Fungsi tukar() menerima parameter pointer, lalu menukar nilai a dan b menggunakan dereferensi. Setelah dipanggil, nilai a berubah menjadi 30 dan b menjadi 20.

### 4. Reference

```C++
#include <iostream>
using namespace std;

void tukar(int &x, int &y){ 
    int temp;
    temp = x; 
    x = y;   
    y = temp; 
}

int main(){
    int a = 20, b = 30;
    int& ref = a; 

    cout << "Nilai a: " << a << endl;
    cout << "Alamat a (&a): " << &a << endl;
    cout << "Nilai ref (alias a): " << ref << endl;
    cout << "Alamat ref (&ref)" << &ref << endl;

    //mengubah nilai a melalui reference
    ref = 50;
    cout << "\nSetelah ref = 50;" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai ref: " << ref << endl;

    tukar(a, b);
    cout << "After swaping, value of a = " << a << " and b = " << b << endl;

    return 0;
}
```
Program ini menunjukkan penggunaan reference di C++. Variabel ref menjadi alias dari a, sehingga saat ref = 50, nilai a juga berubah menjadi 50. Fungsi tukar() menggunakan reference parameter untuk menukar nilai dua variabel, sehingga setelah dipanggil, nilai a dan b saling bertukar.

### 5. Procedure

```C++
#include <iostream>
using namespace std;

int cariMAX(int arr[], int ukuran){
    int MAX = arr[0];
    for(int i = 1; i < ukuran; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran){
    int totalJumlah = 0;
    for(int i = 0; i < ukuran; i++){
        totalJumlah += arr[i];
    }
    cout << "Total jumlah: " << totalJumlah << endl;

    int totalKali = 1;
    for(int i = 0; i < ukuran; i++){
        totalKali *= arr[i];
    }
    cout << "Total perkalian: " << totalKali << endl;
}
int main(){
    const int ukuran = 5;
    int arr[ukuran];
    for(int i = 0; i < ukuran; i++){
        cout << "Masukkan nilai array ke-" << i << ": ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Nilai terbesar dalam array: " << cariMAX(arr, ukuran) << endl;
    operasiAritmatika(arr, ukuran);
    return 0;
}
```
Program C++ ini meminta pengguna menginput 5 elemen array, lalu menghitung dan menampilkan nilai terbesar menggunakan fungsi cariMAX(). Selain itu, fungsi operasiAritmatika() digunakan untuk menghitung jumlah semua elemen (totalJumlah) dan hasil perkalian semua elemen (totalKali). Hasil perhitungan tersebut kemudian ditampilkan ke layar.

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3

```C++
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
```
### Output Unguided 1 :

##### Output
![Screenshot Output Unguided 1_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan2/output/Output_Modul2_Soal1.png)

Program C++ tersebut menunjukkan operasi dasar pada matriks 3x3, yaitu penjumlahan, pengurangan, dan perkalian, serta menampilkan hasilnya dengan sebuah prosedur. Fungsi tampilkanHasil() digunakan untuk mencetak isi matriks dua dimensi berukuran 3x3 ke layar. Di dalam main(), terdapat dua matriks awal, yaitu arrA dan arrB, kemudian tiga matriks hasil (arrC, arrD, arrE) yang diinisialisasi dengan nilai nol. Proses penjumlahan dilakukan dengan menjumlahkan setiap elemen yang bersesuaian dari arrA dan arrB, lalu hasilnya disimpan di arrC. Proses pengurangan dilakukan dengan mengurangkan elemen arrA dengan elemen arrB, hasilnya disimpan di arrD. Sementara itu, perkalian matriks dilakukan dengan tiga perulangan bersarang: perulangan baris i, perulangan kolom j, dan perulangan variabel k untuk menghitung hasil kali baris arrA dengan kolom arrB. Hasil perkalian tiap elemen disimpan ke dalam arrE. Program kemudian mencetak matriks A, matriks B, serta hasil penjumlahan, pengurangan, dan perkalian dengan memanggil fungsi tampilkanHasil(). Dengan demikian, program ini memberikan contoh implementasi nyata operasi aljabar linear sederhana menggunakan array dua dimensi dan nested loop.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel

### Pointer

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y, int *z){ 
    int temp;
    temp = *x; 
    *x = *y;   
    *y = *z; 
    *z = temp;
}

int main(){
    int a = 20, b = 30, c = 40;
    int *ptr;

    ptr = &a;

    cout << "======= Pointer A =======" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Alamat a: " << &a << endl;
    cout << "Nilai ptr (alamat a): " << ptr << endl;
    cout << "Nilai yang ditunjuk ptr: " << *ptr << endl << endl;

    cout << "Sebelum ditukar: a = " << a << ", b = " << b << ", dan c = " << c << endl;
    tukar(&a, &b, &c);
    cout << "Setelah ditukar: a = " << a << ", b = " << b << ", dan c = " << c << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output Pointer
![Screenshot Output Unguided 2_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan2/output/Output_Modul2_Soal2A.png)

Program C++ tersebut memperlihatkan penggunaan pointer untuk mengakses dan memodifikasi nilai variabel, serta implementasi fungsi pertukaran dengan parameter pointer. Di dalam fungsi tukar(), parameter x, y, dan z bertipe pointer, sehingga nilai yang ditukar adalah isi dari alamat memori yang ditunjuk pointer tersebut. Prosesnya adalah menyimpan nilai *x (nilai dari a) ke variabel sementara temp, kemudian *x diisi dengan *y (nilai b), *y diisi dengan *z (nilai c), dan terakhir *z diisi dengan temp. Hal ini membuat nilai variabel asli a, b, dan c benar-benar berubah karena pointer menunjuk langsung ke alamat memori variabel tersebut. Pada bagian main(), variabel a = 20, b = 30, dan c = 40 didefinisikan, lalu pointer ptr diarahkan ke alamat a. Program mencetak nilai a, alamat a, nilai pointer ptr (yang berisi alamat a), serta nilai yang ditunjuk oleh pointer ptr (yaitu isi a). Setelah itu, program menampilkan nilai a, b, dan c sebelum dan sesudah dipanggil fungsi tukar(&a, &b, &c). Hasil akhirnya, nilai a menjadi 30, b menjadi 40, dan c menjadi 20, sesuai dengan logika pertukaran dalam fungsi. Program ini menunjukkan bagaimana pointer bekerja untuk memanipulasi data secara langsung melalui alamat memori.

### Reference

```C++
#include <iostream>
using namespace std;

void tukar(int &x, int &y, int z){ 
    int temp;
    temp = x; 
    x = y;   
    y = z; 
    z = temp;
}

int main(){
    int a = 20, b = 30, c = 40;
    int& ref = a; 

    cout << "Nilai a: " << a << endl;
    cout << "Alamat a (&a): " << &a << endl;
    cout << "Nilai ref (alias a): " << ref << endl;
    cout << "Alamat ref (&ref)" << &ref << endl << endl;

    //mengubah nilai a melalui reference
    
    cout << "Before swaping, value of a = " << a << ", b = " << b << ", dan c = " << c << endl; 
    ref = 50;
    cout << "\nSetelah ref = 50;" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai ref: " << ref << endl << endl;
    tukar(a, b, c);
    cout << "After swaping, value of a = " << a << ", b = " << b << ", dan c = " << c << endl; 

    return 0;
}
```
### Output Unguided 2 :

##### Output Reference
![Screenshot Output Unguided 2_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan2/output/Output_Modul2_Soal2B.png)

Program C++ tersebut mendemonstrasikan penggunaan reference (alias variabel) dan fungsi pertukaran nilai. Pada fungsi tukar(), parameter x dan y dideklarasikan sebagai reference sehingga perubahan pada variabel ini akan langsung memengaruhi nilai aslinya, sedangkan z hanya parameter biasa (pass by value) sehingga perubahan pada z tidak memengaruhi variabel asli. Di dalam main(), terdapat tiga variabel a = 20, b = 30, dan c = 40. Variabel ref didefinisikan sebagai reference dari a, sehingga ref menjadi alias dari a dan memiliki alamat memori yang sama. Program kemudian mencetak nilai dan alamat dari a serta ref untuk menunjukkan keterkaitannya. Setelah itu, nilai a diubah melalui ref dengan memberikan ref = 50, yang otomatis juga mengubah nilai a menjadi 50. Selanjutnya, fungsi tukar(a, b, c) dipanggil. Di dalam fungsi, nilai a dipindahkan ke variabel sementara temp, lalu a diisi dengan b, b diisi dengan c, dan z (yang hanya salinan dari c) diubah nilainya tetapi tidak berpengaruh pada variabel asli c. Hasil akhirnya, nilai a berubah menjadi 30, nilai b berubah menjadi 40, sedangkan nilai c tetap 40 karena parameter z bukan reference. Program ini sekaligus memperlihatkan perbedaan pass by reference dan pass by value pada fungsi di C++.

### 3. Diketahui sebuah array 1 dimensi sebagai berikut : arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! 

```C++
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
```
### Output Unguided 3 :

##### Output 
![Screenshot Output Unguided 3_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan2/output/Output_Modul2_Soal3(1).png)

![Screenshot Output Unguided 3_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan2/output/Output_Modul2_Soal3(2).png)

Program C++ tersebut adalah sebuah program sederhana yang menggunakan array dan fungsi untuk melakukan beberapa operasi dasar pada data. Di dalamnya terdapat array arrA berisi 10 bilangan integer. Program menyediakan menu dengan 4 pilihan, yaitu menampilkan isi array, mencari nilai maksimum, mencari nilai minimum, dan menghitung nilai rata-rata. Fungsi cariMinimum() digunakan untuk mencari nilai terkecil dalam array dengan cara membandingkan setiap elemen. Fungsi cariMaximum() digunakan untuk mencari nilai terbesar dengan prinsip yang sama. Fungsi hitungRataRata() menjumlahkan semua elemen array lalu membaginya dengan jumlah elemen untuk mendapatkan nilai rata-rata, hasilnya dikembalikan melalui parameter referensi. Pada bagian main(), program menampilkan menu, menerima input dari pengguna, lalu menjalankan perintah sesuai pilihan dengan menggunakan switch-case. Jika input tidak sesuai menu, program akan menampilkan pesan kesalahan. Dengan demikian, program ini menunjukkan konsep dasar array, fungsi, perulangan, parameter referensi, serta kontrol alur menggunakan switch-case.

## Kesimpulan
Praktikum ini menunjukkan bahwa penggunaan array, matriks, pointer, reference, fungsi, dan prosedur dalam C++ merupakan dasar penting untuk memahami pengolahan data. Array satu dimensi dapat digunakan untuk operasi sederhana seperti mencari nilai maksimum, minimum, dan rata-rata, sedangkan array dua dimensi merepresentasikan matriks yang dapat dijumlahkan, dikurangkan, maupun dikalikan menggunakan perulangan bersarang. Pointer memungkinkan manipulasi data melalui alamat memori, sementara reference mempermudah operasi dengan menjadikan variabel sebagai alias. Dengan dukungan fungsi dan prosedur, program menjadi lebih modular, terstruktur, dan efisien. Konsep-konsep dasar ini sekaligus menjadi landasan bagi pengembangan aplikasi komputasi yang lebih kompleks, termasuk implementasi pustaka matriks yang efisien sebagaimana dibahas dalam penelitian.

## Referensi
[1] R. B. Davies, Writing a Matrix Package in C++, Statistics Research Associates Limited, 1993. [Online]. Available: https://statsresearch.co.nz/pdf/newmat1.pdf
<br>[2] S. Zheng, et al., “C++ vector and matrix class library for finite element method,” SoftwareX, vol. 27, 2024. [Online]. Available: https://www.sciencedirect.com/science/article/pii/S2352711024001961
<br>[3] M. M. Boritov, “Working With Matrices in the C++ Programming Language Environment,” International Multidisciplinary Journal for Research & Development, vol. 12, no. 5, 2025. [Online]. Available: https://www.ijmrd.in/index.php/imjrd/article/view/3114
