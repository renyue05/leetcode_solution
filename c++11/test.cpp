#include <iostream>
#include <functional>
#include <stdio.h>
using namespace std;
void f()
{
    cout << "f()" << endl;
}
class A
{
public:
    int num = 10;
    void foo()
    {
        cout << "foo() \n";
    }
};
char *returnArr()
{
    static char arr[] = "hello world";
    return arr;
}
int main(int argc, char const *argv[])
{
    // void (*p)() = &f;
    // f();
    // p();
    // A a;
    // std::invoke(&A::foo, &a);
    // char *s1 = "abc";
    // char s2[] = "abc";
    // cout << s1 << endl;
    // cout << s2 << endl;
    // s1[0] = 'g';
    // s2[0] = 'g';
    // cout << s1 << endl;
    // cout << s2 << endl;
    // s1 = "def";
    // s2 = "def";
    // char *arr = returnArr();
    // cout << arr << endl;
    // arr[0] = 'l';
    // cout << returnArr() << endl;

    // char c = 128 + 13;
    char c = 140;
    // 1 0 0 0 0 0 0 0
    // 1 0 0 0 0 0 0 0
    // 1 1 1 1 0 1 1 0
    // 1 0 0 0 1 0 1 0
    // 140
    // 1 0 0 0 1 1 0 0 补码
    // 1 1 1 1 0 1 0 0 
    // 
    printf("%d\n", c);
    for (int i = 0; i < 8; ++i)
    {
        cout << !!(c & (1 << (7 - i))) << " ";
    }
    cout << endl;

    int i = 0x1234;
    // int i = 2147483647;
    cout << i << endl;
    cout << sizeof i << endl;
    printf("%d\n",*(char*)&i);

    return 0;
}
