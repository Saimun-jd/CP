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

const int MXN = 1e5 + 5, INF = 1e9 + 5;
int dp[3005][3005];

std::string ans, t, s;

int lcs(int n, int m) {
    if(n<0 || m<0) return 0;
    int& ret = dp[n][m];
    if(ret != -1) return ret;
    if(t[n] == s[m]) return ret = 1 + lcs(n-1, m-1);
    return ret = std::max(lcs(n-1, m), lcs(n, m-1));
}

int lcsbtm(int n, int m) {
    
}

std::string gensol(int n, int m) {
    if(n<0 || m<0) return "";
    if(t[n] == s[m]) return gensol(n-1, m-1) + t[n];
    if(lcs(n-1, m) == lcs(n, m)) return gensol(n-1, m);
    else return gensol(n, m-1);
}

signed main()
{
    fastio;
    memset(dp, -1, sizeof(dp));
    std::cin>> t>> s;
    int n = t.size();
    int m = s.size();

    // auto DFS = [&](int i, int j, auto&& DFS) -> int {
    //     if(i < 0 || j < 0) return 0;
    //     int& ret = dp[i][j];
    //     if(ret != -1) return ret;
    //     if(t[i] == s[j]) return ret = DFS(i-1, j-1, DFS) + 1;
    //     return ret = std::max(DFS(i-1, j, DFS), DFS(i, j-1, DFS));
    // };

    // auto Generate_Sol = [&](int i, int j, auto&& Generate_Sol) -> std::string {
    //     if(i<0 || j<0) return "";
    //     if(t[i] == s[j]) return Generate_Sol(i-1, j-1, Generate_Sol) + t[i];
    //     if(DFS(i-1, j, DFS) > DFS(i, j-1, DFS)) return Generate_Sol(i-1, j, Generate_Sol);
    //     else return Generate_Sol(i, j-1, Generate_Sol);
    // };
    std::cout<< gensol(n-1, m-1);
    return 0;
}