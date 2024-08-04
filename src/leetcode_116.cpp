#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
Node *connect(Node *root)
{
    Node *ret;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; ++i)
        {
            Node *p = q.front();
            q.pop();
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);

            if (i < size - 1)
            {
                p->next = q.front();
            }
            else
            {
                p->next = nullptr;
            }
        }
    }

    return root;
}

int main(int argc, char const *argv[])
{

    return 0;
}
