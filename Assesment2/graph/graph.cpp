#include "graph.h"

void createGraph(GraphKota &G) {
    G.first = NULL;
}

adrKota alokasiNode(string nama) {
    adrKota P = new ElmKota;
    P->nama = nama;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

adrEdge alokasiEdge(adrKota tujuan, int jarak) {
    adrEdge E = new ElmEdge;
    E->tujuan = tujuan;
    E->jarak = jarak;
    E->next = NULL;
    return E;
}

void insertNode(GraphKota &G, adrKota P) {
    P->next = G.first;
    G.first = P;
}

adrKota findNode(GraphKota G, string nama) {
    adrKota P = G.first;
    while (P != NULL) {
        if (P->nama == nama) return P;
        P = P->next;
    }
    return NULL;
}

void connectNode(GraphKota &G, string a, string b, int jarak) {
    adrKota A = findNode(G,a);
    adrKota B = findNode(G,b);
    adrEdge EA = alokasiEdge(B,jarak);
    adrEdge EB = alokasiEdge(A,jarak);
    EA->next = A->firstEdge;
    A->firstEdge = EA;
    EB->next = B->firstEdge;
    B->firstEdge = EB;
}

void disconnectNode(adrKota A, adrKota B) {
    adrEdge E = A->firstEdge, prev = NULL;
    while (E != NULL) {
        if (E->tujuan == B) {
            if (prev == NULL) A->firstEdge = E->next;
            else prev->next = E->next;
            delete E;
            break;
        }
        prev = E;
        E = E->next;
    }
}

void deleteNode(GraphKota &G, string nama) {
    adrKota P = G.first, prev = NULL;
    while (P != NULL && P->nama != nama) {
        prev = P;
        P = P->next;
    }
    adrKota Q = G.first;
    while (Q != NULL) {
        disconnectNode(Q,P);
        Q = Q->next;
    }
    if (prev == NULL) G.first = P->next;
    else prev->next = P->next;
    delete P;
}

void printGraph(GraphKota G) {
    adrKota P = G.first;
    cout << "=== REPRESENTASI ADJACENCY LIST GRAPH ===" << endl;
    while (P != NULL) {
        cout << "Node " << P->nama << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->tujuan->nama << " (" << E->jarak << " KM), ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
    cout << endl;
}

void resetVisited(GraphKota &G) {
    adrKota P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }
}

void printBFS(GraphKota &G, string start) {
    resetVisited(G);
    queue<adrKota> Q;
    adrKota S = findNode(G,start);
    Q.push(S);
    S->visited = 1;
    cout << "BFS Traversal: ";
    while (!Q.empty()) {
        adrKota P = Q.front();
        Q.pop();
        cout << P->nama << " - ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->tujuan->visited == 0) {
                E->tujuan->visited = 1;
                Q.push(E->tujuan);
            }
            E = E->next;
        }
    }
    cout << endl;
}

void printDFS(GraphKota &G, string start) {
    resetVisited(G);
    stack<adrKota> S;
    S.push(findNode(G,start));
    cout << "DFS Traversal: ";
    while (!S.empty()) {
        adrKota P = S.top();
        S.pop();
        if (P->visited == 0) {
            P->visited = 1;
            cout << P->nama << " - ";
            adrEdge E = P->firstEdge;
            while (E != NULL) {
                if (E->tujuan->visited == 0)
                    S.push(E->tujuan);
                E = E->next;
            }
        }
    }
    cout << endl;
}
