#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

struct ElmEdge;
struct ElmKota;

typedef ElmKota* adrKota;
typedef ElmEdge* adrEdge;

struct ElmEdge {
    adrKota tujuan;
    int jarak;
    adrEdge next;
};

struct ElmKota {
    string nama;
    int visited;
    adrEdge firstEdge;
    adrKota next;
};

struct GraphKota {
    adrKota first;
};

void createGraph(GraphKota &G);
adrKota alokasiNode(string);
adrEdge alokasiEdge(adrKota, int);

void insertNode(GraphKota &G, adrKota P);
adrKota findNode(GraphKota G, string nama);
void connectNode(GraphKota &G, string a, string b, int jarak);
void disconnectNode(adrKota A, adrKota B);
void deleteNode(GraphKota &G, string nama);

void printGraph(GraphKota G);
void resetVisited(GraphKota &G);
void printBFS(GraphKota &G, string start);
void printDFS(GraphKota &G, string start);

#endif
