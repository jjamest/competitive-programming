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

void generate(vector<int> &current, int remaining, int max, vector<vector<int>> &result)
{
    if (remaining == 0)
    {
        result.push_back(current);
        return;
    }
    for (int i = min(remaining, max); i >= 1; i--)
    {
        current.push_back(i);
        generate(current, remaining - i, i, result);
        current.pop_back();
    }
}

int main()
{
    fastio;

    int n;
    cin >> n;

    // vector<int> a(n, 1);

    // printArr(a, n);

    // while ((int)a.size() > 1)
    // {
    //     int cSize = (int)a.size();

    //     // check ones
    //     if (a[cSize - 1] == 1 && a[cSize - 2] && 1) // there are 2 ones available to merge
    //     {
    //         // merge
    //         a.pop_back();
    //         a[(int)a.size() - 1] = 2;
    //         sort(a.begin(), a.end());
    //     }
    //     else // theres only one or no ones available to merge
    //     {
    //         // check for when theres one non-one and a one like 4 1

    //         // take from the right most non-one
    //         for (int i = (int)a.size() - 1; i >= 0; i--)
    //         {
    //             if (a[i] != 1) // we got a non-one number
    //             {
    //                 // transfer to the left
    //                 a[i]--;
    //                 a[i - 1]++;
    //                 sort(a.begin(), a.end()); // sort
    //             }
    //         }
    //     }
    // }

    vector<vector<int>> result;
    vector<int> current;
    generate(current, n, n, result);
    for (auto combo : result)
    {
        for (int i = 0; i < (int)combo.size(); i++)
        {
            cout << combo[i];
            if (i < (int)combo.size() - 1)
                cout << " ";
        }
        // for (int num : combo)
        // {
        //     cout << num;
        // }
        cout << endl;
    }

    return 0;
}