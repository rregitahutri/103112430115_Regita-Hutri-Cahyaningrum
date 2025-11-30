#include <iostream>
#include "bstree.h"
using namespace std;
int main() {
    // cout << "Hello World" << endl;
    address root = Nil;
    // insertNode(root,1);
    // insertNode(root,2);
    // insertNode(root,6);
    // insertNode(root,4);
    // insertNode(root,5);
    // insertNode(root,3);
    // insertNode(root,6);
    // insertNode(root,7);
    // inOrder(root);
    
    // cout<<"\nkedalaman : "<<hitungKedalaman(root,1)<<endl;
    // cout<<"jumlah Node : "<<hitungJumlahNode(root)<<endl;
    // cout<<"total : "<<hitungTotalInfo(root, 0)<<endl;

    // Nomor 3
    insertNode(root, 6); // Root utama
    insertNode(root, 4); // Root subtree kiri
    insertNode(root, 7); // Root subtree kanan
    insertNode(root, 2); 
    insertNode(root, 5); 
    insertNode(root, 1); 
    insertNode(root, 3);
    cout << "\n=== HASIL ===" << endl;

    cout << "Pre-Order  : ";
    preOrder(root);
    cout << endl;

    cout << "In-Order   : ";
    inOrder(root);
    cout << endl;

    cout << "Post-Order : ";
    postOrder(root);
    cout << endl;
    return 0;
}