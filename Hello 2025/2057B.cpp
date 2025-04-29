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

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<int> cnt = {1};
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            cnt.back()++;
        }
        else
        {
            cnt.push_back(1);
        }
    }

    sort(cnt.begin(), cnt.end());
    int m = cnt.size();
    for (int i = 0; i < m - 1; i++)
    {
        if (cnt[i] > k)
        {
            cout << m - i << endl;
            return;
        }
        k -= cnt[i];
    }
    cout << 1 << endl;
}

int main()
{
    fastio;

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}