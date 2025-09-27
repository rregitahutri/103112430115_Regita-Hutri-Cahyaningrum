# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Regita Hutri Cahyaningrum - 103112430115</p>

## Dasar Teori
isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
contoh :
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.

### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 

### 1. Input/Output

```C++
#include <iostream>
using namespace std;

int main(){
    int angka;
    cout << "Masukkan angka : ";
    cin >> angka;

    cout << "Angka yang diinput :" << angka << endl;
    return 0;
}
```
penjelasan singkat guided 1

### 2. Operator Aritmatika

```C++
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
```
penjelasan singkat guided 2

### 3. Percabangan

```C++
#include <iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "Masukkan angka1 : ";
    cin >> angka1;
    cout << "Masukkan angka2 : ";
    cin >> angka2;

    if (angka1 > angka2){
        cout << angka1 << " lebih besar dari " << angka2 << endl;
    } else if (angka1 < angka2){
        cout << angka1 << " lebih kecil dari " << angka2 << endl;
    } else if (angka1 == angka2){
        cout << angka1 << " sama dengan " << angka2 << endl;
    }

    if (angka1 != angka2){
        cout << angka1 << " tidak sama dengan " << angka2 << endl;
    }
    return 0;
}
```
penjelasan singkat guided 3

### 4. Perulangan For

```C++
#include <iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "Masukkan angka1 : ";
    cin >> angka1;
    cout << "Masukkan angka2 : ";
    cin >> angka2;
    
    for (int i = 0; i < angka1; i++){ //increment
        cout << i << " - ";
    }
    cout << endl;
    for (int i = 20; i > angka2; i--){ //decrement
        cout << i << " - ";
    }
    return 0;
}
```
penjelasan singkat guided 4

### 5. Struct

```C++
#include <iostream>
using namespace std;

int main(){
    const int jumlah = 5;

    struct rapot{
        char nama[5];
        int nilai;
    };

    rapot siswa[jumlah];

    for (int i = 0; i < jumlah; i++){
        cout << "masukkan nama siswa :";
        cin >> siswa[i].nama;
        cout << "masukkan nilai siswa :";
        cin >> siswa[i].nilai;
    };

    int i = 0;
    while (i < jumlah){
        cout << "nama : " << siswa[i].nama << endl;
        cout << "nilai : " << siswa[i].nilai << endl;
        i++;
    };

    return 0;
}
```
penjelasan singkat guided 5

## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/output/Output_Soal1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100.

```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/output/Output_Soal2.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. Buatlah program yang dapat memberikan input dan output sbb.

```C++
#include <iostream>
using namespace std;

int main() {
    int n, i, j;
    cout << "input: ";
    cin >> n;
    cout << "output: " << endl;

    for (i = 1; i <= n + 1; i++) {
        for (j = 1; j < i; j++) {
            cout << "  ";
        }

        for (j = n - i + 1; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (j = 1; j <= n - i + 1; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/output/Output_Soal3.png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
