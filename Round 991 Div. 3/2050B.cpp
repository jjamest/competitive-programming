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
    long long n;
    cin >> n;

    long long sum = 0;
    vector<long long> nums(n);

    for (long long i = 0; i < n; i++)
    {
        long long a;
        cin >> a;

        nums[i] = a;
        sum += a;
    }

    if (sum % n != 0)
    {
        cout << "NO" << endl;
        return;
    }

    long long target = sum / n;
    long long evenDiff = 0, oddDiff = 0;

    for (long long i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            evenDiff += nums[i] - target;
        }
        else
        {
            oddDiff += nums[i] - target;
        }
    }

    if (evenDiff != 0 || oddDiff != 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
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