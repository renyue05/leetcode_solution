#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    int ret = -1;
    vector<int> dp(nums.size(), 1);
    vector<int> nextGreat(nums.size(), -1);
    unordered_map<int, int> mp;
    stack<pair<int, int>> stk;
    stk.push({nums[0], 0});
    for (int i = 1; i < nums.size(); ++i)
    {
        while (!stk.empty() && nums[i] > stk.top().first)
        {
            nextGreat[stk.top().second] = i;
            stk.pop();
        }
        stk.push({nums[i], i});
    }
    for_each(nextGreat.begin(), nextGreat.end(), [](int a)
             { cout << a << " "; });
    cout << endl;
    for (int i = nums.size() - 1; i >= 0; --i)
    {
        dp[i] = nextGreat[i] != -1 ? dp[i] = 1 + dp[nextGreat[i]] : dp[i];
        ret = max(dp[i], ret);
    }
    for_each(dp.begin(), dp.end(), [](int a)
             { cout << a << " "; });
    cout << endl;
    return ret;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{0, 1, 0, 3, 2, 3};
    lengthOfLIS(nums);
    return 0;
}
