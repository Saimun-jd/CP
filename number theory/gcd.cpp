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
ll gcd(ll a, ll b) {
    if(b>a) std::swap(a, b);
    if(a==0) return b;
    if(b==0) return a;
    return gcd(b, a%b); 
}

ll lcm(ll a, ll b) {
    return a*b/gcd(a, b);
}

signed main()
{
    fastio;
    ll a, b;
    std::cin>> a>> b;
    std::cout<< gcd(a, b);
    return 0;
}