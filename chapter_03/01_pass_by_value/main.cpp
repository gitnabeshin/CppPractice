#include <iostream>
using namespace std;

class sample
{
    int i;

public:
    sample(int n)
    {
        i = n;
    }
    void set_i(int n)
    {
        i = n;
    }
    int get_i()
    {
        return i;
    }
};

int sqr_it(sample o)
{
    return o.get_i() * o.get_i();
}

int sqr_it_overwrite(sample o)
{
    // o is copy. separated from orginal object.
    o.set_i(o.get_i() * o.get_i() + 100);
    return o.get_i();
}

int sqr_it_overwrite2(sample *pObj)
{
    pObj->set_i(pObj->get_i() * pObj->get_i() + 1000);
    return pObj->get_i();
}

int main()
{
    sample o1(10), o2(2), o3(0);
    cout << sqr_it(o1) << "\n";

    cout << "Copied Object value: " << sqr_it_overwrite(o2) << "\n";
    cout << "Original Object value: " << sqr_it(o2) << "\n";

    cout << "Copied Object pointer: " << sqr_it_overwrite2(&o2) << "\n";
    cout << "Original Object value: " << sqr_it(o2) << "\n";

    cout << sqr_it(o3) << "\n";
    // Object copy type is Deep Copy.
    o3 = o1;
    cout << sqr_it(o3) << "\n";

    return 0;
}
