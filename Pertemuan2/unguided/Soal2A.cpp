#include <iostream>
using namespace std;

void tukar(int *x, int *y, int *z){ 
    int temp;
    temp = *x; 
    *x = *y;   
    *y = *z; 
    *z = temp;
}

int main(){
    int a = 20, b = 30, c = 40;
    int *ptr;

    ptr = &a;

    cout << "======= Pointer A =======" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Alamat a: " << &a << endl;
    cout << "Nilai ptr (alamat a): " << ptr << endl;
    cout << "Nilai yang ditunjuk ptr: " << *ptr << endl << endl;

    cout << "Sebelum ditukar: a = " << a << ", b = " << b << ", dan c = " << c << endl;
    tukar(&a, &b, &c);
    cout << "Setelah ditukar: a = " << a << ", b = " << b << ", dan c = " << c << endl;

    return 0;
}