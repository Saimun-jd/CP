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
#define REQ(i, n) for(int i=1; i<=n; i++)

const int MXN = 1e5 + 5, INF = 1e9 + 5;
const ll mod = 998244353;

void solve() {
    std::string s;
    ll total = 0;
    ll ways = 1;
    std::cin>> s;
    int n = s.size();

    ll fact[n+1];
    fact[0] = 1;
    REQ(i, n) fact[i] = (i * fact[i-1]) % mod;

    for(int i=0; i<n; ) {
        int j = i;
        for( ; j<n; j++) {
            if(s[i] != s[j]) break;
        }
        total += (j - i - 1);
        ways = (ways * (j-i)) % mod;
        i = j;
    }
    ways = ways*fact[total] % mod;
    std::cout<< total << " " << ways << std::endl;
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int TC;
    std::cin>>TC;
    while (TC--)
    {
        solve();
    }
    return 0;
}