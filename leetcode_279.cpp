#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
using namespace std;
int func(int n, vector<int> vec)
{
    int l = 0, r = vec.size() - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (vec[m] == n || (vec[m] < n && vec[m + 1] > n))
        {
            return vec[m];
        }
        else if (vec[m] > n)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return 1;
}
int numSquares(int n)
{
    vector<int> vec_{1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289, 324, 361, 400, 441, 484, 529, 576, 625, 676, 729, 784, 841, 900, 961, 1024, 1089, 1156, 1225, 1296, 1369, 1444, 1521, 1600, 1681, 1764, 1849, 1936, 2025, 2116, 2209, 2304, 2401, 2500, 2601, 2704, 2809, 2916, 3025, 3136, 3249, 3364, 3481, 3600, 3721, 3844, 3969, 4096, 4225, 4356, 4489, 4624, 4761, 4900, 5041, 5184, 5329, 5476, 5625, 5776, 5929, 6084, 6241, 6400, 6561, 6724, 6889, 7056, 7225, 7396, 7569, 7744, 7921, 8100, 8281, 8464, 8649, 8836, 9025, 9216, 9409, 9604, 9801, 10000};
    int ret = 0;
    vector<int> dp(10001, 1000000);
    for (int i = 0; vec_[i] <= dp.size(); ++i)
    {
        int sn = vec_[i];
        for (int j = sn; j <= dp.size(); ++j)
        {
            if (j == sn)
            {
                dp[j] = 1;
            }
            else
            {
                dp[j] = min(dp[sn] + dp[j - sn], dp[j]);
            }
        }
    }
    ofstream ofs("aaa.txt");
    ofs << 0 << ',';
    int num = 0;
    for (int i = 1; i < dp.size(); ++i)
    {
        // cout << i << " " << dp[i] << endl;
        if (num == 400)
        {
            ofs << endl;
            num = 0;
        }
        ofs << dp[i] << ',';
        ++num;
    }
    ofs.close();
    return ret;
}
int main(int argc, char const *argv[])
{
    cout << numSquares(12) << endl;
    // cout <<
    return 0;
}
