#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return 0;
    }
    else if (nums.size() == 2)
    {
        return nums[0] > nums[1] ? 0 : 1;
    }
    int ret = -1;
    int l = 0;
    int r = nums.size() - 1;
    int m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (m == 0 && nums[0] > nums[1])
        {
            return 0;
        }
        else if (m == nums.size() - 1 && nums[nums.size() - 1] > nums[nums.size() - 2])
        {
            return nums.size() - 1;
        }
        else if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1])
        {
            return m;
        }
        if (nums[m] < nums[r])
        {
            l = m + 1;
        }
        else if (nums[m] < nums[l])
        {
            r = m - 1;
        }
        else if (nums[m] > nums[l] && nums[m] > nums[r])
        {
            if (nums[m] < nums[m + 1])
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        else if (nums[m] > nums[r])
        {
            r = m - 1;
        }
        else if (nums[m] > nums[l])
        {
            l = m + 1;
        }
        else
        {
            l = m + 1;
        }
    }

    return ret;
}
int main(int argc, char const *argv[])
{
    vector<int> nums{3, 4, 3, 2, 1};
    int ret = findPeakElement(nums);
    cout << ret << endl;
    return 0;
}
