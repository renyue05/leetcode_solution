#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long getTime(int speed, vector<int> &piles)
{
    long long ret = 0;
    for (auto pile : piles)
    {
        ret += ((pile + speed - 1) / speed);
    }
    return ret;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int ret = 0;
    int max = 0;
    for (int pile : piles)
    {
        max = pile > max ? pile : max;
    }
    int min = 1;
    int m;
    while (min <= max)
    {
        m = (min + max) / 2;
        long long t = getTime(m, piles);
        if (t > h)
        {
            min = m + 1;
        }
        else
        {
            ret = m;
            max = m - 1;
        }
    }

    return ret;
}
int main(int argc, char const *argv[])
{
    vector<int> piles{805306368,805306368,805306368};
    int h = 1000000000;
    int ret = minEatingSpeed(piles, h);
    cout << ret << endl;
    return 0;
}
