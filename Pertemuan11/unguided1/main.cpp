#include "MultiLL.h"
#include <iostream>
using namespace std;

int main() {

    // 1. Inisialisasi List Parent (Golongan Hewan)
    listParent L;
    createListParent(L);

    // 2. Membuat Data Parent (Golongan Hewan)
    NodeParent G1 = allocNodeParent("G001", "Aves");
    insertFirstParent(L, G1);

    NodeParent G2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(L, G2);

    NodeParent G3 = allocNodeParent("G003", "Pisces");
    insertLastParent(L, G3);

    NodeParent G4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(L, G4);

    NodeParent G5 = allocNodeParent("G005", "Reptil");
    insertLastParent(L, G5);

    cout << endl;

    // 3. Memasukkan Child (Data Hewan) ke Parent tertentu

    // ---- Golongan Aves (G001)
    NodeChild H1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertFirstChild(G1->L_Child, H1);

    NodeChild H2 = allocNodeChild("AV002", "Bebek", "Air", true, 2);
    insertLastChild(G1->L_Child, H2);

    // ---- Golongan Mamalia (G002)
    NodeChild R1 = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
    insertFirstChild(G2->L_Child, R1);

    NodeChild R2 = allocNodeChild("M003", "Gorila", "Hutan", false, 160);
    insertLastChild(G2->L_Child, R2);
    
    NodeChild R3 = allocNodeChild("M002", "Kucing", "Darat", false, 4);
    insertLastChild(G2->L_Child, R3);

    // ---- Golongan Amfibi (G004)
    NodeChild B1 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertFirstChild(G4->L_Child, B1);

    printMLLStructure(L);
    cout << endl;
    
    return 0;
}
