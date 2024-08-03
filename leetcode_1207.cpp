#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
bool uniqueOccurrences(vector<int> &arr)
{
    unordered_map<int, int> map;
    for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
    {
        map[(*it)]++;
    }
    int flag = map.begin()->second;
    for (auto it = map.begin(); it != map.end(); ++it)
    {
        if (it->second != flag)
        {
            return false;
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 1, 1, 2, 2, 3};
    // cout << uniqueOccurrences(arr) << endl;
    unordered_map<int, int> m;
    m[-1]++;
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    cout << m.size() << endl;
    return 0;
}
