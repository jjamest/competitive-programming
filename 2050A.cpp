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
    int n, m;
    cin >> n >> m;

    vector<string> words(n);

    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    int x = 0;
    int characters = 0;

    for (int i = 0; i < n; i++)
    {
        int wordLength = (int)words[i].length();

        if (wordLength + characters <= m)
        {
            // Works
            characters += wordLength;
            x++;
        }
        else
        {
            break;
        }
    }

    cout << x << endl;
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