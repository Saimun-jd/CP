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

const int MXN = 1e5 + 5, INF = 1e9 + 5;
const int N = 1e3;
//int dp[N][N];


void floyed_warshell(int n, std::vector<std::vector<int>>& dp) {
    REQ(k, n) {
        REQ(i, n) {
            REQ(j, n) {
                dp[i][j] = std::min(dp[i][j] ,dp[i][k] + dp[k][j]);
            }
        }
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::vector<int>> dp(N, std::vector<int>(N, 0));
    int n, m; // Number of vertices and edges
    std::cin >> n >> m;

    REP(i, N) {
        REP(j, N) {
            if(i == j) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = INF;
        }
    }

    // Read the edges and their weights
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        std::cin >> u >> v >> weight;
        dp[u][v] = weight;
    }
    floyed_warshell(n, dp);
    REQ(i, n) {
            REQ(j, n) {
                if(dp[i][j] != INF)
                    std::cout<< dp[i][j] <<" ";
                else std::cout<< "INF"<< " ";
            }
            std::cout<<std::endl;
        }
    return 0;
}