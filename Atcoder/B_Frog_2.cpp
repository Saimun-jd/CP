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

const int MXN = 1e5 + 5, INF = 1e9 + 5;
const int N = 1e5;
int hi[N+1];
ll dp[N+1];

ll frog(int n, int k) {
    dp[1] = std::abs(hi[1]-hi[0]); 
    for(int i = 2; i<n; i++) {
        ll cost = LONG_MAX;
        for(int j=1; j<=k; j++) {
            if(i-j >= 0) {
                cost = std::min(cost, std::abs(hi[i]-hi[i-j])+dp[i-j]);
            }
        }
        dp[i] = cost;
    }
    return dp[n-1];
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    memset(dp, 0, sizeof(dp));

    int n, k;
    std::cin>> n>> k;
    for(int i=0; i<n; i++) {
        std::cin>> hi[i];
    }
    std::cout<< frog(n, k);
    return 0;
}