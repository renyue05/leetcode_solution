#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;
struct node
{
    string m_key;
    double m_val;
    node *m_father;
    node() : m_key(""), m_val(0), m_father(nullptr) {}
    node(string key, float val, node *father) : m_key(key), m_val(val), m_father(father) {}
};

vector<double> calcEquation(vector<vector<string>> &equations,
                            vector<double> &values,
                            vector<vector<string>> &queries)
{
    vector<double> ret;
    map<string, node *> m_set;
    for (int i = 0; i < equations.size(); ++i)
    {
        if ((!m_set.count(equations[i][0])) && (!m_set.count(equations[i][1])))
        {

            m_set.insert({equations[i][0], new node(equations[i][0], 1, nullptr)});

            m_set.insert({equations[i][1], new node(equations[i][1], 1 / values[i], m_set[equations[i][0]])});
        }
        else if (!m_set.count(equations[i][0]))
        {
            m_set.insert({equations[i][0], new node(equations[i][0], values[i], m_set[equations[i][1]])});
        }
        else
        {
            m_set.insert({equations[i][1], new node(equations[i][1], 1 / values[i], m_set[equations[i][0]])});
        }
    }
    for (int i = 0; i < queries.size(); ++i)
    {
        string v0 = queries[i][0];
        string v1 = queries[i][1];
        if ((!m_set.count(v0)) || (!m_set.count(v1)))
        {
            ret.push_back(-1.0);
        }
        else
        {
            double t0 = 1, t1 = 1;
            auto p0 = m_set[v0], p1 = m_set[v1];
            while (p0)
            {
                t0 *= p0->m_val;
                p0 = p0->m_father;
            }
            while (p1)
            {
                t1 *= p1->m_val;
                p1 = p1->m_father;
            }
            ret.push_back(t0 / t1);
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    vector<vector<string>> equations{{"a", "e"}, {"b", "e"}};
    vector<double> values{4.0, 3.0};
    vector<vector<string>> queries{{"a", "b"}, {"e", "e"}, {"x", "x"}, {"a", "a"}, {"x", "x"}};
    auto ret = calcEquation(equations, values, queries);
    for (auto val : ret)
    {
        cout << val << endl;
    }
    return 0;
}
