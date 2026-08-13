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

    int n;
    cin >> n;

    while (n--)
    {
        string seq;
        cin >> seq;

        int count = 1;
        char previous = seq[0];
        for (int i = 1; i <= (int)seq.length(); i++)
        {
            if (seq[i] != previous)
            {
                cout << count << " " << seq[i - 1] << " ";
                count = 1;
            }
            else
            {
                count++;
            }
            previous = seq[i];
        }
        cout << endl;
    }

    return 0;
}