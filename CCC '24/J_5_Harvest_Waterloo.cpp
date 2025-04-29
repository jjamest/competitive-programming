/*
 * Author: fadedpigeon_47
 */

#include <bits/stdc++.h>
using namespace std;

/* ------------------------------------------------------------ */
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

const int INT_INF = numeric_limits<int>::max();
const long long LL_INF = numeric_limits<long long>::max();
/* ------------------------------------------------------------ */

int main()
{
    fastio;

    int r, c;
    cin >> r >> c;

    vector<vector<int>> grid(r, vector<int>(c));
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char value;
            cin >> value;

            if (value == 'S')
                grid[i][j] = 1;
            else if (value == 'M')
                grid[i][j] = 5;
            else if (value == 'L')
                grid[i][j] = 10;
            else
                grid[i][j] = -1;
        }
    }

    int a, b;
    cin >> a >> b;

    int total = 0;

    const int dRow[] = {-1, 1, 0, 0};
    const int dCol[] = {0, 0, -1, 1};

    stack<pair<int, int>> dfs;
    dfs.push({a, b});
    visited[a][b] = true;

    while (!dfs.empty())
    {
        auto [row, col] = dfs.top();
        dfs.pop();

        total += grid[row][col];

        for (int i = 0; i < 4; ++i)
        {
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            if (nRow >= 0 && nRow < r && nCol >= 0 && nCol < c && !visited[nRow][nCol] && grid[nRow][nCol] >= 0)
            {
                dfs.push({nRow, nCol});
                visited[nRow][nCol] = true;
            }
        }
    }

    cout << total << endl;

    return 0;
}