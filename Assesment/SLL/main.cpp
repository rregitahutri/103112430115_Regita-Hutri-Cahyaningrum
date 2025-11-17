#include <iostream>
#include "SLLInventory.h" 

using namespace std;

int main() {
    List L;
    Product tempProd, deletedProd;
    createList(L);

    tempProd = {"Pulpen", "A001", 20, 2500, 0};
    insertLast(L, tempProd);

    tempProd = {"Buku Tulis", "A002", 15, 5000, 10};
    insertLast(L, tempProd);

    tempProd = {"Penghapus", "A003", 30, 1500, 0};
    insertLast(L, tempProd);

    viewList(L);

    deleteFirst(L, deletedProd);
    cout << endl << "Data dihapus: " << deletedProd.Nama;

    cout << endl << "Data Setelah deleteFirst:" << endl;
    viewList(L);
    
    Product updateData = {"Stabilo", "A010", 40, 9000, 5};
    updateAtPosition(L, 2, updateData);
    
    cout << endl << "Data Setelah update:" << endl;
    viewList(L);

    searchByFinalPriceRange(L, 2000, 7000);

    MaxHargaAkhir(L);

    return 0;
}