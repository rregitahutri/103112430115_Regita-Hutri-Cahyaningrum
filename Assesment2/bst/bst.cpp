#include "bst.h"

bool isEmpty(BinTree tree) {
    return tree == Nil;
}

void createTree(BinTree &tree) {
    tree = Nil;
}

node alokasi(int id, string nama, int stok) {
    node P = new BST;
    P->id = id;
    P->nama = nama;
    P->stok = stok;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void dealokasi(node nodeHapus) {
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru) {
    if (isEmpty(tree)) {
        tree = nodeBaru;
    } else if (nodeBaru->id < tree->id) {
        insertNode(tree->left, nodeBaru);
    } else {
        insertNode(tree->right, nodeBaru);
    }
}

void searchById(BinTree tree, int id) {
    if (tree == Nil) {
        cout << "Data tidak ditemukan" << endl;
    } else if (tree->id == id) {
        cout << tree->id << " " << tree->nama << " " << tree->stok << endl;
    } else if (id < tree->id) {
        searchById(tree->left, id);
    } else {
        searchById(tree->right, id);
    }
}

void searchByProduct(BinTree tree, string nama, bool &found) {
    if (tree != Nil) {
        searchByProduct(tree->left, nama, found);
        if (tree->nama == nama) {
            cout << tree->id << " " << tree->nama << " " << tree->stok << endl;
            found = true;
        }
        searchByProduct(tree->right, nama, found);
    }
}

void preOrder(BinTree tree) {
    if (tree != Nil) {
        cout << tree->id << "   " << tree->nama << "    " << tree->stok << endl;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void inOrder(BinTree tree) {
    if (tree != Nil) {
        inOrder(tree->left);
        cout << tree->id << "   " << tree->nama << "    " << tree->stok << endl;
        inOrder(tree->right);
    }
}

void postOrder(BinTree tree) {
    if (tree != Nil) {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->id << "   " << tree->nama << "    " << tree->stok << endl;
    }
}

node mostLeft(BinTree tree) {
    if (tree->left == Nil)
        return tree;
    return mostLeft(tree->left);
}

node mostRight(BinTree tree) {
    if (tree->right == Nil)
        return tree;
    return mostRight(tree->right);
}

bool deleteNode(BinTree &tree, int id) {
    if (tree == Nil) return false;

    if (id < tree->id) {
        return deleteNode(tree->left, id);
    } else if (id > tree->id) {
        return deleteNode(tree->right, id);
    } else {
        node temp = tree;
        if (tree->left == Nil) {
            tree = tree->right;
        } else if (tree->right == Nil) {
            tree = tree->left;
        } else {
            node pengganti = mostLeft(tree->right);
            tree->id = pengganti->id;
            tree->nama = pengganti->nama;
            tree->stok = pengganti->stok;
            deleteNode(tree->right, pengganti->id);
            return true;
        }
        dealokasi(temp);
        return true;
    }
}

void deleteTree(BinTree &tree) {
    if (tree != Nil) {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}