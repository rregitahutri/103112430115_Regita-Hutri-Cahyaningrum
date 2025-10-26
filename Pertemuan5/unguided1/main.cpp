#include "listAngka.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF, nodeAb = Nil;
    createList(List);

    dataAngka dtAngka;

    nodeA = alokasi(29);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(45);
    nodeF = alokasi(50);

    insertFirst(List, nodeB);
    insertLast(List, nodeA);
    insertAfter(List, nodeD, nodeB);
    insertFirst(List, nodeC);
    insertLast(List, nodeE);
    insertFirst(List, nodeF);

    printList(List);
    cout << endl;

    updateFirst(List);
    updateAfter(List, nodeD);
    updateLast(List);
    updateAfter(List, nodeF);

    delAfter(List, nodeB, nodeC);

    cout << endl;
    printList(List);
    cout << endl;

    FindNodeByData(List, 20);
    FindNodeByData(List, 55);
    FindNodeByAddress(List, nodeB);
    FindNodeByAddress(List, nodeA);
    FindNodeByRange(List, 40);

    cout << "Total penjumlahan : " << sumList(List) << endl;
    cout << "Total pengurangan : " << subList(List) << endl;
    cout << "Total perkalian   : " << multipleList(List) << endl;

    return 0;
}