#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
void bfs(vector<vector<int>> &grid, vector<vector<int>> &visted, int x, int y)
{
    if (visted[x][y])
    {
        return;
    }
    int h = grid.size();
    int w = grid[0].size();
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        int x1 = cur.first;
        int y1 = cur.second;
        visted[x1][y1] = true;
        for (int i = 0; i < 4; ++i)
        {
            int x2 = x1 + dir[i][0];
            int y2 = y1 + dir[i][1];
            if (x2 >= 0 && x2 < w && y2 >= 0 && y2 < h && grid[x2][y2])
            {
                q.push({x2, y2});
            }
        }
    }
}
int numIslands(vector<vector<char>> &grid)
{
    vector<vector<bool>> visted(grid.size(), vector<bool>(grid[0].size(), false));
}
int main(int argc, char const *argv[])
{

    return 0;
}
