#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
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

int n;
ld p;
ld prob_hp = 1.0;
void solve()
{
    while(n > 0) {
        if(n%2) {
            prob_hp = prob_hp*(1-p) + (1-prob_hp) * p;
        }
        p = (1-p) * p + (1-p) *p;
        n /= 2;
    }
}

signed main()
{
    fastio;
    solve();
    std::cin>> n>> p;
    solve();
    std::cout<< std::fixed<< std::setprecision(10) << prob_hp;
    return 0;
}