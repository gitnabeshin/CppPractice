#include <iostream>
using namespace std;

int main() {
    int i, j;
    double d;

    i = 10;
    j = 20;
    d = 99.01;

    cout << "Here are some value: ";
    cout << i << ", " << j << ", " << d << "\n";

    cout << "Update some value: ";
    cin >> i >> j >> d;

    cout << "Here are new value: ";
    cout << i << ", " << j << ", " << d << "\n";

    return 0;
}