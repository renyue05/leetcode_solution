#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<char, vector<string>> mmap{{'2', {"a", "b", "c"}}, {'3', {"d", "e", "f"}}, {'4', {"g", "h", "i"}}, {'5', {"j", "k", "l"}}, {'6', {"m", "n", "o"}}, {'7', {"p", "q", "r", "s"}}, {'8', {"t", "u", "v"}}, {'9', {"w", "x", "y", "z"}}};
void func(const string &digits, int n, vector<string> &ret, string &tmp)
{
    if (n == digits.size())
    {
        ret.push_back(tmp);
        return;
    }
    vector<string> strings = mmap[digits[n]];
    for (string s : strings)
    {
        tmp += s;
        func(digits, n + 1, ret, tmp);
        tmp.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    vector<string> ret;
    string tmp("");
    func(digits, 0, ret, tmp);
    return ret;
}

int main(int argc, char const *argv[])
{
    string dig = "23";
    auto ret = letterCombinations(dig);
    return 0;
}
