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
#define printLine(l)                    \
    for (__i__ = 0; __i__ < l; __i__++) \
    {                                   \
        cout << "-";                    \
    }                                   \
    cout << endl
#define print2dArr(a, r, c)                 \
    cout << #a << ":\n";                    \
    for (__i__ = 0; __i__ < r; __i__++)     \
    {                                       \
        for (__j__ = 0; __j__ < c; __j__++) \
        {                                   \
            cout << a[__i__][__j__] << " "; \
        }                                   \
        cout << endl;                       \
    }
#define printArr(a, l)                      \
    cout << #a << ": ";                     \
    for (int __i__ = 0; __i__ < l; __i__++) \
    {                                       \
        cout << a[__i__] << " ";            \
    }                                       \
    cout << endl
#define printVar(n) cout << #n << ": " << n << endl
#define printMap(m)                                              \
    cout << #m << ":\n";                                         \
    for (auto __it__ = m.begin(); __it__ != m.end(); __it__++)   \
    {                                                            \
        cout << __it__->first << ": " << __it__->second << endl; \
    }
#define printPair(p) \
    cout << #p << ": {" << p.first << ", " << p.second << "}" << endl

const int INT_INF = numeric_limits<int>::max();
const long long LL_INF = numeric_limits<long long>::max();
/* ------------------------------------------------------------ */

int main()
{
    fastio;

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1); // Starting from vertex one so n + 1

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        // Adj matrix
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dists(n + 1, INT_INF);
    dists[1] = 0; // Starting point has distance zero
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});

    while (!q.empty())
    {
        pair<int, int> currentPair = q.top();
        q.pop();

        int currentDist = currentPair.first;
        int currentVertex = currentPair.second;

        if (currentDist > dists[currentVertex])
            continue; // Only take smaller values

        // Edges
        for (int i = 0; i < (int)adj[currentVertex].size(); i++)
        {
            pair<int, int> otherVertex = adj[currentVertex][i];
            int newDist = currentDist + otherVertex.second;
            if (newDist < dists[otherVertex.first])
            {
                // If smaller then choose it
                dists[otherVertex.first] = newDist;
                q.push({newDist, otherVertex.first});
            }
        }
    }

    vector<int> shortest;
    for (int i = 1; i <= n; i++)
    {
        if (dists[i] == INT_INF)
            shortest.push_back(-1);
        else
            shortest.push_back(dists[i]);
    }

    for (int d : shortest)
    {
        cout << d << endl;
    }

    return 0;
}