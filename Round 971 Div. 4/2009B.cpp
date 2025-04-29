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
        int n;
        cin >> n;

        vector<int> notes;
        for (int i = 0; i < n; i++)
        {
            for (int val = 0; val < 4; val++)
            {
                char note;
                cin >> note;
                if (note == '#')
                {
                    notes.push_back(val + 1);
                }
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            cout << notes[i] << " ";
        }
        cout << endl;
    }

    return 0;
}