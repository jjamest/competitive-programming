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

const int INT_INF = numeric_limits<int>::max();
const long long LL_INF = numeric_limits<long long>::max();
/* ------------------------------------------------------------ */

int main()
{
    fastio;

    int t, n;
    cin >> t >> n;

    for (int i = 0; i < t; i++)
    {
        map<char, int> count;
        string s;

        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            s += c;
            count[c]++;
        }

        char answer = 'T';

        bool heavyNext = true;
        bool lightNext = true;
        for (int j = 0; j < n; j++)
        {
            if (count[s[j]] > 1 && heavyNext) // Heavy
            {
                heavyNext = false;
                lightNext = true;
            }
            else if (count[s[j]] <= 1 && lightNext) // Light
            {
                heavyNext = true;
                lightNext = false;
            }
            else
            {
                answer = 'F';
                break;
            }
        }

        cout << answer << endl;
    }

    return 0;
}