#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a, b, x, y;
    cin >> a >> b >> x >> y;

    long long test1 = 2LL * (a + x) + 2LL * max(b, y);
    long long test2 = 2LL * max(a, x) + 2LL * (b + y);

    cout << min(test1, test2) << endl;

    return 0;
}