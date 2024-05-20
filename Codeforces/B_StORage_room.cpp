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

void solve()
{

}

signed main()
{
    fastio;
    solve();
    int tc;
    std::vector<std::vector<ll>> vec(1003, std::vector<ll>(1003));
    std::cin>> tc;
    while(tc--) {
        int n;
        std::set<ll> ans;
        std::cin>> n;
        REP(i, n) {
            REP(j, n) {
                ll k;
                std::cin>> k;
                vec[i].push_back(k);
                if(i!=j) {
                    ans.insert()
                }
            }
        }
    }
    
    return 0;
}