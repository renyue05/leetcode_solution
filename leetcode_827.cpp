#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int mark;
int result;
void print(vector<vector<int>> &grid)
{
    for (auto v : grid)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visted, int r, int c)
{
    if (visted[r][c] || grid[r][c] == 0)
    {
        return;
    }
    grid[r][c] = mark;
    visted[r][c] = true;
    result++;
    if (r - 1 >= 0)
    {
        dfs(grid, visted, r - 1, c);
    }
    if (r + 1 < grid.size())
    {
        dfs(grid, visted, r + 1, c);
    }
    if (c - 1 >= 0)
    {
        dfs(grid, visted, r, c - 1);
    }
    if (c + 1 < grid[0].size())
    {
        dfs(grid, visted, r, c + 1);
    }
}
int largestIsland(vector<vector<int>> &grid)
{
    int max = 0;
    result = 0;
    mark = 2;
    unordered_map<int, int> m;
    unordered_set<int> s;
    m.insert({0, 0});
    vector<vector<bool>> visted(grid.size(), vector<bool>(grid[0].size(), false));
    for (int r = 0; r < grid.size(); ++r)
    {
        for (int c = 0; c < grid[0].size(); ++c)
        {
            if (grid[r][c] && !visted[r][c])
            {
                result = 0;
                dfs(grid, visted, r, c);
                m.insert({mark, result});
                max = max > result ? max : result;
                mark++;
            }
        }
    }
    print(grid);
    for (auto p : m)
    {
        cout << p.first << " " << p.second << endl;
    }
    for (int r = 0; r < grid.size(); ++r)
    {
        for (int c = 0; c < grid[0].size(); ++c)
        {
            if (!grid[r][c])
            {

                result = 1;
                s.clear();
                if (r - 1 >= 0)
                {
                    // result += m[grid[r - 1][c]];
                    s.insert(grid[r - 1][c]);
                }
                if (r + 1 < grid.size())
                {
                    // result += m[grid[r + 1][c]];
                    s.insert(grid[r + 1][c]);
                }
                if (c - 1 >= 0)
                {
                    // result += m[grid[r][c - 1]];
                    s.insert(grid[r][c - 1]);
                }
                if (c + 1 < grid[0].size())
                {
                    // result += m[grid[r][c + 1]];
                    s.insert(grid[r][c + 1]);
                }
                for (auto n : s)
                {
                    result += m[n];
                }
                max = max > result ? max : result;
            }
        }
    }
    return max;
}
int main(int argc, char const *argv[])
{
   /*  vector<vector<int>> grid{{0, 1, 0, 0, 0, 0, 0, 0},
                             {1, 1, 1, 0, 0, 0, 1, 1},
                             {0, 1, 1, 1, 0, 1, 1, 1},
                             {0, 0, 0, 0, 1, 0, 0, 0},
                             {0, 0, 0, 0, 1, 0, 0, 0},
                             {0, 0, 1, 0, 0, 0, 0, 0},
                             {0, 1, 1, 0, 0, 1, 1, 0}}; */
    vector<vector<int>> grid{{1, 1}, {1, 0}};
    cout << grid.size() << grid[0].size() << endl;
    int result = largestIsland(grid);
    cout << result << endl;
    return 0;
}
