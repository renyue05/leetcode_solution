#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    queue<int> q;
    vector<int> v(nums.size(), 0);
    int max = 0;
    if (k != 0)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == 0)
            {
                if (nums[i] == 0)
                {
                    if (k > 0)
                    {
                        k--;
                        q.push(i);
                        v[i] = 0;
                    }
                }
                else
                {
                    v[i] = 0;
                }
            }
            else
            {
                if (nums[i] == 0)
                {
                    if (k > 0)
                    {
                        k--;
                        q.push(i);
                        v[i] = v[i - 1];
                    }
                    else
                    {

                        int tmp = q.front();
                        q.pop();
                        v[i] = tmp + 1;
                        q.push(i);
                    }
                }
                else
                {
                    v[i] = v[i - 1];
                }
            }
            max = max > (i - v[i] + 1) ? max : (i - v[i] + 1);
        }
    }
    else
    {
        int pre = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 1)
            {
                max = max > i - pre + 1 ? max : i - pre + 1;
            }
            else
            {
                pre = i + 1;
            }
        }
    }
    return max;
}
int main(int argc, char const *argv[])
{
    // vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int result = longestOnes(nums, 0);
    cout << result << endl;

    return 0;
}
// [ 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1 ] 3
//   1  2  3  4  5  5  6  7  8
