#include "Singlelist.h"
#include <iostream>
using namespace std;

int main() {
    linkedList L;
    address P1, P2, P3, P4, P5;
    createList(L);

    P1 = alokasi(0);
    insertFirst(L, P1);

    P2 = alokasi(12);
    insertFirst(L, P2);

    P4 = alokasi(9);
    insertFirst(L, P4);

    P5 = alokasi(2);
    insertLast(L, P5);

    P3 = alokasi(8);
    insertAfter(L, P2, P3);

    cout << "--- ISI LIST AWAL ---" << endl;
    printInfo(L);
    cout << endl;
    
    deleteFirst(L);
    deleteLast(L);
    deleteAfter(L, P2, P3);
    cout << "--- ISI LIST SETELAH DELETE FIRST, DELETE LAST, DAN DELETE AFTER ---" << endl;
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);
    cout << endl << "- List Berhasil Terhapus -";
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
