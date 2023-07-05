#include <iostream>
using namespace std;

class MyClass
{
    int n, d;

public:
    MyClass(int i, int j)
    {
        n = i;
        d = j;
    }
    // friend function.
    friend bool isEqual(MyClass obj);
};

bool isEqual(MyClass obj)
{
    // In friend function private variables can be accessed through its instance.
    if (obj.n == obj.d)
    {
        return true;
    }
    return false;
}

int main()
{
    MyClass obj1(10, 10), obj2(1, 2);

    cout << "obj1 isEqual: " << isEqual(obj1) << "\n";
    cout << "obj2 isEqual: " << isEqual(obj2) << "\n";

    return 0;
}