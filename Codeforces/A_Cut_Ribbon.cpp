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
const int N = 4001;
std::vector<int> dp(N, -1);
int a, b, c;

int ribbon(int n) {
    if(n==0) return 0;
    if(dp[n] != -1) return dp[n];
    int ans = INT_MIN;
    if(n-a >= 0 ) ans = std::max(ans ,1 + ribbon(n-a));
    if(n-b >= 0 ) ans = std::max(ans ,1 + ribbon(n-b));
    if(n-c >= 0 ) ans = std::max(ans ,1 + ribbon(n-c));
    return dp[n] = ans;
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin>> n>> a>> b>> c;
    std::cout<< ribbon(n);

    return 0;
}