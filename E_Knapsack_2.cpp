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

const ll INF = 1e9 + 5;
int vi[105];
int wi[105];
int N, W;
const int maxv = 1e5;
int totalvalue = 0;
ll dp[105][maxv];
// Top Down Approach
ll knpsk(int idx, int value_left ) {
    if(value_left == 0) return 0;
    if(idx < 0) return LONG_MAX;
    if(dp[idx][value_left] != -1) return dp[idx][value_left];

    ll amount = knpsk(idx-1, value_left);

    if(value_left - vi[idx] >= 0) 
        amount = std::min(amount, knpsk(idx-1, value_left-vi[idx]) + wi[idx]);
    return dp[idx][value_left] = amount;
}
// Bottom Up Approach
ll knpsk2() {
    REQ(i, maxv) dp[0][i] = LONG_MAX;
    dp[0][0] = 0;
    int ans = 0;
    for(int i = 1; i<=N; i++) { 
        for(int j=0; j<=totalvalue; j++) {
            if(j>=vi[i-1])
                dp[i][j] = std::min(dp[i-1][j], dp[i-1][j-vi[i-1]]+wi[i-1]);
            else
                dp[i][j] = dp[i-1][j];
            
            if(dp[i][j]<=W) ans = std::max(ans, j);
        }
    }
    return ans;
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin>> N>> W;
    REP(i, N) {
        std::cin>> wi[i]>> vi[i];
        totalvalue += vi[i];
    }
    // for(int i=max_val; i>=0; i--){
    //     if(knpsk(N-1, i) <= W){
    //         std::cout<< i << std::endl;
    //         break;
    //     }
    // }
    std::cout<< knpsk2();
    return 0;
}