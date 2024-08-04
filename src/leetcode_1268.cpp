#include <iostream>
#include <vector>
#include <string>
using namespace std;
// vector<string> tmp_s;
class Trie
{
public:
    vector<Trie *> children;
    bool isEnd;
    string m_word;
    Trie() : children(26), isEnd(false) {}

    void insert(string word)
    {
        Trie *node = this;
        for (char ch : word)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
            {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
        node->m_word = word;
    }
    Trie *func(string word)
    {
        Trie *node = this;
        for (auto ch : word)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
            {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }
    bool search(string word)
    {
        Trie *node = func(word);
        return node && node->isEnd;
    }

    bool startsWith(string prefix)
    {
        Trie *node = func(prefix);
        return node ? true : false;
    }
};
void findWord(Trie *t, vector<string> &tmp_s)
{

    if (tmp_s.size() >= 3)
    {
        return;
    }
    if (t->isEnd)
    {
        tmp_s.push_back(t->m_word);
        // cout << t->m_word << " ";
    }
    for (auto child : t->children)
    {
        if (child)
        {
            findWord(child, tmp_s);
        }
    }
}
class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        vector<vector<string>> ret;
        Trie *trie = new Trie();
        for (auto word : products)
        {
            trie->insert(word);
        }
        // 前缀树已经建立好
        string p;
        for (char ch : searchWord)
        {
            vector<string> tmp_s;
            p += ch;
            ch -= 'a';
            Trie *node = trie->func(p);
            if (node)
            {
                findWord(node, tmp_s);
            }
            // cout << endl;
            ret.emplace_back(tmp_s);
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> products{"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string searchWord("mouse");
    s.suggestedProducts(products, searchWord);
    return 0;
}
