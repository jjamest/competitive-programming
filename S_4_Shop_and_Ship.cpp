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
/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */

vector<int> dijkstra(int n, int start, vector<vector<pair<int, int>>> &graph)
{
    vector<int> distances(n + 1, INT_INF);
    distances[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [current_distance, current_vertex] = pq.top();
        pq.pop();

        if (current_distance > distances[current_vertex])
            continue;

        for (auto [neighbor, weight] : graph[current_vertex])
        {
            int new_distance = current_distance + weight;
            if (new_distance < distances[neighbor])
            {
                distances[neighbor] = new_distance;
                pq.push({new_distance, neighbor});
            }
        }
    }

    return distances;
}

int main()
{
    fastio;

    int n, t;
    cin >> n >> t;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < t; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;

        adj[x].push_back({y, c});
        adj[y].push_back({x, c});
    }

    int k;
    cin >> k;
    vector<pair<int, int>> pencils(k);
    for (int i = 0; i < k; i++)
    {
        int z, p;
        cin >> z >> p;
        pencils[i] = {z, p};
    }
    int d;
    cin >> d;

    vector<int> dists = dijkstra(n, d, adj);

    int answer = INT_INF;
    for (pair<int, int> p : pencils)
    {
        answer = min(answer, p.second + dists[p.first]);
    }

    cout << answer << endl;

    return 0;
}