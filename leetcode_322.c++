#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int coinChange(vector<int> &coins, int amount)
{
    int ret = 0;
    // multiset<int,std::greater<int>> m_set;
    multiset<int> m_set;
    
    for (auto val : coins)
    {
        m_set.insert(val);
    }
    auto it = m_set.begin();
    // for (int i = 0; i < amount - 1; ++i)
    // {
    //     ++it;
    // }
    // cout << *it << endl;
    for (auto it = m_set.begin(); it != m_set.end(); ++it)
    {
        cout << *it << endl;
    }
    return *it;
}
int main(int argc, char const *argv[])
{
    vector<int> coins{3,2,3,1,2,4,5,5,6};
    int amount = 4;
    int ret = coinChange(coins, amount);
    return 0;
}
