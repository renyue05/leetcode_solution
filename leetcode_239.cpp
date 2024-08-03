#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    multiset<int, std::greater<int>> set_;
    vector<int> ret;

    for (int i = 0; i < k; ++i)
    {
        set_.insert(nums[i]);
    }
    ret.push_back(*set_.begin());
    for (int i = k; i < nums.size(); ++i)
    {
        set_.insert(nums[i]);
        set_.erase(set_.find(nums[i - k]));
        
        ret.push_back(*set_.begin());
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    auto ret = maxSlidingWindow(nums, 3);
    for (auto n : ret)
    {
        cout << n << " ";
    }
    cout << endl;
    // multiset<int, std::greater<int>> set_;
    // set_.insert(10);
    // set_.insert(14430);
    // set_.insert(-10);
    // cout << *set_.begin();
    // cout << endl;
    return 0;
}
