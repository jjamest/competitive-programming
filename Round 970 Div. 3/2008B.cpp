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
    int n;
    string s;
    cin >> n >> s;

    int side = sqrt(n);

    if (side * side != n)
    {
        cout << "No" << endl;
        return;
    }

    for (int i = 0; i < side; i++)
    {
        for (int j = 0; j < side; j++)
        {
            if (s[i * side + j] == '1')
            {
                if (!(i == 0 || i == side - 1 || j == 0 || j == side - 1))
                {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }

    cout << "Yes" << endl;
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