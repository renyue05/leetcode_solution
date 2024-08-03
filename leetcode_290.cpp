#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
bool wordPattern(string pattern, string s)
{
    unordered_map<char, int> pmap;
    unordered_map<string, int> smap;
    vector<string> vec;
    int num = 0;
    for (auto c : pattern)
    {
        if (!pmap.count(c))
        {
            pmap.insert({c, num++});
        }
    }

    int p = 0;
    num = 0;
    int pidx = 0;
    while (p < s.size())
    {
        size_t t = s.find(' ', p);
        if (t > s.size())
        {
            // cout << s.substr(p);
            if (!smap.count(s.substr(p)))
            {
                smap.insert({s.substr(p), num++});
            }
            vec.push_back(s.substr(p));

            break;
        }
        // cout << s.substr(p, t - p);
        if (!smap.count(s.substr(p, t - p)))
        {
            smap.insert({s.substr(p, t - p), num++});
        }
        vec.push_back(s.substr(p, t - p));
        p = t + 1;
    }
    for (int i = 0; i < pattern.size(); ++i)
    {
        if (pmap[pattern[i]] != smap[vec[i]])
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    string pattern = "abba";
    string s = "dog cat cat dog";
    wordPattern(pattern, s);
    return 0;
}
