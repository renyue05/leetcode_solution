#include <iostream>
#include <vector>
using namespace std;
vector<bool> used(9, false);
void func(int start, int target, int num, vector<vector<int>> &ret, vector<int> &tmp)
{
    if (num == 0)
    {
        if (target == 0)
        {
            ret.push_back(tmp);
        }
        return;
    }
    for (int i = start; i <= 9 && i <= target; ++i)
    {
        tmp.push_back(i);
        func(i + 1, target - i, num - 1, ret, tmp);
        tmp.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> ret;
    vector<int> tmp;
    func(1, n, k, ret, tmp);
    return ret;
}
int main(int argc, char const *argv[])
{
    int k = 3, n = 9;
    combinationSum3(k, n);
    return 0;
}
