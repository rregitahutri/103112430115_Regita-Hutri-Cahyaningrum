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