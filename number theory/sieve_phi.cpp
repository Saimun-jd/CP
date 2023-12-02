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

ll phi(ll n) {
    ll result = n;
    for(int i = 2; i<=n; i++) {
        if(n%i == 0){
            while (n%i == 0) {
                n /= i;
            }
            result -= result/i; // phi = n(1-1/p1)(1-1/p2)...
        }
    }
    if(n>1) {
        result -= result/n;
    }
    return result;
}

void sieve_phi(ll n) {
    std::vector<ll> phi(n+1);
    REPQ(i, n) phi[i] = i;
    for(int i = 2; i<=n; i++) {
        if(phi[i] == i) {
            for(int j = i; j<=n; j+=i) {
                phi[j] -= phi[j]/i;
            }
        }
    }
}

//sieve using sum of divisors method => phi(n) = n - sum(phi(d)) // d -> all divisors of n

void sieve_phi2(ll n) {
    std::vector<ll> phi(n+1);
    phi[0] = 0;
    phi[1] = 1;
    for(int i = 2; i<=n; i++) 
        phi[i] = n-1; // n-1 because 1 is every numbers divisor and phi(1) = 1
    
    for(int i = 2; i<=n; i++) {
        for(int j = 2*i; j<=n; j+=i) {
            phi[j] -= phi[i]; // subbing all the multiple of i
        }
    }
}

signed main()
{
    fastio;
    solve();
    std::cout<< "phi(12) = "<< phi(12);
    return 0;
}