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

    long long n, k;
    cin >> n >> k;

    vector<long long> neg, pos;
    for (long long i = 0; i < n; i++)
    {
        long long h;
        cin >> h;

        if (h < 0)
            neg.push_back(-h);
        else
            pos.push_back(h);
    }

    sort(pos.begin(), pos.end(), greater<>());
    sort(neg.begin(), neg.end(), greater<>());

    long long m = pos.size();
    vector<long long> prefix_sum = {0};
    for (long long x : pos)
    {
        prefix_sum.push_back(prefix_sum.back() + x);
    }

    long long answer = prefix_sum[min(m, k)];

    long long neg_sum = 0;

    for (long long x : neg)
    {
        if (k < 2)
            break;
        neg_sum += x;
        k -= 2;
        answer = max(answer, neg_sum + prefix_sum[min(m, k)]);
    }

    cout << answer << endl;

    return 0;
}