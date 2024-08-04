#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
bool func(unordered_map<char, int> tmap)
{
    int sum = 0;
    for (auto p : tmap)
    {
        if (p.second < 0)
        {
            return false;
        }
    }
    return true;
}
string minWindow(string s, string t)
{
    if (s == t)
    {
        return s;
    }
    typedef unordered_map<char, int> cmap;
    cmap tmap;
    bool iscover = false;
    for (auto c : t)
    {
        tmap[c]--;
    }
    string ret("");
    int l = -1;
    for (int i = 0; i < s.size(); ++i)
    {
        if (tmap.count(s[i]))
        {
            l = (l == -1) ? i : l;
            tmap[s[i]]++;
            if (!iscover)
            {
                iscover = func(tmap);
            }
            if (iscover)
            {
                while (tmap.count(s[l]) == 0 || (tmap[s[l]] > 0))
                {
                    if (tmap.count(s[l]) && tmap[s[l]] > 0)
                    {
                        --tmap[s[l]];
                    }
                    ++l;
                }
                ret = (ret.size() == 0 || i - l + 1 < ret.size()) ? s.substr(l, i - l + 1) : ret;
            }
        }
    }
    return ret;
}
int main(int argc, char const *argv[])
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    unordered_map<int, int> m;
    unordered_map<string, int> mm;

    string ret = minWindow(s, t);
    cout << ret << endl;

    return 0;
}
