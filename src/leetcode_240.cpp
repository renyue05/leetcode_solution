#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int binSearch(const vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (nums[m] == target)
        {
            return m;
        }
        else if (nums[m] < target)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    bool ret = false;
    for (int i = 0; i < matrix.size(); ++i)
    {
        if (matrix[i][0] <= target && matrix[i][matrix[0].size() - 1] >= target)
        {
            if (binSearch(matrix[i], target) != -1)
            {
                return true;
            }
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{
    vector<int> nums{1, 2, 5, 6, 9};
    cout << binSearch(nums, 5) << endl;
    return 0;
}
