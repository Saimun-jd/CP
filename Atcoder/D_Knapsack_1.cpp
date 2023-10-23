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
#define clr(vec, v) memset(vec, v, sizeof(vec))

const int MXN = 1e5 + 5, INF = 1e9 + 5;
int wi[105];
int vi[105];
const int N = 1e5+7;
ll dp[105][N];

ll knapsack(int idx, int amount) {
    // if we reach this end of the list
    if(idx<0) 
        return 0;
    if(dp[idx][amount] != -1) return dp[idx][amount];

    // don't take this item
    ll ans = knapsack(idx-1, amount);
    // take this item
    if(amount-wi[idx] >= 0) 
        ans = std::max(ans, knapsack(idx-1, amount-wi[idx]) + vi[idx]);
    
    return dp[idx][amount] = ans;

}

ll knpsk2(int idx, int amount) {
    for(int i = 1; i<=idx; i++) 
        for(int j = 1; j<=amount; j++)
            dp[i][j] = (wi[i-1] <= j) ? std::max(dp[i-1][j-wi[i-1]]+vi[i-1], dp[i-1][j]) : dp[i-1][j];

    return dp[idx][amount];
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    clr(dp, 0);

    int n, w;
    std::cin>> n>> w;
    for(int i=0; i<n; ++i) {
        std::cin>> wi[i] >> vi[i];
    }
    std::cout<< knpsk2(n, w);
    return 0;
}