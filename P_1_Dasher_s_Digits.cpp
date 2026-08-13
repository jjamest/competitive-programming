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

    int n, m;
    cin >> n >> m;

    string x;
    cin >> x;

    vector<int> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }

    int largest_a = -1;
    int largest_i = 0;

    for (int i = 0; i < m; i++)
    {
        if (a[i] >= largest_a)
        {
            largest_a = a[i];
            largest_i = i;
        }
    }

    int found_zeros = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == '0')
        {
            found_zeros++;
            if (largest_i + 1 == found_zeros)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (x[j] != '0')
                    {
                        cout << x[j];
                    }
                }
                for (int j = 0; j < i; j++)
                {
                    if (x[j] != '0')
                    {
                        cout << x[j];
                    }
                }
            }
        }
    }
    cout << endl;
}