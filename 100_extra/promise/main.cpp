#include <iostream>
#include <future>
#include <thread>
#include <chrono>

void func(std::promise<int> p)
{
    std::cout << "    thread func start." << std::endl;

    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum = sum + i;
        std::cout << "    func:[" << i << "], " << sum << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    // promise:スレッドの処理結果を書き込む
    p.set_value(sum);

    // スレッドの処理途中で結果を呼び出し元に通知することが出来る
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "    func: finished. sum = " << sum << std::endl;
}

int main()
{
    std::cout << "start." << std::endl;

    std::promise<int> p;
    std::future<int> f = p.get_future();

    std::thread th(func, std::move(p));

    for (int i = 0; i < 10; i++)
    {
        std::cout << "main:[" << i << "]" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }

    // future: join()とは別タイミングで、別スレッドの結果を読み取る
    std::cout << "main func get value before join." << std::endl;
    std::cout << f.get() << std::endl;

    std::cout << "main func join..." << std::endl;
    th.join();

    std::cout << "main func finished." << std::endl;
    return 0;
}