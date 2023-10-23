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
#define clr(v, val) memset(v, val, sizeof(v))

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
int dp[210][25];
int prices[25][25];
int M, C;

int shopping(int money, int g) {
    // base case
    if(money < 0) return -1000000000;
    if(g == C) return (M-money);
    
    //dp case
    if(dp[money][g] != -1) return dp[money][g];

    // logic
    // choose every gament item and try for every prices
    int ans = -1;
    for(int i=1; i<=prices[g][0]; i++) {
        ans = std::max(ans, shopping(money-prices[g][i], g+1));
    }
    return dp[money][g] = ans;
}

signed main()
{
    fastio;
    int TC;
    std::cin>> TC;
    while(TC--) {
        std::cin>> M>> C;
        clr(dp, -1);
        REP(i, C) {
            std::cin>>prices[i][0];
            for(int j=1; j<=prices[i][0]; j++) 
                std::cin>> prices[i][j];
        }
        int ans = shopping(M, 0);
        if(ans > 0) std::cout<< ans<< std::endl;
        else std::cout<< "no solution" << std::endl;
    }
    return 0;
}