#include <iostream>
#include <vector>
using namespace std;

int longestSubarray(vector<int> &nums)
{
    int result = 0;
    int sum = 0;
    int len = 0;
    int flag = -1;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == 1)
        {
            sum += 1;
        }
        else
        {
            sum = (i - flag - 1);
            flag = i;
        }
        result = result > sum ? result : sum;
    }
    result = (flag == -1) ? result - 1 : result;
    return result;
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> nums = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    // vector<int> nums = {1, 1, 1};
    cout << longestSubarray(nums) << endl;
    return 0;
}
