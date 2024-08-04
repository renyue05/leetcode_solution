#include <iostream>
#include <string>
using namespace std;
struct node
{
    int val;
    node* next;
};
int main(int argc, char const *argv[])
{

    int a = 10;
    int *p = &a;
    node * n1 = new node();
    node * n2 = new node();
    n1->next = n2;
    n1->val = 1;
    n2->val = 2;
    n2 = nullptr;
    return 0;
}
