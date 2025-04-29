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

    int m, n;
    cin >> m >> n;

    map<int, vector<pair<int, int>>> nums;
    queue<pair<int, int>> q;
    bool visited[1001][1001] = {false};

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int c;
            cin >> c;

            if (nums.count(c) > 0)
                nums[c].push_back({i, j});
            else
                nums[c] = {{i, j}};
        }
    }

    q.push({m, n});
    visited[m][n] = true;
    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        if ((current.first == 1) && (current.second == 1))
        {
            cout << "yes" << endl;
            return 0;
        }
        else
        {
            int product = current.first * current.second;
            for (int i = 0; i < (int)nums[product].size(); i++)
            {
                pair<int, int> position = nums[product][i];
                if (!visited[position.first][position.second])
                {
                    q.push({position.first, position.second});
                    visited[position.first][position.second] = true;
                }
            }
        }
    }

    cout << "no" << endl;

    return 0;
}