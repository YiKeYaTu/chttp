//
// Created by lc on 2021/12/12.
//
#include <thread>
#include <mutex>

class A {
    std::mutex m;
};

int main()
{
    A *p = new A;

    return 0;
}