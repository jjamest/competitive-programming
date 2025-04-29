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

    int n;
    cin >> n;

    int cornerMin = INT_INF;
    int cornerIdx = -1;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int v;
            cin >> v;
            grid[i][j] = v;

            if (v < cornerMin)
            {
                cornerMin = v;
                if (i == 0 && j == 0)
                    cornerIdx = 1;
                else if (i == 0 && j == n - 1)
                    cornerIdx = 2;
                else if (i == n - 1 && j == 0)
                    cornerIdx = 3;
                else if (i == n - 1 && j == n - 1)
                    cornerIdx = 4;
            }
        }
    }

    switch (cornerIdx)
    {
    // No rotating
    case 1:
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << grid[i][j] << ' ';
            }
            cout << endl;
        }
        break;
    // Once to the left
    case 2:
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << grid[j][n - i - 1] << ' ';
            }
            cout << endl;
        }
        break;
    // Once to the right
    case 3:
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << grid[n - j - 1][i] << ' ';
            }
            cout << endl;
        }
        break;

    // 180 degrees
    case 4:
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << grid[n - i - 1][n - j - 1] << ' ';
            }
            cout << endl;
        }
        break;

    default:
        break;
    }

    return 0;
}