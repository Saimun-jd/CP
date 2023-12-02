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

pii egcd(int a, int b) {
    if(b==0) {
        return {1, 1};
    }
    auto [x2, y2] = egcd(b, a%b);
    int x = y2, y = x2 - (a/b)*y2;
    return {x, y};
}

void solve()
{

}

signed main()
{
    fastio;
    solve();
    int a, b;
    std::cin>> a>> b;
    auto [x, y] = egcd(a, b);
    std::cout<< x << " " << y;
    
    return 0;
}