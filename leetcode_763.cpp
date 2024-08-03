#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
vector<int> partitionLabels(string s)
{
    vector<int> ret;
    int pre = -1;
    unordered_map<char, int> last_;
    unordered_map<char, int> cnum_;
    for (int i = 0; i < s.size(); ++i)
    {
        last_[s[i]] = i;
        cnum_[s[i]]++;
    }

    for (int i = 0; i < s.size(); ++i)
    {
        int tmp_last = last_[s[i]];
        for (int j = 0; j < tmp_last; ++j)
        {
            tmp_last = last_[s[j]] > tmp_last ? last_[s[j]] : tmp_last;
        }
        ret.push_back(tmp_last - pre);
        pre = tmp_last;
        i = tmp_last;
    }

    return ret;
}
int main(int argc, char const *argv[])
{
    string s("eaaaabaaec");
    auto ret = partitionLabels(s);
    for (int i : ret)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
