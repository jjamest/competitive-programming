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

    int t;
    cin >> t;

    while (t--)
    {
        long long x, y, k;
        cin >> x >> y >> k;

        long long x_jumps = x / k;
        long long y_jumps = y / k;
        if (x % k > 0)
            x_jumps++;
        if (y % k > 0)
            y_jumps++;

        if (x_jumps > y_jumps)
        {
            cout << 2 * y_jumps + (2 * (x_jumps - y_jumps) - 1) << endl;
            continue;
        }
        else if (y_jumps > x_jumps)
        {
            cout << 2 * y_jumps << endl;
            continue;
        }
        else
        {
            cout << 2 * x_jumps << endl;
            continue;
        }
    }
    return 0;
}