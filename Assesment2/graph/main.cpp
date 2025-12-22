#include "graph.h"

int main() {
    GraphKota G;
    createGraph(G);

    insertNode(G, alokasiNode("Bekasi"));
    insertNode(G, alokasiNode("Tangerang"));
    insertNode(G, alokasiNode("Depok"));
    insertNode(G, alokasiNode("Bogor"));
    insertNode(G, alokasiNode("Jakarta"));

    connectNode(G,"Jakarta","Bogor",42);
    connectNode(G,"Jakarta","Bekasi",16);
    connectNode(G,"Jakarta","Depok",21);
    connectNode(G,"Jakarta","Tangerang",24);

    connectNode(G,"Bogor","Depok",22);
    connectNode(G,"Bogor","Bekasi",60);

    connectNode(G,"Depok","Tangerang",30);
    connectNode(G,"Depok","Bekasi",25);

    connectNode(G,"Tangerang","Bekasi",45);

    printGraph(G);

    deleteNode(G,"Depok");
    printGraph(G);

    cout << "=== HASIL TRAVERSAL BFS & DFS DARI KOTA TANGERANG ===" << endl;
    printBFS(G,"Tangerang");
    printDFS(G,"Tangerang");
}
