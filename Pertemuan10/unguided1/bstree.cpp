#include "bstree.h"
#include <iostream>

using namespace std;

bool isEmpty(address root) {
    return root == Nil;
}

void createTree(address &root) {
    root = Nil;
}

address alokasi(infotype x) {
    address nodeBaru = new Node;
    if (nodeBaru != Nil) {
        nodeBaru->info = x;
        nodeBaru->left = Nil;
        nodeBaru->right = Nil;
    }
    return nodeBaru;
}

void dealokasi(address nodeHapus) {
    delete nodeHapus;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
        if (root != Nil) {
        }
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        }
        else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    } else {
        if (root->info == x) {
            return root;
        } else if (x < root->info) {
            return findNode(x, root->left);
        } else {
            return findNode(x, root->right);
        }
    }
}

void preOrder(address root) {
    if (root != Nil) {
        cout << root->info << " - ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) {
    if (root != Nil) {
        inOrder(root->left);
        cout << root->info << " - ";
        inOrder(root->right);
    }
}

void postOrder(address root) {
    if (root != Nil) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " - ";
    }
}

address mostRight(address root) {
    address temp = root;
    while (temp != Nil && temp->right != Nil) {
        temp = temp->right;
    }
    return temp;
}

address mostLeft(address root) {
    address temp = root;
    while (temp != Nil && temp->left != Nil) {
        temp = temp->left;
    }
    return temp;
}

bool deleteNode(address &root, infotype x) {
    if (root == Nil) {
        return false; 
    }

    if (x < root->info) {
        return deleteNode(root->left, x);
    } else if (x > root->info) {
        return deleteNode(root->right, x);
    } else {
        address temp;

        if (root->left == Nil) {
            temp = root;
            root = root->right;
            dealokasi(temp);
            return true;
        } else if (root->right == Nil) {
            temp = root;
            root = root->left;
            dealokasi(temp);
            return true;
        }

        temp = mostLeft(root->right);
        
        root->info = temp->info;

        return deleteNode(root->right, temp->info);
    }
}

int size(address root) {
    if (root == Nil) {
        return 0;
    } else {
        return 1 + size(root->left) + size(root->right);
    }
}

int height(address root) {
    if (root == Nil) {
        return -1;
    } else {
        int hl = height(root->left);
        int hr = height(root->right);
        
        if (hl > hr) return 1 + hl;
        else return 1 + hr;
    }
}