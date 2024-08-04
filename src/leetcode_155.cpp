#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
using namespace std;
class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        m_stack.push(val);
        m_map[val]++;
    }

    void pop()
    {
        m_map[m_stack.top()]--;
        if (m_map[m_stack.top()] == 0)
        {
            m_map.erase(m_stack.top());
        }
        m_stack.pop();
    }

    int top()
    {
        return m_stack.top();
    }

    int getMin()
    {
        return m_map.begin()->first;
    }

private:
    map<int, int> m_map;
    stack<int> m_stack;
};
int main(int argc, char const *argv[])
{
    set<int> s;
    s.insert(100000);
    s.insert(10);
    s.insert(5656);
    for (auto val : s)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
