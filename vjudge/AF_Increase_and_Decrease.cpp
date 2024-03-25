#include <bits/stdc++.h>

#define fastio std::ios_base::sync_with_stdio(false); \
                std::ios_base::sync_with_stdio(false);

using ll = long long;
using pii = std::pair<int, int>;
using WGraph = std::vector<std::vector<pii>>;
using Graph = std::vector<std::vector<int>>;
using MinHeap = std::priority_queue<pii, std::vector<pii>, std::greater<pii>>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define REP(i, n) for(int i=0; i<n; i++)
#define REPQ(i, n) for(int i=0; i<=n; i++)
#define REQ(i, n) for(int i=1; i<=n; i++)
template <typename T>
T ckmax(T arg) {
    return arg;
}

// Recursive case to find the maximum value.
template <typename T, typename... Args>
T ckmax(T first, Args... rest) {
    T maxRest = ckmax(rest...); // Recursively find the maximum of the remaining arguments.
    return (first > maxRest) ? first : maxRest; // Compare the current argument with the maximum of the rest.
}

const int MXN = 1e5 + 5, INF = 1e9 + 5;

signed main()
{
    fastio;
    int n;
    std::cin>> n;
    ll sum = 0;
    REP(i, n) {
        int num;
        std::cin>> num;
        sum += num;
    }
    if(sum%n==0) {
        std::cout<< n;
    } else {
        std::cout<< n-1;
    }

    return 0;
}