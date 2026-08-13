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
    int l, r;
    cin >> l >> r;

    if (l == r)
    {
        cout << 1 << endl;
        return;
    }

    vector<int> a = {l};
    int i = 0;

    while (a.back() < r)
    {
        int new_value;
        if ((int)a.size() == 1)
            new_value = a[i] + 1;
        else
            new_value = a[i] + a[i] - a[i - 1] + 1;

        if (new_value <= r)
            a.push_back(new_value);
        else
            break;
        i++;
    }

    cout << (int)a.size() << endl;
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

    return 0;
}