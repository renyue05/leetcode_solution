#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int longestValidParentheses(string s)
{
    int ret = 0;
    stack<pair<char, int>> stk;
    vector<int> dp(s.size(), 0);
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(' || stk.empty() || stk.top().first != '(')
        {
            stk.push({s[i], i});
            dp[i] = 0;
        }
        else
        {
            int pre = stk.top().second;
            stk.pop();
            dp[i] = (i - pre + 1) + (pre ? dp[pre - 1] : 0);
        }
        ret = max(dp[i], ret); 
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    cout << longestValidParentheses("())(())()(())") << endl;
    return 0;
}
