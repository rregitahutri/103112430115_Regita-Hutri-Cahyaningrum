#include <iostream>
#include "DLLPlaylist.h" // Include header saja

using namespace std;

int main() {
    List playlist;
    Song s1, s2, s3, deletedS;
    
    createList(playlist);

    s1 = {"Senja di Kota", "Nona Band", 210, 150, 4.2};
    s2 = {"Langkahmu", "Delta", 185, 320, 4.8};
    s3 = {"Hujan Minggu", "Arka", 240, 90, 3.9};
    insertLast(playlist, s1);
    insertLast(playlist, s2);
    insertLast(playlist, s3);

    viewList(playlist);

    deleteLast(playlist, deletedS);
    cout << "\nLagu dihapus: " << deletedS.Title << endl;

    Song updateData = {"Pelita", "Luna", 200, 260, 4.5};
    updateAtPosition(playlist, 2, updateData);

    viewList(playlist);

    cout << "\n=== OPERASI BEFORE ===" << endl;
    
    cout << "a. insertBefore Node Posisi 2" << endl;
    address pPos2 = getAddressAt(playlist, 2);
    Song dataInsert = {"Senandung", "Mira", 175, 120, 4.0};
    insertBefore(playlist, pPos2, dataInsert);
    viewList(playlist);

    cout << "\nb. updateBefore Node Posisi 2" << endl;
    pPos2 = getAddressAt(playlist, 2);
    Song dataUpdateBefore = {"Fajar", "Budi", 190, 200, 4.1};
    updateBefore(playlist, pPos2, dataUpdateBefore);
    viewList(playlist);

    cout << "\nc. deleteBefore Node Posisi 3" << endl;
    address pPos3 = getAddressAt(playlist, 3);
    deleteBefore(playlist, pPos3, deletedS);
    cout << "Data yang dihapus: " << deletedS.Title << endl;
    viewList(playlist);

    searchByPopularityRange(playlist, 150.0, 300.0);

    return 0;
}