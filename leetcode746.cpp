#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    vector<int> dp(cost.size() + 1, 0);
    for (int i = 2; i < dp.size(); ++i)
    {
        dp[i] = (dp[i - 1] + cost[i - 1]) < (dp[i - 2] + cost[i - 2]) ? (dp[i - 1] + cost[i - 1]) : (dp[i - 2] + cost[i - 2]);
    }
    return dp.back();
}

int main(int argc, char const *argv[])
{

    return 0;
}
