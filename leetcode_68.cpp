#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    vector<string> ret;
    for (int i = 0; i < words.size(); ++i)
    {
    }
    int tmplen = 0;
    int idx = 0;
    while (idx < words.size())
    {
        vector<string> tmpWords;

        int wordlen = 0;

        tmplen = words[idx].size();
        wordlen = words[idx].size();
        tmpWords.push_back(words[idx]);
        idx++;
        while (tmplen + 1 + words[idx].size() <= maxWidth)
        {
            tmplen += (1 + words[idx].size());
            wordlen += words[idx].size();
            tmpWords.push_back(words[idx]);
            idx++;
        }
        cout << tmplen - tmpWords.size() + 1 << endl;
        string s;
        if (idx == words.size())
        {
            for (auto ss : tmpWords)
            {
                s += ss;
                s += " ";
            }
            s.resize(maxWidth, ' ');
        }
        else
        {
            if (tmpWords.size() == 1)
            {
                s += tmpWords[0];
                s.resize(maxWidth, ' ');
            }
            else
            {
                // tmpWords.size() 是单词个数
                // tmplen - tmpWords.size() + 1 是字母总数
                // maxWidth - tmplen + tmpWords.size() - 1为空格总数
                // 将空格数分为 tmpWords.size() - 1份
                int space_nums = maxWidth - tmplen + tmpWords.size() - 1;
                int n = tmpWords.size() - 1;
                int min_space = space_nums / n;
                int more_num = space_nums % n;
                s += tmpWords[0];
                for (int i = 1; i < tmpWords.size(); ++i)
                {
                    s += string((i - 1) < more_num ? (min_space + 1) : (min_space), ' ');
                    s += tmpWords[i];
                }
            }
        }
        ret.emplace_back(s);
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    vector<string> words{"What","must","be","acknowledgment","abilities","be","abilities","be"};
    auto ret = fullJustify(words, 16);
    for_each(ret.begin(), ret.end(), [](string &str)
             { cout << str << endl; });
    return 0;
}
