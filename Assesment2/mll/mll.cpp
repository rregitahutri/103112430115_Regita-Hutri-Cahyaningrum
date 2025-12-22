#include "mll.h"

void createListParent(MLL &L) {
    L.first = NULL;
    L.last = NULL;
}

adrParent alokasiParent(string id, string nama) {
    adrParent P = new Parent;
    P->idGenre = id;
    P->namaGenre = nama;
    P->next = NULL;
    P->prev = NULL;
    P->firstChild = NULL;
    P->lastChild = NULL;
    return P;
}

adrChild alokasiChild(string id, string judul, int durasi, int tahun, float rating) {
    adrChild C = new Child;
    C->idFilm = id;
    C->judul = judul;
    C->durasi = durasi;
    C->tahun = tahun;
    C->rating = rating;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void insertFirstParent(MLL &L, adrParent P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastChild(adrParent P, adrChild C) {
    if (P->firstChild == NULL) {
        P->firstChild = C;
        P->lastChild = C;
    } else {
        P->lastChild->next = C;
        C->prev = P->lastChild;
        P->lastChild = C;
    }
}

void hapusListChild(adrParent P) {
    adrChild C = P->firstChild;
    while (C != NULL) {
        adrChild temp = C;
        C = C->next;
        delete temp;
    }
    P->firstChild = NULL;
    P->lastChild = NULL;
}

void deleteAfterParent(MLL &L, adrParent prev) {
    adrParent del = prev->next;
    prev->next = del->next;
    if (del->next != NULL)
        del->next->prev = prev;
    else
        L.last = prev;
    hapusListChild(del);
    delete del;
}

void printStrukturMLL(MLL L) {
    adrParent P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << "=== Parent " << i << " ===" << endl;
        cout << "ID Genre: " << P->idGenre << endl;
        cout << "Nama Genre: " << P->namaGenre << endl;
        adrChild C = P->firstChild;
        int j = 1;
        while (C != NULL) {
            cout << "   - Child " << j << ":" << endl;
            cout << "     ID Film: " << C->idFilm << endl;
            cout << "     Judul Film: " << C->judul << endl;
            cout << "     Durasi Film: " << C->durasi << " menit" << endl;
            cout << "     Tahun Tayang : " << C->tahun << endl;
            cout << "     Rating Film : " << C->rating << endl;
            C = C->next;
            j++;
        }
        cout << "-------------------------------------" << endl;
        P = P->next;
        i++;
    }
}

void searchFilmByRatingRange(MLL L, float min, float max) {
    adrParent P = L.first;
    int posParent = 1;
    while (P != NULL) {
        adrChild C = P->firstChild;
        int posChild = 1;
        while (C != NULL) {
            if (C->rating >= min && C->rating <= max) {
                cout << "Data Film ditemukan pada list child dari node parent " << P->namaGenre << " pada posisi ke-" << posChild << "!" << endl;
                cout << "--- Data Film (Child) ---" << endl;
                cout << "Judul Film " << C->judul << endl;
                cout << "Posisi dalam list child posisi ke-" << posChild << endl;
                cout << "ID Film: " << C->idFilm << endl;
                cout << "Durasi Film: " << C->durasi << " menit." << endl;
                cout << "Tahun Tayang : " << C->tahun << endl;
                cout << "Rating Film : " << C->rating << endl;
                cout << "-------------------------------------" << endl;
                cout << "--- Data Genre (Parent) ---" << endl;
                cout << "ID Genre : " << P->idGenre << endl;
                cout << "Posisi dalam list parent posisi ke-" << posParent << endl;
                cout << "Nama Genre: " << P->namaGenre << endl;
                cout << "====================" << endl;
            }
            C = C->next;
            posChild++;
        }
        P = P->next;
        posParent++;
    }
}
