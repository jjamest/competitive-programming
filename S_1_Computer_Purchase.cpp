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

    if (n == 0)
    {
        cout << endl;
        return 0;
    }

    map<string, int> mp;

    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;

        int r, s, d;
        cin >> r >> s >> d;

        mp[name] = 2 * r + 3 * s + d;
    }

    vector<pair<string, int>> temp(mp.begin(), mp.end());

    sort(temp.begin(), temp.end(), [](const pair<string, int> &a, const pair<string, int> &b)
         { return a.second > b.second; });

    cout << temp[0].first << endl;
    if (temp.size() > 1)
    {
        cout << temp[1].first << endl;
    }

    return 0;
}