#include <iostream>
#include <vector>
using namespace std;

class T
{
public:
    T() : m_val(0)
    {
        cout << "constructor" << endl;
    }
    T(int val) : m_val(val)
    {
        cout << "param constructor" << endl;
    }
    T(T &other)
    {
        cout << "copy constructor" << endl;
    }
    T(T &&other)
    {
        cout << "move constructor" << endl;
    }

    T &operator=(T &othr)
    {
        cout << "copy asignment" << endl;
        return *this;
    }
    T &operator=(const T &&othr)
    {
        cout << "move asignment" << endl;
        return *this;
    }

private:
    int m_val;
};
T create()
{
    T tmp;
    return tmp;
}
int main(int argc, char const *argv[])
{
    // T a;
    // T tmp(a);
    // T* p = new T;
    T aa = std::move(create());
    return 0;
}
