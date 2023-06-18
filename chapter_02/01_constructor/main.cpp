#include<iostream>
using namespace std;

class myclass {
    int a;
public:
    myclass(){
        cout << "Called constructor!!\n";
        a = 10;
    }

    myclass(int i){
        cout << "Called constructor!! with " << i << "\n";
        a = i;
    }

    ~myclass(){
        cout << "Called destructor!! of " << a << "\n";
    }

    void show() {
        cout << "a = " << a << "\n";
    }
};


int main(void) {

    myclass obj1;
    obj1.show();

    myclass *obj2 = new myclass(100);
    obj2->show();
    delete obj2;

    myclass obj3(25);
    obj3.show();

    cout << "end.\n";

    return 0;
}