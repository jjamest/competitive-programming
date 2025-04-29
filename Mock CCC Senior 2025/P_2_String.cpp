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

int main()
{
    fastio;

    int n;
    string s;
    cin >> n >> s;

    for (int round = 0; round < n; round++)
    {

        string newString = "";
        int lengthCount = 1;

        for (int i = 1; i <= (int)s.length(); i++)
        {
            if (s[i] == s[i - 1]) // character is still consecutive
            {
                lengthCount++;
            }
            else // not consecutive
            {
                // cout << "Not consecutive : " << lengthCount << endl;
                // cout << lengthCount << s[i - 1] << endl;
                newString += to_string(lengthCount) + s[i - 1];
                lengthCount = 1;
            }
        }
        s = newString;
    }

    cout << s << endl;

    return 0;
}