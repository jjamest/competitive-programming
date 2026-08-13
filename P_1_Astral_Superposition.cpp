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

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    vector<vector<int>> final_photo(n, vector<int>(n, 0));
    vector<vector<int>> first_photo(n, vector<int>(n, 0));
    vector<vector<bool>> must(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;

            if (c == 'G')
                final_photo[i][j] = 1;
            else if (c == 'B')
                final_photo[i][j] = 2;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // check all cells=2
            if (final_photo[i][j] == 2)
            {
                int ni = i - b;
                int nj = j - a;

                if ((ni >= 0 && ni < n && nj >= 0 && nj < n && first_photo[ni][nj]) || (a == 0 && b == 0))
                {
                    first_photo[i][j] = 1;
                    must[i][j] = true;
                    must[ni][nj] = true;
                }
                else
                {
                    cout << -1 << endl;
                    return;
                }
            }

            // check all cells=1
            if (final_photo[i][j] == 1)
            {
                first_photo[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (first_photo[i][j] != 1)
                continue;

            int ni = i - b;
            int nj = j - a;

            if (!must[i][j] && ni >= 0 && ni < n && nj >= 0 && nj < n && first_photo[ni][nj] && (a || b))
            {
                first_photo[i][j] = 0;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            answer += first_photo[i][j];
        }
    }

    cout << answer << endl;
}

int32_t main()
{
    fastio;

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}