#include <iostream>
#include <cstring>
#include <wchar.h>
#include <string>
#include <cstddef>

int main()
{
    std::string s = "hello";
    std::cout << s << std::endl;
    std::cout << s.length() << ", " << s.size() << ", " << sizeof(s) << std::endl;
    std::printf("[%s], [%lu]\n", s.c_str(), sizeof(s));

    s += " world";
    std::cout << s << std::endl;
    std::cout << s.length() << std::endl;
    std::printf("[%s]\n", s.c_str());

    std::string hello = s.substr(0, 5);
    std::cout << hello << std::endl;

    std::cout << "--------------------" << std::endl;
    std::wstring ws = L"HELLO";
    std::wcout << ws << std::endl;
    std::wcout << ws.length() << ", " << ws.size() << ", " << sizeof(ws) << std::endl;
    std::printf("[%ls], [%lu]\n", ws.c_str(), sizeof(ws));
    // size of wchar_t depends on compiler. On gcc, it's 4byte.

    std::cout << "--------------------" << std::endl;
    s = "hello";
    std::byte bytes[s.length()];
    std::memcpy(bytes, s.data(), s.length());
    for (auto &b : bytes)
    {
        std::cout << std::to_integer<int>(b) << ' ';
    }
    std::cout << std::endl;

    std::byte bytes2[ws.length()];
    std::memcpy(bytes2, ws.data(), ws.length());
    for (auto &b : bytes2)
    {
        std::cout << std::to_integer<int>(b) << ' ';
    }
    std::cout << std::endl;
}