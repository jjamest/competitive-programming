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

    int n;
    cin >> n;

    unordered_map<int, int> freq;

    int maxFreq = 0;
    int secondMaxFreq = 0;
    set<int> firstFreqCount;
    set<int> secondFreqCount;

    for (int i = 0; i < n; i++)
    {
        int r;
        cin >> r;

        if (freq[r])
        {
            freq[r]++;
        }
        else
        {
            freq[r] = 1;
        }

        if (freq[r] > maxFreq)
        {
            maxFreq = freq[r];
        }
        else if (freq[r] > secondMaxFreq)
        {
            secondMaxFreq = freq[r];
        }
    }

    for (const auto &[key, value] : freq)
    {
        if (value == maxFreq)
        {
            firstFreqCount.insert(key);
        }
        else if (value == secondMaxFreq)
        {
            secondFreqCount.insert(key);
        }
    }

    if (firstFreqCount.size() > 1)
    {
        cout << abs(*firstFreqCount.begin() - *firstFreqCount.rbegin()) << endl;
        return 0;
    }

    if (secondFreqCount.size() > 1)
    {
        int minDiff = abs(*firstFreqCount.begin() - *secondFreqCount.begin());
        int maxDiff = abs(*firstFreqCount.begin() - *secondFreqCount.rbegin());
        cout << max(minDiff, maxDiff);
        return 0;
    }

    cout << abs(*firstFreqCount.begin() - *secondFreqCount.rbegin()) << endl;

    return 0;
}