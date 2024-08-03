#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    vector<int> idx(spells.size());
    vector<int> ret(spells.size(), 0);
    iota(idx.begin(), idx.end(), 0);
    auto cmp = [&spells](const int &a, const int &b)
    { return (spells[a] > spells[b]); };
    sort(potions.begin(), potions.end());
    sort(idx.begin(), idx.end(), cmp);
    int l, r, m;
    int cache_l = 0;
    for (auto i : idx)
    {
        // spells[i]从小到大
        l = cache_l;
        r = potions.size() - 1;

        while (l <= r)
        {
            m = (l + r) / 2;
            int tmp = spells[i] * potions[m];
            if (tmp >= success && ((m - 1) >= 0 && spells[i] * potions[m - 1] < success || m == 0))
            {
                ret[i] = potions.size() - m;
                cache_l = m;
                break;
            }
            else if (tmp >= success)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    vector<int> spells{5, 1, 3};
    vector<int> potions{1, 2, 3, 4, 5};
    int success = 7;
    auto ret = successfulPairs(spells, potions, success);
    for (auto i : ret)
    {
        cout << i << endl;
    }
    /* vector<int> nums{3, 2, 5, 1};
    vector<int> idx(nums.size());
    iota(idx.begin(), idx.end(), 0);

    auto comp = [&nums](const int &a, const int &b)
    {
        return (nums[a] < nums[b]);
    };
    sort(idx.begin(), idx.end(), comp);
    for (auto v : idx)
    {
        cout << v << " ";
    }
    cout << endl;
    sort(idx.begin(), idx.end());
    cout << idx[0] << endl; */

    return 0;
}
