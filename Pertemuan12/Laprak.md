# <h1 align="center">Laporan Praktikum Modul 14 - Graph</h1>
<p align="center">Regita Hutri Cahyaningrum - 103112430115</p>

## Dasar Teori
Graf merupakan struktur data non-linear yang terdiri dari sekumpulan simpul (node) serta hubungan antar simpul yang direpresentasikan dengan sisi (edge). Dalam konteks pemodelan sistem, graf sering digunakan untuk merepresentasikan hubungan atau jalur antar objek, terutama pada kasus pencarian rute, pemetaan, dan struktur jaringan yang kompleks. Salah satu pendekatan umum dalam penelusuran graf adalah algoritma Breadth First Search (BFS) dan Depth First Search (DFS), yang masing-masing memiliki strategi traversal berbeda sesuai kebutuhan aplikasi. Algoritma BFS menelusuri graf berdasarkan urutan tingkat kedalaman atau level, dimulai dari satu node awal kemudian mengunjungi seluruh node tetangga sebelum bergerak ke level berikutnya, sehingga algoritma ini cocok digunakan untuk pencarian jalur terpendek pada graf tidak berbobot [1][2]. Sebaliknya, DFS bekerja dengan strategi menyusuri node sedalam mungkin sebelum melakukan backtracking, sehingga cocok untuk pencarian jalur tertentu, eksplorasi struktur graf, dan identifikasi keterhubungan komponen [1].

Dalam implementasi praktis, algoritma BFS dan DFS banyak diterapkan dalam konteks pencarian rute, pemetaan lokasi, serta optimasi jaringan. Beberapa penelitian menunjukkan bahwa kedua algoritma ini dapat digunakan untuk menentukan lintasan dalam aplikasi berbasis peta digital seperti Google Maps atau sistem penunjang keputusan terkait rute lokasi tertentu [2]. Selain itu, perbandingan performa BFS dan DFS juga dilakukan pada aplikasi pencarian rute wisata, yang menunjukkan bahwa BFS lebih unggul dalam menemukan jalur terpendek, sedangkan DFS lebih efisien untuk eksplorasi ruang solusi yang lebih dalam [3]. Secara keseluruhan, baik BFS maupun DFS memiliki peran penting dalam pengolahan graf dan menjadi dasar dalam implementasi berbagai algoritma canggih lainnya, seperti Dijkstra dan A*, yang memanfaatkan karakteristik traversal untuk mendapatkan hasil yang optimal.

## Guided 

### 1. ADT Graph Tidak Berarah dengan Operasi CRUD dan Traversal BFS DFS

##### Source Code graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge{
    adrNode Node;
    adrEdge Next;
};

struct Graph{
    adrNode First;
};

void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph data);
adrNode AlokasiEdge(adrEdge nodeTujuan);

void InsertNode(Graph &G, infoGraph data);
adrNode FindNode(Graph G, infoGraph data);
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2);
void DisconnectNode(adrNode node1, adrNode node2);
void DeleteNode(Graph &G, infoGraph X);

void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);
void PrintBFS(Graph G, infoGraph StartInfo);
void PrintDFS(Graph G, infoGraph StartInfo);

#endif
```
##### Source Code graph.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
```
##### Source Code main.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS
int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    PrintBFS(G, 'A');
    PrintDFS(G, 'A');
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL) {
        cout << "Node E berhasil dihapus." << endl;
    } else {
        cout << "Node E gagal dihapus." << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    PrintBFS(G, 'A');
    PrintDFS(G, 'A');

    return 0;
}
```
Program di atas merupakan implementasi lengkap dari ADT Graph tidak berarah menggunakan struktur multilist, yang terdiri dari node (ElmNode) dan edge (ElmEdge). Pada file graph.h didefinisikan tipe data graph beserta fungsi‐fungsi dasar seperti membuat graph, menambah node, menghapus node, menghubungkan dan memutuskan hubungan antar node, serta melakukan traversal. File graph.cpp berisi implementasi dari seluruh operasi tersebut, mulai dari alokasi node dan edge, penyisipan node baru, pencarian node berdasarkan karakter, hingga prosedur ConnectNode dan DisconnectNode yang membentuk edge dua arah sesuai karakteristik graph tak berarah. Selain itu, terdapat prosedur DeleteNode yang menghapus sebuah node beserta seluruh hubungan yang terkait dengannya. Program juga menyediakan dua metode penelusuran graph yaitu Breadth First Search (BFS) menggunakan queue dan Depth First Search (DFS) menggunakan stack, di mana keduanya mencetak urutan kunjungan node. Pada main.cpp, seluruh fungsi diuji dengan membuat graph berisi node A hingga F, menghubungkannya sesuai ilustrasi graph, menampilkan adjacency list, melakukan traversal, menghapus node E, lalu menampilkan hasil perubahan graph. Program ini memperlihatkan bagaimana struktur graph dapat dimanipulasi dan ditelusuri secara dinamis menggunakan pointer.

## Unguided 

### 1. Buatlah ADT Graph tidak berarah file “graph.h. Buatlah implementasi ADT Graph pada file “graph.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”.

##### Source Code graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode First;
};

void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph data);
adrEdge AlokasiEdge(adrNode nodeTujuan);

void InsertNode(Graph &G, infoGraph data);
adrNode FindNode(Graph G, infoGraph data);
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2);

void PrintInfoGraph(Graph G);

void PrintDFS(Graph G, infoGraph StartInfo);
void PrintBFS(Graph G, infoGraph StartInfo);

#endif
```
##### Source Code graph.cpp
```C++
#include "graph.h"
#include <queue>
#include <stack>
using namespace std;

void CreateGraph(Graph &G) {
    G.First = NULL;
}

adrNode AlokasiNode(infoGraph data) {
    adrNode P = new ElmNode;
    P->info = data;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;
    return P;
}

adrEdge AlokasiEdge(adrNode tujuan) {
    adrEdge E = new ElmEdge;
    E->Node = tujuan;
    E->Next = NULL;
    return E;
}

void InsertNode(Graph &G, infoGraph data) {
    adrNode P = AlokasiNode(data);

    if (G.First == NULL) {
        G.First = P;
    } else {
        adrNode Q = G.First;
        while (Q->Next != NULL) Q = Q->Next;
        Q->Next = P;
    }
}

adrNode FindNode(Graph G, infoGraph data) {
    adrNode P = G.First;
    while (P != NULL) {
        if (P->info == data) return P;
        P = P->Next;
    }
    return NULL;
}

void ConnectNode(Graph &G, infoGraph x, infoGraph y) {
    adrNode N1 = FindNode(G, x);
    adrNode N2 = FindNode(G, y);

    if (N1 != NULL && N2 != NULL) {
        adrEdge E1 = AlokasiEdge(N2);
        E1->Next = N1->firstEdge;
        N1->firstEdge = E1;

        adrEdge E2 = AlokasiEdge(N1);
        E2->Next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.First;
    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;

        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }

        cout << endl;
        P = P->Next;
    }
}
```
##### Source Code main.cpp
```C++
#include "graph.h"
#include <iostream>
using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== GRAPH ===" << endl;
    PrintInfoGraph(G);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan12/output/Soal1.png)

Program di atas mengimplementasikan ADT Graph tidak berarah menggunakan multilist yang terdiri dari node (ElmNode) dan edge (ElmEdge). File graph.h mendefinisikan struktur graph beserta fungsi dasar seperti membuat graph, menambah node, mencari node, menghubungkan dua node, dan menampilkan graph. Pada graph.cpp, fungsi-fungsi tersebut diimplementasikan, mulai dari alokasi node dan edge, penyisipan node ke dalam graph, pencarian node berdasarkan info, hingga pembuatan hubungan dua node dalam bentuk adjacency list untuk graph tidak berarah. Fungsi PrintInfoGraph menampilkan seluruh node beserta daftar tetangganya. Pada main.cpp, graph diuji dengan menambahkan enam node (A-F), kemudian setiap node dihubungkan sesuai ilustrasi graph menggunakan fungsi ConnectNode. Terakhir, program mencetak representasi adjacency list dari graph sehingga terlihat keterhubungan antar node secara lengkap.

### 2. Buatlah prosedur untuk menampilkanhasil penelusuran DFS.

##### Source Code graph.h
```C++
// Tambahan Soal Nomor 2
void PrintDFS(Graph G, infoGraph StartInfo);

#endif
```
##### Source Code graph.cpp
```C++
// Tambahan Soal Nomor 2
void PrintDFS(Graph G, infoGraph start) {
    adrNode P = G.First;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }

    adrNode S = FindNode(G, start);
    if (S == NULL) return;

    stack<adrNode> st;
    st.push(S);

    cout << "DFS: ";
    while (!st.empty()) {
        adrNode curr = st.top();
        st.pop();

        if (curr->visited == 0) {
            curr->visited = 1;
            cout << curr->info << " ";

            adrEdge e = curr->firstEdge;
            while (e != NULL) {
                if (e->Node->visited == 0)
                    st.push(e->Node);
                e = e->Next;
            }
        }
    }
    cout << endl;
}
```
##### Source Code main.cpp
```C++
    // Tambahan Soal Nomor 2
    cout << "DFS dari A: ";
    PrintDFS(G, 'A');

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan12/output/Soal2.png)

Sebelum proses penelusuran dimulai, seluruh node terlebih dahulu diset ulang nilai visited-nya menjadi 0 agar traversal berjalan dengan benar. Penelusuran dimulai dari node yang diberikan sebagai parameter (start), lalu node tersebut dimasukkan ke dalam stack. DFS bekerja dengan mengambil node teratas dari stack, menandainya sebagai visited, mencetak informasinya, kemudian mendorong seluruh tetangganya yang belum dikunjungi ke dalam stack. Proses ini berulang sampai stack kosong. Pada main.cpp, prosedur ini dipanggil untuk menampilkan urutan DFS yang dimulai dari node ‘A’.

### 3. Buatlah prosedur untuk menampilkanhasil penelusuran BFS.

##### Source Code graph.h
```C++
// Tambahan Soal Nomor 3
void PrintBFS(Graph G, infoGraph StartInfo);
```
##### Source Code graph.cpp
```C++
// Tambahan Soal Nomor 3
void PrintBFS(Graph G, infoGraph start) {
    adrNode P = G.First;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }

    adrNode S = FindNode(G, start);
    if (S == NULL) return;

    queue<adrNode> q;
    q.push(S);
    S->visited = 1;

    cout << "BFS: ";
    while (!q.empty()) {
        adrNode curr = q.front();
        q.pop();

        cout << curr->info << " ";

        adrEdge e = curr->firstEdge;
        while (e != NULL) {
            if (e->Node->visited == 0) {
                e->Node->visited = 1;
                q.push(e->Node);
            }
            e = e->Next;
        }
    }
    cout << endl;
}
```
##### Source Code main.cpp
```C++
        // Tambahan Soal Nomor 3
        cout << "BFS dari A: ";
        PrintBFS(G, 'A');
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/rregitahutri/103112430115_Regita-Hutri-Cahyaningrum/blob/main/Pertemuan12/output/Soal3.png)

Pada proses ini, sebelum traversal dimulai, seluruh node di-reset nilai visited-nya agar penelusuran berjalan dengan benar. BFS dimulai dari node awal yang diberikan sebagai parameter, kemudian node tersebut dimasukkan ke dalam queue. Selama queue tidak kosong, node terdepan diambil, dicetak, lalu seluruh tetangga yang belum dikunjungi ditandai sebagai visited dan dimasukkan ke dalam queue. Dengan cara ini, BFS menelusuri graph secara bertingkat (level by level). Pada main.cpp, prosedur ini dipanggil untuk menampilkan urutan BFS yang dimulai dari node 'A'.

## Kesimpulan
Penerapan ADT Graph tidak berarah dengan menggunakan struktur multilist dapat mempermudah representasi hubungan antar node secara dinamis, termasuk penambahan, penghapusan, dan penghubungan node. Implementasi algoritma traversal BFS dan DFS menunjukkan perbedaan cara kerja dalam menelusuri graf, di mana BFS menelusuri node berdasarkan tingkat (level) dan cocok untuk mencari jalur terpendek, sedangkan DFS menelusuri graf secara mendalam dan efektif untuk eksplorasi struktur graf. Melalui pengujian pada main.cpp, seluruh operasi seperti insert node, connect node, delete node, serta penelusuran BFS dan DFS dapat berjalan dengan baik, sehingga membuktikan bahwa ADT Graph yang dibuat sudah berfungsi dengan benar dan mampu merepresentasikan hubungan antar node serta proses traversal sesuai teori yang telah dipelajari.

## Referensi
[1] Nicolas, F., & Suryantara, I. G. N. (2022). Implementasi Algoritma Breadth First Search dan Depth First Search pada Aplikasi Kimia Hidrokarbon Berbasis Augmented Reality. CogITo Smart Journal, Vol. 8 No. 1. Diakses melalui https://cogito.unklab.ac.id/index.php/cogito/article/view/354/231
<br>[2] Andriati, D. A., Dariato, E., & Hafizh, R. (2025). Implementasi Teori Graf dan Optimisasi Algoritma Dijkstra, BFS dan DFS dalam Menentukan Rute Terpendek Jaringan Bengkel di Jakarta Berbasis Google Maps. Jatilima: Jurnal Multimedia dan Teknologi Informasi, Vol. 07 No. 03. Diakses melalui https://journal.cattleyadf.org/index.php/jatilima/article/view/1654/894
<br>[3] (2025). Comparison of BFS and DFS Algorithm for Routes to Historical-Cultural Tourism Locations in Banten Province. Journal of Advances in Information and Industrial Technology (JAIIT). Diakses melalui https://journal.ittelkom-sby.ac.id/jaiit/article/view/560/249