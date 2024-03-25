#include <bits/stdc++.h>

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

const int MXN = 1e3 + 5, INF = 1e9 + 5;
const int N = 4;
const int VIS_ALL = ((1<<N) - 1);
int dp[10][10] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42,30, 0, 10},
    {25, 34, 10, 0}
};

int tsp(int mask, int at) {
    if(mask == VIS_ALL) return dp[at][0];

    int cost = INF;

    REP(city, N) {
        if(!(mask & (1<<city))) {
            int newCost = dp[at][city] + tsp((mask | (1<<city)), city);
            cost = std::min(cost, newCost);
        }
    }
    return cost;
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cout<< tsp(1, 0);
    return 0;
}