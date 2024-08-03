#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int pre = 0;
    int ret = 1000000;
    int l = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        pre = (pre + nums[i]) > 0 ? pre + nums[i] : 0;
        if (pre == 0)
        {
            l = i;
        }
        while (pre - nums[l] >= target)
        {
            pre -= nums[l];
            l++;
            ret = i - l + 1 < ret ? i - l + 1 : ret;
        }
        ret = pre > target ? (i - l + 1 < ret ? i - l + 1 : ret) : ret;
    }
    return (ret == 1000000) ? 0 : ret;
}
int main(int argc, char const *argv[])
{
    int target = 15;
    vector<int> nums{1,2,3,4,5};
    int ret = minSubArrayLen(target, nums);
    cout << ret << endl;
    cout << (-1 % 5) << endl;
    cout << (1 == 1.1) << endl;
    return 0;
}
