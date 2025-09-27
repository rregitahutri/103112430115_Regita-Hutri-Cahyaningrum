#include <iostream>
using namespace std;

int main() {
    int n, i, j;
    cout << "input: ";
    cin >> n;
    cout << "output: " << endl;

    for (i = 1; i <= n + 1; i++) {
        for (j = 1; j < i; j++) {
            cout << "  ";
        }

        for (j = n - i + 1; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (j = 1; j <= n - i + 1; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}
