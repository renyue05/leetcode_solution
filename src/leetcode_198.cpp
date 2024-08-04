#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int max(int a, int b)
{
    return a > b ? a : b;
}
int rob(vector<int> &nums)
{
    vector<int> dp(nums.size() + 1, 0);
    int ret = nums[0];
    dp[1] = nums[0];
    for (int i = 2; i < dp.size(); ++i)
    {
        // nums i;
        dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
        ret = max(ret, dp[i]);
    }
    return ret;
}
int main(int argc, char const *argv[])
{

    return 0;
}
