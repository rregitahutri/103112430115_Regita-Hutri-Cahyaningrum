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

        // Tambahan Soal Nomor 2
        cout << "DFS dari A: ";
        PrintDFS(G, 'A');

        // Tambahan Soal Nomor 3
        cout << "BFS dari A: ";
        PrintBFS(G, 'A');

        return 0;
    }
