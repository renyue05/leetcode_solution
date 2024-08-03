#include <iostream>
#include <vector>
using namespace std;
int tribonacci(int n)
{
    // 0 1 1 2 3 5
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    if(n == 2)
    {
        return 2;
    }
    vector<int> ret(n + 1, 0);
    ret[0] = 0;
    ret[1] = 1;
    ret[2] = 1;
    for (int i = 3; i < n + 1; ++i)
    {
        ret[i] = ret[i - 1] + ret[i - 2] + ret[i - 3];
    }
    return ret.back();
}
int main(int argc, char const *argv[])
{

    return 0;
}
