#include <iostream>
#include <vector>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
void threadproc()
{
    while (true)
    {
        std::cout << "I am thread\n";
    }
}
void fun()
{
    std::thread t(threadproc);
    t.detach();
}
int main(int argc, char const *argv[])
{
    fun();
    while (true)
    {
    }
    return 0;
}
