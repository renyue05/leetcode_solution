#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long totalCost(vector<int> &costs, int k, int candidates)
{
    long long ret = 0;
    priority_queue<int, vector<int>, greater<>> lpq;
    priority_queue<int, vector<int>, greater<>> rpq;
    int l = 0, r = 0;
    for (int i = 0; i < candidates; ++i)
    {
        lpq.push(costs[i]);
        ++l;
    }
    cout << "l:" << l << endl;
    for (int i = 0; i < candidates && (l + r) < costs.size(); ++i)
    {
        rpq.push(costs[costs.size() - 1 - r]);
        ++r;
    }
    r = costs.size() - r - 1;
    cout << "r:" << r << endl;

    // while (!lpq.empty())
    // {
    //     cout << lpq.top() << endl;
    //     lpq.pop();
    // }
    // cout << "=============" << endl;
    // while (!rpq.empty())
    // {
    //     cout << rpq.top() << endl;
    //     rpq.pop();
    // }

    for (int i = 0; i < k; ++i)
    {
        if (lpq.empty())
        {
            ret += rpq.top();
            rpq.pop();
        }
        else if (rpq.empty())
        {
            ret += lpq.top();
            lpq.pop();
        }
        else
        {
            if (lpq.top() <= rpq.top())
            {
                ret += lpq.top();
                lpq.pop();
                if (l < r + 1)
                {
                    lpq.push(costs[l++]);
                }
            }
            else
            {
                ret += rpq.top();
                rpq.pop();
                if (r > l - 1)
                {
                    rpq.push(costs[r--]);
                }
            }
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    vector<int> costs{1,2,4,1};
    int k = 3;
    int candidates = 3;
    int ret = totalCost(costs, k, candidates);
    cout << ret << endl;
    return 0;
}
