#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    list<TreeNode *> q;
    vector<vector<int>> ret;
    if (!root)
    {
        return ret;
    }
    q.push_back(root);
    int layer = 0;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> v;
        for (int i = 0; i < size; ++i)
        {
            TreeNode *p = q.front();
            q.pop_front();
            v.push_back(p->val);
            if (p->left)
                q.push_back(p->left);
            if (p->right)
                q.push_back(p->right);
        }
        if (layer % 2)
        {
            reverse(v.begin(), v.end());
        }
        ret.push_back(v);
        ++layer;
    }
    return ret;
}
int main(int argc, char const *argv[])
{

    return 0;
}
