#ifndef BST_H
#define BST_H
#define Nil NULL
#include <iostream>
#include <string>
using namespace std;

typedef struct BST *node;

struct BST {
    int id;
    string nama;
    int stok;
    node left;
    node right;
};

typedef node BinTree;

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int id, string nama, int stok);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchById(BinTree tree, int id);
void searchByProduct(BinTree tree, string nama, bool &found);

void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

node mostLeft(BinTree tree);
node mostRight(BinTree tree);

bool deleteNode(BinTree &tree, int id);
void deleteTree(BinTree &tree);

#endif
