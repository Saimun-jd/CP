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

ll factmod(ll n, ll p) {
    std::vector<ll> fact(p);
    fact[0] = 1;
    for(ll i = 1; i<p; i++) {
        fact[i] = i * fact[i-1] % p;
    }
    ll result = 1;
    while(n) {
        if((n%p)%2) result = p - result;
        result = result * fact[n%p] % p;
        n /= p;
    }
}

void solve()
{

}

signed main()
{
    fastio;
    solve();
    
    return 0;
}