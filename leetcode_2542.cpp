#include <iostream>
#include <queue>
#include <vector>

using namespace std;
long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
{
    // // 会了
    // priority_queue<int> pq;
    // vector<pair<int, int>> nums;
    // for (int i = 0; i < nums1.size(); ++i)
    // {
    //     nums.push_back({nums2[i], nums1[i]});
    // }
    // sort(nums.begin(), nums.end(), [](auto u1, auto u2)
    //      { return u1.first > u2.first; });
    // for (auto p : nums)
    // {
    //     cout << p.first << " " << p.second << endl;
    // }
    // for (int i = 0; i < k; ++i)
    // {
    // }
    return 0;
}
int main(int argc, char const *argv[])
{
    vector<int> nums1{1, 3, 3, 2};
    vector<int> nums2{2, 1, 3, 4};
    priority_queue<int, vector<int>, greater<> > pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);

    cout << pq.top() << endl;

    return 0;
}
