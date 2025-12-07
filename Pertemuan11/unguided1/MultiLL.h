#ifndef MultiLL_H
#define MultiLL_H

#include <iostream>
#include <string>

using namespace std;

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

//isEmpty & create list
bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

//alokasi & dealokasi
NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeChild(NodeChild &NChild);
void deallocNodeParent(NodeParent &NParent);

//operasi pada parent
void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

//operasi pada child
void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

//operasi print
void printMLLStructure(listParent &LParent);

//operasi hapus list
void deleteListChild(listChild &LChild);

#endif