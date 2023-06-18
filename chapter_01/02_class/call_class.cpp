#include<iostream>
using namespace std;

class myclass {
    int a;
public:
    int b;
    void set_a(int num);
    int get_a();
};

void myclass::set_a(int num) {
    a = num;
}

int myclass::get_a(){
    return a;
}

int main(void) {
    myclass obj1, obj2;

    obj1.set_a(100);
    obj2.set_a(30);

    cout << "obj1.get_a() = " << obj1.get_a() << "\n";
    cout << "obj2.get_a() = " << obj2.get_a() << "\n";

    obj1.b = 200;
    obj2.b = 20;

    cout << "obj1.b = " << obj1.b << "\n";
    cout << "obj2.b = " << obj2.b << "\n";

    return 0;
}