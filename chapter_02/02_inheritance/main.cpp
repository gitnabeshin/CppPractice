#include <iostream>
using namespace std;

class B {
    int i;
public:
    void set_i(int n) {
        i = n;
    }
    int get_i() {
        return i;
    }
};

class D : public B {
    int j;
public:
    void set_j(int n) {
        j = n;
    }
    int get_j() {
        return j;
    }
    int get_all() {
        return j + get_i();
    }
};

int main() {
    D obj_d;

    obj_d.set_i(10);
    obj_d.set_j(100);

    cout << obj_d.get_all() << "\n";

    return 0;
}
