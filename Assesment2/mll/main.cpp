#include "mll.h"

int main() {
    MLL L;
    createListParent(L);

    adrParent G1 = alokasiParent("G001","Action");
    adrParent G2 = alokasiParent("G002","Comedy");
    adrParent G3 = alokasiParent("G003","Horror");
    adrParent G4 = alokasiParent("G004","Romance");

    insertFirstParent(L,G4);
    insertFirstParent(L,G3);
    insertFirstParent(L,G2);
    insertFirstParent(L,G1);

    insertLastChild(G1, alokasiChild("FA001","The Raid",101,2011,7.6));

    insertLastChild(G2, alokasiChild("FC001","Agak Laen",119,2024,8.0));
    insertLastChild(G2, alokasiChild("FC002","My Stupid Boss",108,2016,6.8));

    insertLastChild(G3, alokasiChild("FH001","Pengabdi Setan",107,2017,8.4));

    insertLastChild(G4, alokasiChild("FR001","Habibie & Ainun",118,2012,7.6));
    insertLastChild(G4, alokasiChild("FR002","Dilan 1990",110,2018,6.6));

    printStrukturMLL(L);
    cout << endl;
    
    searchFilmByRatingRange(L,8.0,8.5);

    deleteAfterParent(L,G1);
    printStrukturMLL(L);
}
