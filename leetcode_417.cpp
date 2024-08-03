#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visted, int r, int c)
{
    if (visted[r][c])
    {
        return;
    }
    visted[r][c] = true;
    if (r + 1 < heights.size() && heights[r + 1][c] >= heights[r][c])
    {
        dfs(heights, visted, r + 1, c);
    }
    if (c + 1 < heights[0].size() && heights[r][c + 1] >= heights[r][c])
    {
        dfs(heights, visted, r, c + 1);
    }
    if (r - 1 >= 0 && heights[r - 1][c] >= heights[r][c])
    {
        dfs(heights, visted, r - 1, c);
    }
    if (c - 1 >= 0 && heights[r][c - 1] >= heights[r][c])
    {
        dfs(heights, visted, r, c - 1);
    }
}
vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    vector<vector<bool>> visted(heights.size(), vector<bool>(heights[0].size(), false));
    vector<vector<bool>> visted1(heights.size(), vector<bool>(heights[0].size(), false));
    vector<vector<int>> result;
    for (int i = 0; i < heights[0].size(); ++i)
    {
        dfs(heights, visted, 0, i);
        dfs(heights, visted1, heights.size() - 1, heights[0].size() - 1 - i);
    }
    for (int i = 1; i < heights.size(); ++i)
    {
        dfs(heights, visted, i, 0);
        dfs(heights, visted1, heights.size() - 1 - i, heights[0].size() - 1);
    }
    for (int i = 0; i < heights.size(); ++i)
    {
        for (int j = 0; j < heights[0].size(); ++j)
        {
            if(visted[i][j] && visted1[i][j])
            {
                vector<int> tmp{i,j};
                result.push_back(tmp);
            }
        }
    }

    for (auto v : visted)
    {
        for (auto b : v)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << "===============" << endl;
    for (auto v : visted1)
    {
        for (auto b : v)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    return result;
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> heights = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    pacificAtlantic(heights);
    return 0;
}
