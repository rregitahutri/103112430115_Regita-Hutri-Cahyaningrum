#include "Singlylist.h"
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

    cout << "--- ISI LIST AWAL ---" << endl;
    printInfo(L);

    P3 = alokasi(8);
    insertAfter(L, P2, P3);

    cout << "--- ISI LIST SETELAH INSERT AFTER ---" << endl;
    printInfo(L);

    return 0;
}
