# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Regita Hutri Cahyaningrum - 103112430115</p>

## Dasar Teori
Konsep array dan pointer dalam C++ memungkinkan pengguna untuk mengakses dan memanipulasi elemen data lewat dua pendekatan utama, yaitu akses dengan indeks dan akses melalui pointer. Penelitian oleh Logozar, Mikac, dan Radošević [1] menunjukkan bahwa dalam konteks static array, akses menggunakan indeks vs pointer arithmetic bisa memiliki performa yang sangat mirip, tergantung optimasi compiler dan struktur data. Ini berarti pendekatan manual menggunakan indeks (seperti pada pertukaran elemen array) bukan selalu kurang efisien dibanding pointer.

Selanjutnya, dari aspek pembelajaran, Donyina & Heckel [2] menggarisbawahi bahwa mahasiswa sering mengalami kesulitan memahami fungsi pointer, dereference, dan manipulasi alamat memori. Mereka meneliti penggunaan metode visual, seperti graph transformations, yang membantu memperjelas bagaimana pointer bekerja, terutama dalam operasi address-of (&) dan dereference (*), serta bagaimana array merepresentasikan blok alamat memori yang bersambung. Metode ini terbukti membantu mempercepat pemahaman konsep-konsep abstrak di C.

Selanjutnya, jurnal dari ACM [3] menyoroti pentingnya abstraksi data dan definisi formal tipe serta operasi pada tipe tersebut. ADT mendukung modularitas, keamanan tipe data (type safety), dan kejelasan spesifikasi fungsi/prosedur dalam program. Ini sangat relevan dengan penggunaan struct dan fungsi/prosedur khusus (input, output, tukar) untuk mengelola data, menjaga agar operasi terhadap data sesuai kontrak atau spesifikasi yang ditetapkan.

Tambahan dari sumber di ScienceDirect tentang Abstract Data Type menguatkan bahwa ADT adalah konsep fundamental dalam ilmu komputer yang mendeskripsikan data dan operasi-operasi yang valid pada data tersebut secara abstrak, tanpa memperlihatkan implementasi internalnya. ADT memungkinkan programmer merancang modul atau komponen dengan interface yang jelas, sementara detail bagaimana data disimpan atau bagaimana operasinya diimplementasikan bisa disembunyikan. Hal ini meningkatkan abstraction, modularity, dan encapsulation dalam pengembangan perangkat lunak.

## Guided 

### 1. Sebelum Implementasi ADT

```C++
#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    float nilai1, nilai2;
};

void inputMhs(mahasiswa &m){
    cout << "Masukkan nama: "; 
    cin >> m.nama;
    cout << "Masukkan nilai 1: "; 
    cin >> m.nilai1;
    cout << "Masukkan nilai 2: "; 
    cin >> m.nilai2;
}

float rata2(mahasiswa m){
    return (m.nilai1 + m.nilai2) / 2;
}

int main(){
    mahasiswa mhs; //pemanggilan struct (ADT)
    inputMhs(mhs); //pemanggilan procedure
    cout << "Rata rata : " << rata2(mhs) << endl; //pemanggilan function
    return 0;
}
```
Program di atas merupakan program sederhana dalam bahasa C++ yang menggunakan struct untuk menyimpan data mahasiswa. Struktur mahasiswa memiliki tiga atribut, yaitu nama, nilai1, dan nilai2. Fungsi inputMhs() digunakan untuk menginput data mahasiswa melalui parameter referensi (&), sehingga data yang dimasukkan langsung tersimpan di variabel asli. Fungsi rata2() menghitung nilai rata-rata dari dua nilai yang dimiliki mahasiswa dengan rumus (nilai1 + nilai2) / 2. Pada fungsi main(), program membuat satu variabel mhs bertipe mahasiswa, lalu memanggil fungsi inputMhs() untuk mengisi datanya, dan akhirnya menampilkan hasil perhitungan rata-rata dengan memanggil fungsi rata2(). Program ini menunjukkan penggunaan dasar struct, fungsi prosedural, dan perhitungan sederhana dalam C++.

### 2. Implementasi ADT untuk Pelajaran

##### Source Code main.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main(){
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
##### Source Code pelajaran.cpp
```C++
#include "pelajaran.h"

//implementasi function create_pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel){
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

//implementasi prosedur tampil_pelajaran
void tampil_pelajaran(pelajaran pel){
    cout << "nama pelajaran: " << pel.namaMapel << endl;
    cout << "kode: " << pel.kodeMapel << endl;
}
```
##### Source Code pelajaran.h
```C++
//header guard digunakan untuk mencegah file header yang sama di-include lebih dari sekali dalam satu program
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

//deklarasi ADT pelajaran
struct pelajaran{
    string namaMapel;
    string kodeMapel;
};

//function untuk membuat data pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel);

//prosedur untuk menampilkan data pelajaran
void tampil_pelajaran(pelajaran pel);

#endif
```
Program di atas merupakan implementasi ADT (Abstract Data Type) dalam C++ untuk merepresentasikan data pelajaran secara terstruktur dan modular. Struktur pelajaran didefinisikan di file pelajaran.h dengan dua atribut, yaitu namaMapel dan kodeMapel, serta dilengkapi fungsi create_pelajaran() untuk membuat data pelajaran baru dan prosedur tampil_pelajaran() untuk menampilkannya. File pelajaran.cpp berisi implementasi kedua fungsi tersebut, sedangkan main.cpp digunakan untuk menjalankan program dengan membuat objek pelajaran menggunakan nilai “Struktur Data” dan “STD”. Program ini menunjukkan penerapan konsep abstraksi dan modularitas, sehingga kode lebih rapi, mudah dipelihara, dan dapat digunakan kembali.

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3 * uts + 0.4 * uas + 0.3 * tugas.

```C++
#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    string nim;
    int nilaiUTS;
    int nilaiUAS;
    int nilaiTugas;
    float nilaiAkhir;
};

float nilaiAkhir(mahasiswa mhs){
    return 0.3 * mhs.nilaiUTS + 0.4 * mhs.nilaiUAS + 0.3 * mhs.nilaiTugas;
} 

void inputMhs(mahasiswa &mhs){
    cout << "Masukkan Nama: ";
    cin >> mhs.nama;
    cout << "Masukkan NIM: ";
    cin >> mhs.nim;
    cout << "Masukkan Nilai UTS: ";
    cin >> mhs.nilaiUTS;
    cout << "Masukkan Nilai UAS: ";
    cin >> mhs.nilaiUAS;
    cout << "Masukkan Nilai Tugas: ";
    cin >> mhs.nilaiTugas;

    mhs.nilaiAkhir = nilaiAkhir(mhs);
}

void outputMhs(mahasiswa mhs[], int n){
    cout << "\n=== Daftar Nilai Mahasiswa ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama        : " << mhs[i].nama << endl;
        cout << "NIM         : " << mhs[i].nim << endl;
        cout << "Nilai UTS   : " << mhs[i].nilaiUTS << endl;
        cout << "Nilai UAS   : " << mhs[i].nilaiUAS << endl;
        cout << "Nilai Tugas : " << mhs[i].nilaiTugas << endl;
        cout << "Nilai Akhir : " << mhs[i].nilaiAkhir << endl;
        cout << "-----------------------------";
    }
    cout << endl;
}

int main(){
    mahasiswa mhs[10];
    int n;

    cout << "Masukan data mahasiswa (max 10): ";
    cin >> n;

    if (n > 10) {
        cout << "Maksimal hanya bisa input 10 data mahasiswa." << endl;
        return 0;
    } else{
        for (int i = 0; i < n; i++) {
            cout << "\nData Mahasiswa ke-" << i + 1 << endl;
            inputMhs(mhs[i]);
        }
    }

    outputMhs(mhs, n);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan3/output/Output_Modul3_Soal1(1).png)
![Screenshot Output Unguided 1_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan3/output/Output_Modul3_Soal1(2).png)

Program di atas merupakan contoh penerapan struktur data struct dalam bahasa C++ yang digunakan untuk menyimpan dan mengelola data mahasiswa secara terstruktur. Di dalam program ini, didefinisikan sebuah struktur bernama mahasiswa yang memiliki beberapa anggota (atribut) yaitu nama, nim, nilaiUTS, nilaiUAS, nilaiTugas, dan nilaiAkhir. Atribut-atribut ini digunakan untuk menyimpan identitas serta komponen nilai seorang mahasiswa. Dengan menggunakan struct, data yang berhubungan dapat disimpan dalam satu kesatuan sehingga lebih mudah diakses dan diolah dalam program.

Selanjutnya, terdapat sebuah fungsi bernama nilaiAkhir() yang bertugas untuk menghitung nilai akhir mahasiswa berdasarkan bobot nilai yang telah ditentukan, yaitu 30% dari nilai UTS, 40% dari nilai UAS, dan 30% dari nilai tugas. Fungsi ini menerima parameter berupa objek bertipe mahasiswa dan mengembalikan hasil perhitungan dalam bentuk nilai float. Dengan adanya fungsi ini, perhitungan nilai akhir menjadi lebih efisien dan tidak perlu ditulis berulang kali di bagian lain program.

Kemudian, fungsi inputMhs() digunakan untuk melakukan proses input data mahasiswa. Fungsi ini menerima parameter berupa referensi ke objek mahasiswa agar data yang dimasukkan langsung disimpan ke dalam variabel asli, bukan salinannya. Di dalam fungsi ini, pengguna diminta untuk mengisi nama, NIM, serta nilai UTS, UAS, dan tugas. Setelah semua nilai diinput, fungsi tersebut secara otomatis memanggil nilaiAkhir() untuk menghitung dan menyimpan nilai akhirnya ke dalam atribut nilaiAkhir.

Fungsi outputMhs() berperan untuk menampilkan seluruh data mahasiswa yang telah diinput sebelumnya. Fungsi ini menggunakan array dari struct mahasiswa sebagai parameter dan melakukan perulangan untuk mencetak data masing-masing mahasiswa, termasuk nilai akhir yang sudah dihitung sebelumnya. Setiap mahasiswa ditampilkan dengan format yang jelas agar pengguna dapat membaca hasilnya dengan mudah.

Pada bagian main(), program diawali dengan mendeklarasikan array mhs berukuran 10 untuk menampung maksimal sepuluh data mahasiswa. Pengguna diminta untuk menentukan jumlah mahasiswa yang akan diinput. Jika jumlahnya melebihi 10, program akan menampilkan pesan kesalahan dan berhenti. Namun, jika jumlahnya sesuai, program akan menjalankan perulangan untuk memanggil fungsi inputMhs() dan mengisi data untuk setiap mahasiswa. Setelah semua data dimasukkan, program memanggil fungsi outputMhs() untuk menampilkan seluruh data beserta hasil perhitungan nilai akhirnya.

Secara keseluruhan, program ini menunjukkan bagaimana konsep dasar pemrograman berorientasi data dapat diterapkan menggunakan struct, fungsi, array, dan parameter referensi. Program ini juga mengajarkan pentingnya pemisahan tugas antar fungsi untuk membuat kode lebih terstruktur, mudah dipahami, dan efisien. Tanpa menggunakan pointer, program tetap mampu mengolah data secara dinamis melalui parameter referensi (&), yang memastikan setiap perubahan pada data mahasiswa akan langsung tersimpan dalam array utama.

### 2. Membuat ADT Pelajaran

##### Source Code pelajaran.h
```C++
//header guard digunakan untuk mencegah file header yang sama di-include lebih dari sekali dalam satu program
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

//deklarasi ADT pelajaran
struct pelajaran{
    string namaMapel;
    string kodeMapel;
};

//function untuk membuat data pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel);

//prosedur untuk menampilkan data pelajaran
void tampil_pelajaran(pelajaran pel);

#endif
```
##### Source Code pelajaran.cpp
```C++
#include "pelajaran.h"

//implementasi function create_pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel){
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

//implementasi prosedur tampil_pelajaran
void tampil_pelajaran(pelajaran pel){
    cout << "Nama Mata Kuliah: " << pel.namaMapel << endl;
    cout << "Kode: " << pel.kodeMapel << endl;
}
```
##### Source Code main.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main(){
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan3/output/Output_Modul3_Soal22.png)

Program di atas merupakan implementasi ADT (Abstract Data Type) dalam bahasa C++ untuk merepresentasikan data pelajaran. Program ini dibagi menjadi tiga bagian utama, yaitu file main.cpp, pelajaran.cpp, dan pelajaran.h. Pembagian ini mengikuti konsep *modular programming*, di mana setiap file memiliki tanggung jawab yang berbeda agar program lebih terstruktur, mudah dipelihara, dan dapat digunakan kembali di proyek lain.

Pada file pelajaran.h, didefinisikan struktur data pelajaran yang memiliki dua atribut yaitu namaMapel (nama mata pelajaran) dan kodeMapel (kode pelajaran). File header ini juga dilengkapi dengan **header guard** menggunakan #ifndef, #define, dan #endif untuk mencegah agar file tidak di-*include* lebih dari satu kali dalam proses kompilasi, karena hal itu dapat menyebabkan error duplikasi. Selain itu, pada file ini juga dideklarasikan dua fungsi penting, yaitu create_pelajaran() yang bertugas membuat data pelajaran baru, dan tampil_pelajaran() yang digunakan untuk menampilkan informasi pelajaran ke layar.

Selanjutnya, pada file pelajaran.cpp, kedua fungsi tersebut diimplementasikan. Fungsi create_pelajaran() menerima dua parameter bertipe string, yaitu namaMapel dan kodepel, lalu mengembalikan sebuah objek pelajaran yang sudah diisi dengan nilai-nilai tersebut. Implementasi ini menunjukkan konsep encapsulation, di mana pembuatan objek dilakukan melalui fungsi khusus, bukan secara langsung di luar modul. Kemudian, prosedur tampil_pelajaran() bertugas menampilkan isi struktur pelajaran ke layar dengan format yang jelas, yaitu menampilkan nama pelajaran dan kode pelajarannya.

Terakhir, file main.cpp berfungsi sebagai titik awal eksekusi program. Di dalamnya, variabel namapel dan kodepel diinisialisasi dengan nilai “Struktur Data” dan “STD”. Nilai ini kemudian dikirim ke fungsi create_pelajaran() untuk membuat objek pelajaran. Hasil dari fungsi tersebut disimpan dalam variabel pel, dan kemudian ditampilkan ke layar menggunakan prosedur tampil_pelajaran().

Secara keseluruhan, program ini menunjukkan penerapan konsep ADT (Abstract Data Type), di mana tipe data pelajaran didefinisikan secara terpisah dari logika program utama. Hal ini membuat kode menjadi lebih rapi, mudah dikembangkan, dan mendukung prinsip reusability dan abstraction dalam pemrograman berorientasi objek.

### 3. Buatlah program dengan ketentuan :
###     - 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
###     - fungsi/prosedur yang menampilkan isi sebuah array integer 2D
###     - fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
###     - fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan3/output/Output_Modul3_Soal33.png)

Program di atas merupakan implementasi lengkap yang menunjukkan cara menukar isi dua array dua dimensi berukuran 3x3 dengan dua pendekatan berbeda, yaitu pertukaran secara manual tanpa pointer dan pertukaran menggunakan pointer. Program ini menggunakan konsep dasar dari array multidimensi, fungsi, dan pointer dalam bahasa C++ untuk memperlihatkan bagaimana data dapat diubah atau dipertukarkan baik secara langsung maupun melalui manipulasi alamat memori.

Pada bagian awal, fungsi tampilkanArray() digunakan untuk menampilkan isi dari array dua dimensi. Fungsi ini menggunakan dua buah perulangan bersarang (for) untuk mengakses setiap elemen berdasarkan indeks baris (i) dan kolom (j). Di dalamnya, setiap nilai elemen ditampilkan secara berurutan, dan setelah setiap baris selesai, program mencetak baris baru dengan cout << endl;. Hal ini membuat tampilan array terlihat dalam bentuk matriks yang rapi di layar.

Selanjutnya, terdapat fungsi tukar(int *x, int *y) yang merupakan implementasi pertukaran nilai menggunakan pointer. Fungsi ini menerima dua parameter bertipe pointer (int *x dan int *y), kemudian menggunakan variabel sementara temp untuk menyimpan nilai yang ditunjuk oleh pointer x, agar nilainya tidak hilang saat proses penukaran dilakukan. Setelah itu, nilai yang ditunjuk oleh x diisi dengan nilai dari y, dan nilai yang ditunjuk oleh y diisi dengan temp. Dengan menggunakan pointer, fungsi ini bekerja langsung pada alamat memori dari variabel yang ditukar, sehingga perubahan akan langsung memengaruhi data aslinya tanpa perlu mengembalikan nilai.

Pada bagian main(), dua array dua dimensi dideklarasikan, yaitu arrA dan arrB, masing-masing berukuran 3x3 dan berisi nilai-nilai yang berbeda. Array arrA berisi angka dari 1 sampai 9, sedangkan arrB berisi angka dari 11 sampai 19. Program pertama menampilkan isi kedua array menggunakan fungsi tampilkanArray(). Setelah itu, dilakukan proses pertukaran manual tanpa pointer, di mana elemen dari kedua array ditukar satu per satu menggunakan variabel sementara temp. Pertukaran ini dilakukan dalam dua perulangan bersarang yang mengakses seluruh elemen array. Setelah proses selesai, program menampilkan hasil pertukaran, di mana seluruh isi arrA dan arrB telah bertukar posisi.

Kemudian, program melanjutkan ke bagian kedua, yaitu pertukaran isi array menggunakan pointer. Proses ini dilakukan dengan memanggil fungsi tukar() di dalam dua perulangan for yang sama seperti sebelumnya. Namun, perbedaannya terletak pada cara pemanggilan fungsi, di mana elemen array dikirimkan ke fungsi tukar() dengan menggunakan alamat memorinya (&arrA[i][j] dan &arrB[i][j]). Hal ini memungkinkan fungsi tukar() melakukan operasi pertukaran langsung pada data yang tersimpan di memori tanpa perlu mengembalikan nilai. Setelah pertukaran kedua selesai, program kembali menampilkan isi kedua array, dan hasilnya menunjukkan bahwa isi array telah kembali seperti semula.

Secara keseluruhan, program ini mengilustrasikan dua konsep penting dalam pemrograman C++ yaitu manipulasi array dua dimensi dan penggunaan pointer untuk mengakses serta memodifikasi data di memori secara langsung. Dengan pendekatan manual, pertukaran dilakukan menggunakan variabel sementara dalam ruang lingkup fungsi utama. Sementara itu, dengan pendekatan pointer, pertukaran dilakukan melalui referensi memori yang lebih efisien dan fleksibel. Program ini juga menunjukkan pentingnya penggunaan fungsi untuk membuat kode lebih modular, mudah dibaca, serta lebih terstruktur dalam melakukan operasi berulang seperti penukaran elemen array.

## Kesimpulan
Penerapan konsep ADT, struct, fungsi, dan pointer dalam bahasa C++ sangat penting untuk membangun program yang terstruktur, modular, dan efisien. Dengan menggunakan struct, data yang saling berkaitan dapat disatukan dalam satu kesatuan logis yang memudahkan proses pengelolaan dan pemanggilan data. Implementasi ADT mendukung prinsip abstraction dan encapsulation, di mana detail implementasi disembunyikan dari pengguna dan hanya operasi penting yang ditampilkan. Pemisahan kode ke dalam file header (.h), file implementasi (.cpp), dan program utama juga memperlihatkan manfaat dari konsep modular programming, yang membuat kode lebih mudah dipelihara, diperluas, dan digunakan kembali di berbagai proyek.

Selain itu, penggunaan parameter referensi (&) dan pointer menunjukkan dua pendekatan berbeda dalam manipulasi data. Parameter referensi memungkinkan perubahan langsung terhadap variabel tanpa menyalin nilai, sedangkan pointer memberikan kendali penuh terhadap alamat memori yang ditunjuk, sehingga efisien untuk operasi tingkat rendah seperti pertukaran data antar array dua dimensi. Melalui berbagai implementasi seperti perhitungan nilai mahasiswa, representasi data pelajaran, dan pertukaran isi array, praktikum ini membuktikan bahwa ADT bukan sekadar konsep teoritis, melainkan fondasi utama dalam perancangan sistem perangkat lunak yang aman, efisien, serta mudah dikembangkan karena setiap komponen memiliki fungsi dan tanggung jawab yang jelas.

## Referensi
[1] Logozar, R., Mikac, M., & Radošević, D. (2022). Exploring the Access to the Static Array Elements via Indices and via Pointers — the Introductory C++ Case. Proceedings of the Central European Conference on Information and Intelligent Systems, CECIIS 2022. diakses melalui ResearchGate.
<br>[2] Donyina, A., & Heckel, R. (2025). Pedagogy of Teaching Pointers in the C Programming Language using Graph Transformations. arXiv:2503.20469.
<br>[3] Judul: Relational Synthesis of Recursive Programs via Integrity Constraints (DOI:10.1145/3632870), Association for Computing Machinery.
<br>[4] ScienceDirect Topics. Abstract Data Type. Diakses melalui ScienceDirect.
