#ifndef MLL_H
#define MLL_H
#include <iostream>
#include <string>
using namespace std;

struct Child;
struct Parent;

typedef Parent* adrParent;
typedef Child* adrChild;

struct Child {
    string idFilm;
    string judul;
    int durasi;
    int tahun;
    float rating;
    adrChild next;
    adrChild prev;
};

struct Parent {
    string idGenre;
    string namaGenre;
    adrParent next;
    adrParent prev;
    adrChild firstChild;
    adrChild lastChild;
};

struct MLL {
    adrParent first;
    adrParent last;
};

void createListParent(MLL &L);
adrParent alokasiParent(string, string);
adrChild alokasiChild(string, string, int, int, float);

void insertFirstParent(MLL &L, adrParent P);
void insertLastChild(adrParent P, adrChild C);

void hapusListChild(adrParent P);
void deleteAfterParent(MLL &L, adrParent prev);

void searchFilmByRatingRange(MLL L, float min, float max);
void printStrukturMLL(MLL L);

#endif
