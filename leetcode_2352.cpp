#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <hash_map>

using namespace std;
int equalPairs(vector<vector<int>> &grid)
{
    int result = 0;
    vector<vector<int>> grid1(grid.size(), vector<int>(grid.size()));
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid.size(); ++j)
        {
            grid1[j][i] = grid[i][j];
        }
    }
    map<vector<int>, int> m;
    for (auto v : grid)
    {
        m[v]++;
    }
    for (auto v : grid1)
    {
        if (m.find(v) != m.end())
        {
            result += m[v];
        }
    }
    return result;
}
int main(int argc, char const *argv[])
{
    vector<int> vec1{1, 2, 3, 4};
    vector<int> vec2{1, 2, 3, 4};
    cout << (vec1 == vec2) << endl;
    return 0;
}
