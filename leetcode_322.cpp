#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, -1);
    for (int i = 0; i < coins.size(); ++i)
    {
        dp[coins[i]] = 1;
        for (int j = coins[i] + 1; j < dp.size(); ++j)
        {
            if (dp[coins[i]] != -1 && dp[j - coins[i]] != -1)
            {
                dp[j] = dp[j] == -1 ? dp[coins[i]] + dp[j - coins[i]] : min(dp[j], dp[coins[i]] + dp[j - coins[i]]);
            }
        }
    }
    return dp[amount];
}
int main(int argc, char const *argv[])
{
    vector<int> coins{1, 2, 5};
    cout << coinChange(coins, 11);
    return 0;
}
