#include <iostream>
using namespace std;

void tukar(int *x, int *y){ 
    int temp;
    temp = *x; 
    *x = *y;   
    *y = temp; 
}

int main(){
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Nilai a: " << a << endl;
    cout << "Alamat a: " << &a << endl;
    cout << "Nilai ptr (alamat a): " << ptr << endl;
    cout << "Nilai yang ditunjuk ptr: " << *ptr << endl;

    tukar(&a, &b);
    cout << "Nilai a setelah ditukar: " << a << " dan b = " << b << endl;

    return 0;
}