#include <bits/stdc++.h>

#define fastio std::ios_base::sync_with_stdio(false); \
                std::ios_base::sync_with_stdio(false);
#pragma region 
using ll = long long;
using pii = std::pair<int, int>;
using WGraph = std::vector<std::vector<pii>>;
using Graph = std::vector<std::vector<int>>;
using MinHeap = std::priority_queue<pii, std::vector<pii>, std::greater<pii>>;
#pragma endregion

#pragma region shortcuts
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define REP(i, n) for(int i=0; i<n; i++)
#define REPQ(i, n) for(int i=0; i<=n; i++)
#define REQ(i, n) for(int i=1; i<=n; i++)
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
#pragma endregion

const int MXN = 1e5 + 5, INF = 1e9 + 5;
const int K = 25;
int logn[MXN+1];
int st[K][MXN];
void Calc_logN() {
    logn[1] = 0;
    for(int j=2; j<=MXN; j++) {
        logn[j] = logn[j/2] + 1;
    }
}

void sparse_table(std::vector<int>& vec) {
    int k = logn[sz(vec)];
    std::copy(all(vec), st[0]);
    for(int i=1; i<=k; i++) {
        for(int j=0; j+(1<<i) <= sz(vec); j++) {
            st[i][j] = std::min(st[i-1][j], st[i-1][j+(1<<(i-1))]);
        }
    }
}

int query(int l, int r) {
    int j = logn[r-l+1];
    return std::min(st[j][l], st[j][r-(1<<j)+1]);
}

signed main()
{
    fastio;
    Calc_logN();
    int N;
    std::cin>> N;
    std::vector<int> vec;
    while(N--) {
        int num;
        std::cin>> num;
        vec.push_back(num);
    }
    int Q;
    std::cin>> Q;
    sparse_table(vec);
    while(Q--) {
        int l, r;
        std::cin>> l>> r;
        std::cout<< query(l, r) << std::endl;
    }
    return 0;
}