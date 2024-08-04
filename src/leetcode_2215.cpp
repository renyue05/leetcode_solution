#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<int>> result(2);
    cout << "func" << endl;
    cout << result.size() << endl;
    unordered_set<int> set1;
    unordered_set<int> set2;
    unordered_set<int> result1;
    unordered_set<int> result2;
    for (int i = 0; i < nums1.size(); ++i)
    {
        set1.insert(nums1[i]);
    }
    for (int i = 0; i < nums2.size(); ++i)
    {
        set2.insert(nums2[i]);
        if (set1.find(nums2[i]) == set1.end())
        {
            // result[1].push_back(nums2[i]);
            result2.insert(nums2[i]);
        }
    }
    for (int i = 0; i < nums1.size(); ++i)
    {
        if (set2.find(nums1[i]) == set2.end())
        {
            // result[0].push_back(nums1[i]);
            result1.insert(nums1[i]);
        }
    }
    result[0] = vector<int>(result1.begin(),result1.end());
    result[1] = vector<int>(result2.begin(),result2.end());
    return result;
}
int main(int argc, char const *argv[])
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {1, 2, 3};
    findDifference(nums1, nums2);
    cout << 1 << endl;
    return 0;
}
