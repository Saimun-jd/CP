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

ll remove_upto_ith_bit(ll num, ll bit) {
    ll ans = num;
    for(ll i = 60; i > bit; i--) {
        if(ans & (1LL << i)) ans = ans ^ (1LL << i);
        // ans = ans & ~(1LL << i);
    }
    return ans;
}

ll  n, q;

void solve()
{
    std::cin>> n>> q;
    std::vector<ll> x(n);
    for(auto &elem: x) std::cin>> elem;
    while (q--)
    {
        ll k;
        std::cin>> k;
        std::vector<ll> y = x;
        for(ll bit = 60; bit>=0; bit--) {
            ll req_sum = 0;
            ll mask = (1LL << bit);
            for(auto &elem: y) {
                if(elem & mask) continue;
                ll addr = mask - remove_upto_ith_bit(elem, bit);
                req_sum += addr;
                if(req_sum > k) break;
            }
        
            if(req_sum <= k) { // now set the bit in original array
                for(auto &elem: y) {
                    if(elem & mask) continue;
                    ll addr = mask - remove_upto_ith_bit(elem, bit);
                    elem += addr;
                }
                k -= req_sum;
            }
        }
        ll ans = y[0];
        for(auto &elem: y) ans = ans & elem;
        std::cout<< ans << std::endl;
    }
    
}

signed main()
{
    fastio;
    solve();
    
    return 0;
}