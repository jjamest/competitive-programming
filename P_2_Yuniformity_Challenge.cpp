/*
 * Author: fadedpigeon_47
 */

#include <bits/stdc++.h>
using namespace std;

/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */
template <typename T, typename = void>
struct is_container : std::false_type
{
};
template <typename T>
struct is_container<
    T, std::void_t<decltype(std::declval<T>().begin()), decltype(std::declval<T>().end())>>
    : std::true_type
{
};
template <typename T>
typename std::enable_if<!is_container<T>::value && !std::is_same<T, std::string>::value>::type
print(const T &arg)
{
    std::cout << arg;
}
void print(const std::string &arg)
{
    std::cout << '"' << arg << '"';
}
template <typename T1, typename T2>
void print(const std::pair<T1, T2> &p)
{
    std::cout << "(";
    print(p.first);
    std::cout << ", ";
    print(p.second);
    std::cout << ")";
}
template <typename Container>
typename std::enable_if<is_container<Container>::value>::type
print(const Container &c)
{
    std::cout << "[";
    auto it = c.begin();
    while (it != c.end())
    {
        print(*it);
        if (++it != c.end())
        {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}
template <typename T, typename... Args>
void print(const T &first, const Args &...rest)
{
    print(first);
    if (sizeof...(rest) > 0)
    {
        std::cout << " ";
        print(rest...);
    }
}
template <typename... Args>
void println(const Args &...args)
{
    print(args...);
    std::cout << std::endl;
}
#define PRINT(var)                  \
    do                              \
    {                               \
        std::cout << #var << " = "; \
        print(var);                 \
        std::cout << std::endl;     \
    } while (0)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

const int INT_INF = numeric_limits<int>::max();
const long long LL_INF = numeric_limits<long long>::max();

#define int long long
/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */

int32_t main()
{
    fastio;

    int n, q;
    cin >> n >> q;

    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }

    vector<int> psa(n + 1);
    vector<int> rit(n + 1);
    map<int, int> d;
    for (int i = 1; i <= n; i++)
    {
        psa[i] = psa[i - 1] + (nums[i] != nums[i - 1]);
        d[nums[i]] = i;
        if (d.count(-nums[i]))
        {
            rit[i] = d[-nums[i]];
        }
        rit[i] = max(rit[i - 1], rit[i]);
    }

    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;

        if (psa[r] == psa[l] || rit[r] >= l)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}