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

const int INT_INF = numeric_limits<int>::max();
const long long LL_INF = numeric_limits<long long>::max();
/* ------------------------------------------------------------ */

int main()
{
    fastio;

    int n;
    cin >> n;

    int answer = 0;

    vector<int> hats(n);
    for (int i = 0; i < n; i++)
    {
        cin >> hats[i];
    }

    int opp = n / 2;
    for (int i = 0; i < n; i++)
    {
        int facing = i + opp;
        // Overflow
        if (facing > n - 1)
            facing %= opp;
        // printVar(hats[facing]);
        if (hats[facing] == hats[i])
        {
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}