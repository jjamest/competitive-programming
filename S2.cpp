#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    long long c;
    cin >> s >> c;

    vector<pair<long long, char>> v;
    for (long long i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i]))
        {
            string temp = "";
            for (long long j = i + 1; j < s.length(); j++)
            {
                if (isdigit(s[j]))
                    temp += s[j];
                else
                    break;
            }
            v.push_back({stoll(temp), s[i]});
        }
    }

    long long len = 0;
    for (auto it : v)
    {
        // cout << it.first << " " << it.second << endl;
        len += it.first;
    }

    long long remaining = c % len;
    char current_char = s[0];
    while (remaining >= 0)
    {
        for (auto it : v)
        {
            remaining -= it.first;
            current_char = it.second;
            if (remaining < 0)
                break;
        }
    }

    cout << current_char << endl;

    return 0;
}