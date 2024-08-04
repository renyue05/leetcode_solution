#include <iostream>
#include <vector>
#include <queue>
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
bool func(TreeNode *root, TreeNode *subRoot)
{
    if ((root && !subRoot) || (!root && subRoot))
    {
        return false;
    }
    if (!root && !subRoot)
    {
        return true;
    }
    if (root->val != subRoot->val)
    {
        return false;
    }
    return (func(root->left, subRoot->left) && func(root->right, subRoot->right));
}
bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    bool ret = false;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *tmp = q.front();
        q.pop();
        if (func(tmp, subRoot))
        {
            return true;
        }
        if (tmp->left)
        {
            q.push(tmp->left);
        }
        if (tmp->right)
        {
            q.push(tmp->right);
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{

    return 0;
}
