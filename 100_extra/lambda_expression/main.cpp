#include <iostream>

// function object
class SumFunc
{
private:
    int m_i;

public:
    SumFunc(int i)
    {
        m_i = i;
    }
    int operator()(int j)
    {
        return m_i + j;
    }
};

void func_obj()
{
    std::cout << "===== Just a function object. ======" << std::endl;

    auto sum_calc = SumFunc(10);

    std::cout << "Func called = " << sum_calc(20) << std::endl;
    std::cout << "Func called = " << sum_calc(10) << std::endl;
}

void func_lambda1()
{
    std::cout << "===== lambda func. =====" << std::endl;

    [](int n)
    {
        std::cout << "lambda called = " << n << std::endl;
    }(100);

    auto f_lambda = [](int x)
    {
        std::cout << "lambda called = " << x << std::endl;
    };
    f_lambda(100);
    f_lambda(200);
}

void func_lambda2()
{
    std::cout << "===== lambda func. capture list. =====" << std::endl;

    int x = 0;
    int y = 30;
    std::cout << "x=" << x << ", y=" << y << std::endl;

    // x,y as copy
    auto cc1 = [=]()
    { std::cout << "cc[=]: x=" << x << ", y=" << y << std::endl; };

    auto cc2 = [x, y]()
    { std::cout << "cc[=]: x=" << x << ", y=" << y << std::endl; };

    // x as copy, y as ref
    auto cr = [=, &y]()
    { std::cout << "cr[=, &y]: x=" << x << ", y=" << y << std::endl; };
    // x,y as ref
    auto rr = [&x, &y]()
    { std::cout << "rr[&x, &y]: x=" << x << ", y=" << y << std::endl; };

    x = 1;
    y = 3;
    std::cout << "x=" << x << ", y=" << y << std::endl;

    cc2();
    cr();
    rr();

    [&x]()
    { x += 1; }(); // ref x can be changed.
    std::cout << "[&x]: x=" << x << ", y=" << y << std::endl;

    [y]() mutable
    { y += 1; }(); // mutable copy y can be changed.
    std::cout << "[y]() mutable : x=" << x << ", y=" << y << std::endl;

    // [y]()
    // { y += 1; }(); // copy y can not be changed.
    // std::cout << "[y](): " << x << ", " << y << std::endl;
    // main.cpp:68:9: error: cannot assign to a variable captured by copy in a non-mutable lambda
    //    { y += 1; }(); // copy y can not be changed.

    rr();
}

int main()
{
    func_obj();
    func_lambda1();
    func_lambda2();

    int x = 1;
    // x as capture.
    auto sequence = [x]()
    {
        return x + 100;
    };
    std::cout << "x=" << sequence() << std::endl;

    // x as capture, y as param.
    auto sequence2 = [x](int y)
    {
        return x * y;
    };
    std::cout << "x*y=" << sequence2(200) << std::endl;

    return 0;
}