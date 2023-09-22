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
const int N = 1e5+1;
int arr[N][3];
int dp[N][3];
int n;

int maxHapiIter(int n) {
    int ans = INT_MIN;
    for(int i=1; i<n; i++) {
        dp[i][0] = arr[i][0] + std::max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = arr[i][1] + std::max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = arr[i][2] + std::max(dp[i-1][0], dp[i-1][1]);
    }
    return std::max(dp[n-1][0], std::max(dp[n-1][1], dp[n-1][2]));
}

ll maxHapiRecur(int day, int prevIdx) {
    if(day == n) return 0;
    if(dp[day][prevIdx] != -1) return dp[day][prevIdx];
    ll ans = LONG_MIN;
    if(prevIdx == 0) {
        ans = std::max(ans, arr[day][1] + maxHapiRecur(day+1, 1));
        ans = std::max(ans, arr[day][2] + maxHapiRecur(day+1, 2));                                                                            
    } else if(prevIdx == 1) {
        ans = std::max(ans, arr[day][0] + maxHapiRecur(day+1, 0));
        ans = std::max(ans, arr[day][2] + maxHapiRecur(day+1, 2));        
    } else if(prevIdx == 2) {
        ans = std::max(ans, arr[day][0] + maxHapiRecur(day+1, 0));
        ans = std::max(ans, arr[day][1] + maxHapiRecur(day+1, 1));        
    } else { //3
        ans = std::max(ans, arr[day][0] + maxHapiRecur(day+1, 0));
        ans = std::max(ans, arr[day][1] + maxHapiRecur(day+1, 1));     
        ans = std::max(ans, arr[day][2] + maxHapiRecur(day+1, 2));
    }
    return dp[day][prevIdx] = ans;
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));

    std::cin>> n;
    REP(i, n) {
        std::cin>> arr[i][0]>> arr[i][1]>> arr[i][2];
    }
    //dp[0][0] = arr[0][0];
    //dp[0][1] = arr[0][1];
    ///dp[0][2] = arr[0][2];
    std::cout<< maxHapiRecur(0, 3); //3 means we didn't select either a or b or c
    // int ans = maxHapiIter(n);

    return 0;
}