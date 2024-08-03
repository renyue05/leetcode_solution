#include <queue>
#include <iostream>
#include <vector>

using namespace std;
int bfs(vector<vector<char>> &maze, vector<vector<int>> &visted, int r, int c)
{
    int ans = 0;
    queue<pair<int, int>> q;
    q.push({r, c});
    while (!q.empty())
    {
        /* pair<int, int> cur = q.front();
        q.pop();
        int curr = cur.first;
        int curc = cur.second;
        if (visted[curr][curc])
        {
            continue;
        }
        visted[curr][curc] = 1;
        if (!(curr == r && curc == c))
        {
            if ((curr == 0 || curr == maze.size() - 1 || curc == 0 || curc == maze[0].size() - 1))
            {
                return ans;
            }
        } */
        int s = q.size();
        for (int i = 0; i < s; ++i)
        {
            pair<int, int> curr = q.front();
            q.pop();
            int currr = curr.first;
            int currc = curr.second;
            if (visted[currr][currc])
            {
                continue;
            }
            visted[currr][currc] = 1;
            if (!(currr == r && currc == c))
            {
                if ((currr == 0 || currr == maze.size() - 1 || currc == 0 || currc == maze[0].size() - 1))
                {
                    return ans;
                }
            }

            if (currr - 1 >= 0 && maze[currr - 1][currc] == '.')
            {
                q.push({currr - 1, currc});
            }
            if (currr + 1 < maze.size() && maze[currr + 1][currc] == '.')
            {
                q.push({currr + 1, currc});
            }
            if (currc - 1 >= 0 && maze[currr][currc - 1] == '.')
            {
                q.push({currr, currc - 1});
            }
            if (currc + 1 < maze[0].size() && maze[currr][currc + 1] == '.')
            {
                q.push({currr, currc + 1});
            }
        }

        ans++;
    }
    return -1;
}
int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
{
    vector<vector<int>> visted(maze.size(), vector<int>(maze[0].size(), 0));
    int ans = bfs(maze, visted, entrance[0], entrance[1]);
    return ans;
}
int main(int argc, char const *argv[])
{

    // vector<vector<char>> maze{{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
    vector<vector<char>> maze{{'+', '+', '+', '+'}, {'.', '.', '.', '.'}, {'+', '+', '+', '+'}};
    /* vector<vector<char>> maze{{'+', '.', '+', '+', '+', '+', '+'},
                              {'+', '.', '+', '.', '.', '.', '+'},
                              {'+', '.', '+', '.', '+', '.', '+'},
                              {'+', '.', '.', '.', '.', '.', '+'},
                              {'+', '+', '+', '+', '.', '+', '.'}}; */
    vector<int> en{0, 1};
    int ans = nearestExit(maze, en);
    cout << ans << endl;
    return 0;
}
