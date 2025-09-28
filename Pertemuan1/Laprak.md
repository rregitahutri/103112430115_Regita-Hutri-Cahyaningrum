# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Regita Hutri Cahyaningrum - 103112430115</p>

## Dasar Teori
Bahasa C++ merupakan bahasa pemrograman tingkat tinggi yang dikembangkan sebagai perluasan dari bahasa C, dengan penambahan fitur-fitur seperti abstraksi data, operator overloading, dan konsep pemrograman berorientasi objek untuk membuat pengembangan aplikasi yang lebih kompleks lebih mudah dikelola [1]. C++ dirancang agar tetap efisien dan cepat dalam eksekusi, sehingga cocok digunakan baik untuk aplikasi perangkat lunak umum maupun sistem perangkat keras [1]. Dengan fitur-fitur tambahannya, C++ memungkinkan penggunaan konsep seperti polimorfisme, enkapsulasi, dan inheritance, yang tidak tersedia secara langsung di C [1].

Menurut Indahyati dan Rahmawati, pembelajaran C++ sebaiknya dimulai dari pemahaman algoritma dan dasar-dasar pemrograman, karena algoritma menjadi landasan utama sebelum masuk ke konsep berorientasi objek [3]. Buku tersebut juga menekankan pentingnya latihan membuat program sederhana agar mahasiswa terbiasa dalam memahami sintaks dan logika pemrograman C++ [3]. Dengan latihan secara bertahap, pemula akan mampu membangun keterampilan analisis dan pemecahan masalah yang lebih kompleks [3].

Dalam buku Pengantar Coding Berbasis C/C++, bahasa C dan C++ dibahas bersama-sama sebagai bahasa inti yang mendasari logika algoritma, tipe data, operator, struktur kontrol, dan fungsi-fungsi dasar pemrograman [2]. Buku tersebut menyajikan secara terstruktur materi mulai dari algoritma dasar, pengenalan variabel dan konstanta, hingga struktur kontrol (seperti percabangan dan perulangan) yang juga berlaku dalam lingkungan C++ [2]. Pendekatan bersama ini menekankan pentingnya memahami dasar-dasar pemrograman (seperti variabel, operator, dan kontrol alur) agar transisi ke paradigma berorientasi objek di C++ menjadi lebih mulus [2].

Struktur dasar program C++ meliputi penggunaan header file, deklarasi variabel, fungsi utama main(), dan pernyataan output/input menggunakan pustaka standar (misalnya iostream) [1]. Dalam bagian kode inti, C++ menggunakan perintah seperti std::cout dan std::cin sebagai mekanisme standar untuk output dan input pada konsol [1]. Program dijalankan melalui proses kompilasi, linking, dan eksekusi, sebagaimana pola umum bahasa pemrograman modern [1].

Secara umum, pengenalan bahasa C++ tidak bisa dilepaskan dari pemahaman konsep dasar pemrograman seperti algoritma, struktur data, tipe data dasar, dan kontrol alur, karena fondasi tersebut menjadi basis bagi implementasi konsep berorientasi objek dalam C++ [2][3]. Dengan memahami aspek-aspek dasar ini, mahasiswa atau pemrogram yang baru belajar akan lebih mudah memahami struktur kelas, objek, pewarisan, dan interaksi antar objek dalam proyek perangkat lunak yang lebih besar [3].

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
Pertama, program diatas mendeklarasikan variabel angka bertipe integer. Lalu, dengan cout, program akan menampilkan pesan sebagai instruksi input. Dengan cin untuk menginput angka, setelah menginput suatu angka nilainya disimpan ke variabel. Terakhir, program menampilkan kembali angka yang sudah diinput tadi.

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
Program akan meminta memasukkan dua bilangan bulat (angka1 dan angka2) sebagai inputan, lalu melakukan lima operasi dasar aritmatika: penjumlahan (+), pengurangan (-), perkalian (*), pembagian (/), dan modulus (%). Hasil dari masing-masing operasi itu kemudian ditampilkan dengan cout.

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
Program diatas meminta dua inputan bilangan bulat (angka1 dan angka2), kemudian membandingkan keduanya. Jika angka1 lebih besar dari angka2, maka outputnya berupa pesan bahwa angka1 lebih besar. Jika lebih kecil, outputnya adalah pesan sebaliknya. Dan jika nilainya sama, outputnya pesan bahwa keduanya sama. 

Lalu ada percabangan tambahan yang memeriksa apakah angka1 tidak sama dengan angka2 menggunakan operator !=. Jika benar, program memberi pesan  kedua angka tidak sama. Jadi, program ini mengimplementasikan cara kerja operator relasional (>, <, ==, !=) serta alur logika percabangan untuk membandingkan nilai.

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
Awalnya, program meminta dua input bilangan bulat (angka1 dan angka2). Pada perulangan pertama, for (int i = 0; i < angka1; i++), program mencetak nilai i mulai dari 0 hingga kurang dari angka1 secara bertambah (increment). Dilanjut perulangan kedua, for (int i = 20; i > angka2; i--), mencetak nilai i mulai dari 20 hingga lebih besar dari angka2 secara berkurang (decrement). Kesimpulannya, perulangan for dapat digunakan untuk menghitung maju maupun mundur sesuai kondisi yang ditentukan.

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
Struct rapot berisi dua anggota, yaitu nama (tipe char[5]) untuk menyimpan nama siswa, dan nilai (tipe int) untuk menyimpan nilai. Kemudian terdapat array siswa dengan ukuran jumlah = 5, yang nantinya bisa untuk menampung data 5 siswa. Dengan memakai perulangan for, kemudian diminta menginputkan nama dan nilai setiap siswa, lalu data tersebut disimpan dalam array siswa. Setelah itu, dengan perulangan while, program menampilkan kembali nama dan nilai dari semua siswa yang sudah diinput. Program ini memperlihatkan bagaimana struct digunakan untuk mengelompokkan data yang terkait.

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
![Screenshot Output Unguided 1_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan1/output/Output_Soal1.png)

Program di atas adalah program sederhana untuk melakukan operasi aritmatika dasar menggunakan dua bilangan bertipe float. Pertama, program meminta inputan dua angka (x dan y). Setelah itu, program menampilkan hasil dari empat operasi: penjumlahan (x + y), pengurangan (x - y), perkalian (x * y), dan pembagian (x / y). Khusus untuk pembagian, program memeriksa pengecekan kondisi if (y != 0) agar tidak terjadi error pembagian dengan nol, karena secara matematis dan komputasi itu tidak valid. Jika y bernilai nol, program memberi output "Tidak bisa dibagi dengan 0”. Dengan penggunaan tipe data float, hasil operasi dapat berupa bilangan desimal, jadi lebih fleksibel dibandingkan int yang hanya menampung bilangan bulat.

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
![Screenshot Output Unguided 2_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan1/output/Output_Soal2.png)

Program di atas adalah program konversi angka ke bentuk tulisan bahasa Indonesia untuk bilangan bulat positif dari 0 sampai 100. Menggunakan struct bernama convertN. Di dalam struct ada dua fungsi:

1. puluhan(int n) → digunakan untuk menyimpan angka kelipatan 10 atau angka puluhan (20–99). Cara kerja fungsi ini yaitu dengan membagi angka dengan 10 untuk mendapatkan nilai puluhan, lalu mengambil sisa bagi (%) untuk mendapatkan satuannya. Hasil awal berupa kata “[puluh]” (misalnya "tujuh puluh"). Jika ada sisa, maka ditambahkan satuan di belakangnya (misalnya "tujuh puluh sembilan").

2. convert(int n) → digunakan untuk menentukan hasil konversi berdasarkan rentang nilai n. Jika n < 12, langsung diambil dari array satuan. Jika n < 20, outputnya tulisan dengan format “... belas” (contoh: 15 → “lima belas”). Jika n < 100, dipanggil fungsi puluhan(n) untuk menghasilkan bentuk “... puluh ...”. Jika n == 100, hasilnya “seratus”. Jika input di luar 0–100, program memberi output pesan error.

Di fungsi main, program meminta input angka n, lalu memanggil fungsi convert(n) untuk menampilkan hasil konversi.

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
![Screenshot Output Unguided 3_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan1/output/Output_Soal3.png)

Program di atas adalah implementasi nested loop untuk menghasilkan pola simetris dengan angka dan simbol bintang. Pertama, program meminta inputan bilangan bulat n. Variabel i untuk mengatur baris, variabel j untuk mencetak angka atau spasi.

Loop pertama (for (i = 1; i <= n + 1; i++)) untuk mengatur jumlah baris yang akan ditampilkan, yaitu sebanyak n + 1.

Loop kedua (for (j = 1; j < i; j++)) mencetak spasi ganda "  ", sehingga baris-baris berikutnya akan bergeser ke kanan dan membentuk pola miring.

Loop ketiga (for (j = n - i + 1; j >= 1; j--)) mencetak angka menurun dari n - i + 1 hingga 1. Bagian ini menghasilkan deretan angka dari besar ke kecil di sebelah kiri bintang.

Setelah itu, program mencetak simbol * sebagai pemisah tengah.

Loop keempat (for (j = 1; j <= n - i + 1; j++)) mencetak angka menaik dari 1 sampai n - i + 1, sehingga membentuk cerminan dari angka sebelumnya di sebelah kanan bintang.

Program ini bisa menjadi contoh bagus untuk memahami logika nested loop dan pembentukan pola teks dalam C++.

## Kesimpulan
Bahasa pemrograman C++ memiliki struktur dasar yang terdiri dari header file, fungsi utama main(), serta mekanisme input dan output menggunakan cin dan cout. Konsep dasar yang dipelajari meliputi penggunaan variabel, operator aritmatika, percabangan untuk pengambilan keputusan, perulangan untuk proses berulang, serta struct untuk mengelompokkan data. Pemahaman materi ini menjadi landasan penting dalam membangun logika algoritma dan pemrograman yang lebih kompleks di tingkat selanjutnya, termasuk penerapan pemrograman berorientasi objek dan pengembangan aplikasi yang lebih luas.

## Referensi
[1] Styawati, & Rahmanto, Y. (2024). Dasar-Dasar Pemrograman dengan Bahasa C++. Teknokrat Media & Publishing. Tersedia di: https://publishing.teknokrat.ac.id/dasar-dasar-pemrograman-dengan-bahasa-c 
<br>[2] Tim UNP Press. (2021). Pengantar Coding Berbasis C/C++. UNP Press. Tersedia di: https://unppress.unp.ac.id/index.php/unp-press/catalog/download/83/139/280-1?inline=1
<br>[3] Indahyati, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: Umsida Press. https://doi.org/10.21070/2020/978-623-6833-67-4
