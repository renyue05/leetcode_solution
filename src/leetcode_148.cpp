#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *sortList(ListNode *head)
{
    multimap<int, ListNode *> mmap_;
    ListNode *p = head;
    while (p)
    {
        mmap_.insert({p->val, p});
        cout << p->val << endl;
        p = p->next;
    }
    cout << "====================\n";
    ListNode *ret = new ListNode();
    ListNode* tmp = ret;
    for (auto p : mmap_)
    {
        tmp->next = p.second;
        tmp = tmp->next;
        cout << p.first << endl;
    }

    return ret->next;
}
int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(-1, new ListNode(-1, new ListNode(3, new ListNode(4, new ListNode(0)))));
    sortList(head);
    return 0;
}
