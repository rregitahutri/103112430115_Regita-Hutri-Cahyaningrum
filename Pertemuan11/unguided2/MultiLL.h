#ifndef MultiLL_H
#define MultiLL_H

// Copy isi struct dari mll_soal1.h di sini
// ... (Bagian struct sama persis dengan soal 1) ...
#include <iostream>
#include <string>
using namespace std;

struct golonganHewan { string idGolongan; string namaGolongan; };
struct dataHewan { string idHewan; string namaHewan; string habitat; bool ekor; float bobot; };
typedef struct nodeParent *adrParent;
typedef struct nodeChild *adrChild;
struct nodeChild { dataHewan info; adrChild next; adrChild prev; };
struct listChild { adrChild first; adrChild last; };
struct nodeParent { golonganHewan info; adrParent next; adrParent prev; listChild L_Child; };
struct listParent { adrParent first; adrParent last; };

void createListParent(listParent &L);
void createListChild(listChild &L);
adrParent allocNodeParent(string idGol, string namaGol);
adrChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void insertLastParent(listParent &L, adrParent P);
void insertLastChild(listChild &L, adrChild P);
void printMLLStructure(listParent L);

// --- TAMBAHAN UNTUK SOAL 2 ---
void searchHewanByEkor(listParent L, bool tail);

#endif