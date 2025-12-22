#include "bst.h"

int main() {
    BinTree tree;
    createTree(tree);

    insertNode(tree, alokasi(50,"Monitor LED",10));
    insertNode(tree, alokasi(30,"Keyboard RGB",20));
    insertNode(tree, alokasi(70,"Mouse Gaming",15));
    insertNode(tree, alokasi(20,"Kabel HDMI",50));
    insertNode(tree, alokasi(40,"Headset 7.1",12));
    insertNode(tree, alokasi(60,"Webcam HD",8));
    insertNode(tree, alokasi(80,"Speaker BT",5));

    cout << "=== INORDER ===" << endl;
    cout << "ID   NAMA         STOK" << endl;
    cout << "------------------------" << endl;
    inOrder(tree);

    cout << endl << "=== PREORDER ===" << endl;
    cout << "ID   NAMA         STOK" << endl;  
    cout << "------------------------" << endl;
    preOrder(tree);

    cout << endl << "=== POSTORDER ===" << endl;
    cout << "ID   NAMA         STOK" << endl;
    cout << "------------------------" << endl;  
    postOrder(tree);

    cout << endl << "=== SEARCH ID 40 ===" << endl;
    searchById(tree,40);
    cout << endl << "=== SEARCH ID 99 ===" << endl;
    searchById(tree,99);

    cout << endl << "=== SEARCH PRODUCT 'Webcam HD' ===" << endl;
    bool found = false;
    searchByProduct(tree,"Webcam HD",found);
    if (!found) {
        cout << "Data tidak ditemukan" << endl;
    }

    cout << endl << "=== SEARCH PRODUCT 'Printer' ===" << endl;
    found = false;
    searchByProduct(tree,"Printer",found);
    if (!found) {
        cout << "Data tidak ditemukan" << endl;
    }

    cout << endl << "=== DATA MINIMUM ===" << endl;
    node minNode = mostLeft(tree);
    if (minNode != Nil) {
            cout << minNode->id << " "
            << minNode->nama << " "
            << minNode->stok << endl;
    }

    cout << endl << "=== DATA MAKSIMUM ===" << endl;
    cout << "ID   NAMA         STOK" << endl;
    cout << "------------------------" << endl;
    node maxNode = mostRight(tree);
    if (maxNode != Nil) {
            cout << maxNode->id << " "
            << maxNode->nama << " "
            << maxNode->stok << endl;
    }

    deleteNode(tree,20);
    inOrder(tree);

    deleteNode(tree,30);
    inOrder(tree);

    deleteNode(tree,50);
    inOrder(tree);

    deleteTree(tree);
    inOrder(tree);
}
