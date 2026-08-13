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

const int INT_INF = numeric_limits<int>::max();
const long long LL_INF = numeric_limits<long long>::max();
/* ------------------------------------------------------------ */

int main()
{
    fastio;

    int a3, a2, a1;
    cin >> a3 >> a2 >> a1;

    int apples = a3 * 3 + a2 * 2 + a1;

    int b3, b2, b1;
    cin >> b3 >> b2 >> b1;

    int bananas = b3 * 3 + b2 * 2 + b1;

    if (apples > bananas)
        cout << 'A';
    else if (bananas > apples)
        cout << 'B';
    else
        cout << 'T';
    cout << endl;

    return 0;
}