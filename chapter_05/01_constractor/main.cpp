#include <iostream>
using namespace std;

class MyClass
{
    int x;

public:
    MyClass()
    {
        x = 0;
    }
    MyClass(int i)
    {
        x = i;
    }
    int get_x()
    {
        return x;
    }
};

class MyDate
{
    int day, month, year;

public:
    MyDate(const char *date_str);
    MyDate(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    void show()
    {
        cout << year << "/" << month << "/" << day << endl;
    }
};

MyDate::MyDate(const char *date_str)
{
    sscanf(date_str, "%d/%d/%d", &year, &month, &day);
}

int main()
{
    MyClass obj1;
    MyClass obj2(10);

    cout << "1: " << obj1.get_x() << endl;
    cout << "2: " << obj2.get_x() << endl;

    // set all 0
    MyClass obj3[10];
    // set each number
    MyClass obj4[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int i = 0;
    cout << "3: ";
    for (i = 0; i < 10; i++)
    {
        cout << obj3[i].get_x() << ", ";
    }
    cout << endl;

    cout << "4: ";
    for (i = 0; i < 10; i++)
    {
        cout << obj4[i].get_x() << ", ";
    }
    cout << endl;

    MyDate obj_d1("2023/12/1");
    MyDate obj_d2(2024, 12, 24);
    obj_d1.show();
    obj_d2.show();

    MyClass *obj5 = new MyClass();
    cout << "5: " << obj5->get_x() << endl;

    MyClass *obj6 = new MyClass(100);
    cout << "6: " << obj6->get_x() << endl;

    return 0;
}
