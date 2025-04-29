#include <bits/stdc++.h>
using namespace std;

static const int MAXV = 110;

vector<int> graphAdj[MAXV];

bool visited[MAXV];

int bestPath = 0;

void dfs(int node, int length)
{

    bestPath = max(bestPath, length);

    for (int nxt : graphAdj[node])
    {
        if (!visited[nxt])
        {
            visited[nxt] = true;
            dfs(nxt, length + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_set<int> nodeSet;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        graphAdj[a].push_back(b);
        graphAdj[b].push_back(a);
        nodeSet.insert(a);
        nodeSet.insert(b);
    }

    bestPath = 0;
    for (auto start : nodeSet)
    {
        memset(visited, false, sizeof(visited));
        visited[start] = true;
        dfs(start, 1);
    }

    cout << bestPath << "\n";
    return 0;
}