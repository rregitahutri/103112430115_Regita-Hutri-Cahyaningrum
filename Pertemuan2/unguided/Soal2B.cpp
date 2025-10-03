#include <iostream>
using namespace std;

void tukar(int &x, int &y, int z){ 
    int temp;
    temp = x; 
    x = y;   
    y = z; 
    z = temp;
}

int main(){
    int a = 20, b = 30, c = 40;
    int& ref = a; 

    cout << "Nilai a: " << a << endl;
    cout << "Alamat a (&a): " << &a << endl;
    cout << "Nilai ref (alias a): " << ref << endl;
    cout << "Alamat ref (&ref)" << &ref << endl << endl;

    //mengubah nilai a melalui reference
    
    cout << "Before swaping, value of a = " << a << ", b = " << b << ", dan c = " << c << endl; 
    ref = 50;
    cout << "\nSetelah ref = 50;" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai ref: " << ref << endl << endl;
    tukar(a, b, c);
    cout << "After swaping, value of a = " << a << ", b = " << b << ", dan c = " << c << endl; 

    return 0;
}