#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <string>
using namespace std;

const int MAX = 6;

struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
};

float hitungNilaiAkhir(Mahasiswa M);

bool isEmpty(StackMahasiswa S);
bool isFull(StackMahasiswa S);
void createStack(StackMahasiswa &S);
void Push(StackMahasiswa &S, Mahasiswa M);
void Pop(StackMahasiswa &S);
void Update(StackMahasiswa &S, int posisi, Mahasiswa dataBaru);
void View(StackMahasiswa S);
void SearchNilaiAkhir(StackMahasiswa S, float min, float max);
void MaxNilaiAkhir(StackMahasiswa S);

#endif