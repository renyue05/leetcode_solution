#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include<set>
using namespace std;
// int result;
int m;
vector<string> path;
bool func_1(string s1, string s2)
{
    for (int i = 0; i < s1.size(); ++i)
    {
        string s11 = s1;
        string s22 = s2;
        if (s11.erase(i, 1) == s22.erase(i, 1))
        {
            return true;
        }
    }
    return false;
}
void dfs(string beginWord, string endWord, unordered_map<string, bool> &visted, vector<string> &wordList)
{
    if (beginWord == endWord)
    {
        m = m < path.size() ? m : path.size();
        cout << 123 << endl;
        for (auto w : path)
        {
            cout << w << " ";
        }
        cout << endl;
    }
    if (beginWord == endWord || visted[beginWord])
    {
        // cout << 123 << endl;
        return;
    }
    visted[beginWord] = true;
    for (auto word : wordList)
    {
        if (func_1(beginWord, word) && !visted[word] && beginWord != word)
        {

            path.push_back(word);
            dfs(word, endWord, visted, wordList);
            path.pop_back();
        }
    }
    visted[beginWord] = false;
}
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    int result = 0;
    m = 10000;
    unordered_map<string, bool> visted;
    for (auto word : wordList)
    {
        visted.insert({word, false});
    }
    dfs(beginWord, endWord, visted, wordList);
    return (m == 10000) ? 0 : m + 1;
}

int main(int argc, char const *argv[])
{
    string beginWord = "qa";
    string endWord = "sq";
    // vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
    // vector<string> wordList{"hot", "dot", "dog", "lot", "log"};
    // vector<string> wordList{"hot", "dog", "cog", "pot", "dot"};
    vector<string> wordList{"si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le", "av", "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo", "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye"};
    int result = ladderLength(beginWord, endWord, wordList);
    cout << result << endl;
    
    set<int> s;
    
    return 0;
}
