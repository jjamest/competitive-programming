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

    int l;
    cin >> l;

    for (int i = 0; i < l; i++)
    {
        int times;
        char c;
        cin >> times >> c;

        for (int j = 0; j < times; j++)
        {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}