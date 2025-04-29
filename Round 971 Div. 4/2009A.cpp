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
        int a, b;
        cin >> a >> b;

        int c = (a + b) / 2;

        cout << (c - a) + (b - c) << endl;
    }

    return 0;
}