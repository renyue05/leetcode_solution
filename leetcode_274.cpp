#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int hIndex(vector<int> &citations)
{
    sort(citations.begin(), citations.end());
    for_each(citations.begin(), citations.end(), [](int val)
             { cout << val << " "; });

    return 0;
}
int main(int argc, char const *argv[])
{
    /* code */
    vector<int> c{1, 6, 2, 8, 3};
    hIndex(c);
    return 0;
}
class RandomizedSet
{
public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (idx.count(val))
        {
            return false;
        }
        nums.push_back(val);
        idx.insert({val, nums.size() - 1});
        return true;
    }

    bool remove(int val)
    {
        if (!idx.count(val))
        {
            return false;
        }
        int index = idx[val];
        int back = nums.back();
        nums[index] = back;
        nums.pop_back();
        idx.erase(val);
        idx[back] = index;
    }

    int getRandom()
    {
        return nums[0];
    }

private:
    vector<int> nums;
    unordered_map<int, int> idx;
};