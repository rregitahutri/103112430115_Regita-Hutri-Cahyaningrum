#include "MultiLL.h"

void createListParent(listParent &L) { L.first = NULL; L.last = NULL; }
void createListChild(listChild &L) { L.first = NULL; L.last = NULL; }
adrParent allocNodeParent(string idGol, string namaGol) {
    adrParent P = new nodeParent; P->info.idGolongan = idGol; P->info.namaGolongan = namaGol;
    P->next = NULL; P->prev = NULL; createListChild(P->L_Child); return P;
}
adrChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    adrChild P = new nodeChild; P->info.idHewan = idHwn; P->info.namaHewan = namaHwn;
    P->info.habitat = habitat; P->info.ekor = tail; P->info.bobot = weight;
    P->next = NULL; P->prev = NULL; return P;
}
void insertLastParent(listParent &L, adrParent P) {
    if (L.first == NULL) { L.first = P; L.last = P; } else { P->prev = L.last; L.last->next = P; L.last = P; }
}
void insertLastChild(listChild &L, adrChild P) {
    if (L.first == NULL) { L.first = P; L.last = P; } else { P->prev = L.last; L.last->next = P; L.last = P; }
}
void printMLLStructure(listParent L) {
    adrParent P = L.first; int i = 1;
    while (P != NULL) {
        cout << "Parent " << i << " (" << P->info.namaGolongan << ")" << endl;
        adrChild C = P->L_Child.first;
        if(C==NULL) cout << "(kosong)" << endl;
        while (C != NULL) { cout << " - " << C->info.namaHewan << endl; C = C->next; }
        P = P->next; i++; cout << endl;
    }
}

// --- Implementasi Soal 2 ---
void searchHewanByEkor(listParent L, bool tail) {
    adrParent P = L.first;
    int idxParent = 1;
    while (P != NULL) {
        adrChild C = P->L_Child.first;
        int idxChild = 1;
        while (C != NULL) {
            if (C->info.ekor == tail) {
                cout << "Data ditemukan pada list anak dari node parent " 
                     << P->info.namaGolongan << " pada posisi ke-" << idxParent << "!" << endl;
                cout << "--- Data Child ---" << endl;
                cout << "ID Child      : " << C->info.idHewan << endl;
                cout << "Posisi        : posisi ke-" << idxChild << endl;
                cout << "Nama Hewan    : " << C->info.namaHewan << endl;
                cout << "Habitat       : " << C->info.habitat << endl;
                cout << "Ekor          : " << C->info.ekor << endl;
                cout << "Bobot         : " << C->info.bobot << endl;
                cout << "--------------------------" << endl;
                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent     : " << P->info.idGolongan << endl;
                cout << "Posisi        : posisi ke-" << idxParent << endl;
                cout << "Nama Golongan : " << P->info.namaGolongan << endl;
                cout << "--------------------------" << endl << endl;
            }
            C = C->next;
            idxChild++;
        }
        P = P->next;
        idxParent++;
    }
}