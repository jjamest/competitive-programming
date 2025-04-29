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
#define printArr(a, l)                      \
    cout << #a << ": ";                     \
    for (int __i__ = 0; __i__ < l; __i__++) \
    {                                       \
        cout << a[__i__] << " ";            \
    }                                       \
    cout << endl

const int INT_INF = numeric_limits<int>::max();
const long long LL_INF = numeric_limits<long long>::max();
/* ------------------------------------------------------------ */

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main()
{
    fastio;

    long long n, m;
    cin >> n >> m;

    vector<long long> count(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int answer;
            cin >> answer;

            count[j] += answer;
        }
    }

    vector<pair<int, int>> vec(m);
    for (int i = 0; i < m; i++)
    {
        vec[i] = {count[i], i + 1};
    }

    // for (auto it : vec)
    // {
    //     cout << it.first << " " << it.second << endl;
    // }

    // cout << endl;

    sort(vec.begin(), vec.end(), compare);

    for (int i = 0; i < m; i++)
    {
        cout << vec[i].second;
        if (i < m - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}