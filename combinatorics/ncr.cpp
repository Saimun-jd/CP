#include <bits/stdc++.h>

using ll = long long;
using pii = std::pair<int, int>;
using WGraph = std::vector<std::vector<pii>>;
using Graph = std::vector<std::vector<int>>;
using MinHeap = std::priority_queue<pii, std::vector<pii>, std::greater<pii>>;

#define fastio std::ios_base::sync_with_stdio(false); \
                 std::cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define REP(i, n) for(int i=0; i<n; i++)
#define REPQ(i, n) for(int i=0; i<=n; i++)
#define REQ(i, n) for(int i=1; i<=n; i++)

const ll INF = 1e9 + 5;

ll dp[10000][10000];

void ncr(int n, int r) {
    REQ(i, n){
        REPQ(j, r) {
            if(j>i) dp[i][j] = 0;
            else if(j == 0 || i == j) dp[i][j] = 1; // ncn = nc0 = 1
            else dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
}

void solve(int n, int r)
{
    memset(dp, 0, sizeof(dp));
    ncr(n, r);
}

signed main()
{
    fastio;
    int n, r;
    std::cin>> n>> r;
    solve(n, r);
    std::cout<< dp[n][r];
    return 0;
}