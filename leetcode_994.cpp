#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int bfs(vector<vector<int>> &grid, vector<vector<bool>> &visted)
{
    int ans = 0;
    int org = 0;
    int good = 0;
    queue<pair<int, int>> q;
    for (int r = 0; r < grid.size(); ++r)
    {
        for (int c = 0; c < grid[0].size(); ++c)
        {
            if (grid[r][c])
            {
                org++;
            }
            if (grid[r][c] == 2)
            {
                q.push({r, c});
            }
            if (grid[r][c] == 1)
            {
                good++;
            }
        }
    }
    if (!org)
    {
        return 0;
    }
    while (!q.empty())
    {
        int l = q.size();
        for (int i = 0; i < l; ++i)
        {
            auto cur = q.front();
            q.pop();
            int c_r = cur.first;
            int c_c = cur.second;
            if (visted[c_r][c_c])
            {
                continue;
            }
            visted[c_r][c_c] = true;
            if (c_r - 1 >= 0 && grid[c_r - 1][c_c] == 1 && !visted[c_r - 1][c_c])
            {
                grid[c_r - 1][c_c] = 2;
                good--;
                q.push({c_r - 1, c_c});
            }
            if (c_r + 1 < grid.size() && grid[c_r + 1][c_c] == 1 && !visted[c_r + 1][c_c])
            {
                grid[c_r + 1][c_c] = 2;
                good--;
                q.push({c_r + 1, c_c});
            }
            if (c_c - 1 >= 0 && grid[c_r][c_c - 1] == 1 && !visted[c_r][c_c - 1])
            {
                grid[c_r][c_c - 1] = 2;
                good--;
                q.push({c_r, c_c - 1});
            }
            if (c_c + 1 < grid[0].size() && grid[c_r][c_c + 1] == 1 && !visted[c_r][c_c + 1])
            {
                grid[c_r][c_c + 1] = 2;
                good--;
                q.push({c_r, c_c + 1});
            }
        }
        ans++;
    }
    if (good)
    {
        return -1;
    }
    return ans - 1;
}
int orangesRotting(vector<vector<int>> &grid)
{

    vector<vector<bool>> visted(grid.size(), vector<bool>(grid[0].size(), false));
    return bfs(grid, visted);
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> grid{{1, 0, 2, 2, 2}};
    cout << orangesRotting(grid) << endl;;
    return 0;
}
