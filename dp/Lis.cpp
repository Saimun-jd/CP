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
std::vector<int> dp(N, 1);
std::vector<int> list(N);

int lis(int n) {
    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(list[i] > list[j]) {
                dp[i] = std::max(dp[i], 1+dp[j]);
            }
        }
    }
    for(auto val: dp) {
        ans = std::max(ans, val);
    }
    return ans;
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; 
    std::cin>> n;
    for(int i=0; i<n; i++) {
        std::cin>> list[i];
    }
    std::cout<< lis(n);
    return 0;
}