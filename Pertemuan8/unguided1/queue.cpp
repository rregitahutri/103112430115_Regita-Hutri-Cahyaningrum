#include "queue.h"
#include <iostream>
using namespace std;

bool isEmptyQueue(queue Q){
    return (Q.head == -1 && Q.tail == -1);
}

// bool isFullQueue(queue Q){
//     return (Q.tail == MAKSIMAL - 1);
// }

// //isFull implementasi 3
bool isFullQueue(queue Q){
    return (Q.tail + 1) % MAKSIMAL == Q.head;
}

void CreateQueue(queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

// void enqueue(queue &Q, int x){
//     if(isFullQueue(Q)){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmptyQueue(Q)){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail++;
//         }
//         Q.info[Q.tail] = x;
//     }
// }

// //enQueue implementasi 3
void enqueue(queue &Q, int x){
    if(isFullQueue(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmptyQueue(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
        }
        Q.info[Q.tail] = x;
        // cout << "nama " << x << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// void dequeue(queue &Q){
//     if(isEmptyQueue(Q)){
//         cout << "Queue kosong!" << endl;
//     } else {
//         for(int i = 0; i < Q.tail; i++){
//             Q.info[i] = Q.info[i+1];
//         }
//         Q.tail--;
//         if(Q.tail < 0){
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// void dequeue(queue &Q){
//     if(isEmptyQueue(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         // cout << "Mengahapus data " << Q.info[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

//deQueue implementasi 3
void dequeue(queue &Q){
    if(isEmptyQueue(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        // cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
        }
    }
}

// void printInfo(queue Q){
//     cout << Q.head << " - " << Q.tail << " | ";

//     if(isEmptyQueue(Q)){
    //         cout << "empty queue" << endl;
    //     } else {
        //         for(int i = Q.head; i <= Q.tail; i++){
            //             cout << Q.info[i];
            //             if(i < Q.tail) cout << " ";
            //         }
            //         cout << endl;
            //     }
            // }
            
    // //viewQueue implementasi 3
void printInfo(queue Q){
    cout << Q.head << " - " << Q.tail << " | ";

    if(isEmptyQueue(Q)){
        cout << "empty queue" << endl;
        return;
    }

    int i = Q.head;
    while (true) {
        cout << Q.info[i];

        if (i == Q.tail) break;

        cout << " ";
        i = (i + 1) % MAKSIMAL;
    }

    cout << endl;
}
