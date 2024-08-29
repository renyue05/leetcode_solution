#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> result;
    unordered_map<string, multiset<string>> map;
    for (const string &str : strs)
    {
        string key;
        vector<int> charNum(26, 0);
        for (char c : str)
        {
            ++charNum[c - 'a'];
        }
        for (int i = 0; i < charNum.size(); ++i)
        {
            if (charNum[i])
            {
                key.push_back('a' + i);
                // key.push_back
                key.append(std::to_string(charNum[i]));
            }
        }
        map[key].insert(str);
    }
    for(auto m : map)
    {
        vector<string> strs;
        for(string str : m.second)
        {
            strs.push_back(str);
        }
        result.emplace_back(strs);
    }
    return result;
}
int main(int argc, char const *argv[])
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> result = groupAnagrams(strs);

    for (auto res : result)
    {
        for (auto str : res)
        {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
