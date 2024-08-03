#include <iostream>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> ret;
    int p1 = 0, p2 = numbers.size() - 1;
    for (int p1 = 0; p1 < numbers.size() - 1; ++p1)
    {
        int val = target - numbers[p1];
        // 在p1 + 1 ~  numbers.szie() - 1区间找val
        int l = p1 + 1;
        int r = numbers.size() - 1;
        int m = (l + r) / 2;
        while (l <= r)
        {
            if (numbers[m] == val)
            {
                return vector<int>{p1, m};
            }
            else if (numbers[m] < val)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
    }
    return ret;
}
int main(int argc, char const *argv[])
{
    vector<int> numbers{2, 7, 11, 15};
    int target = 9;
    twoSum(numbers, target);
    return 0;
}
