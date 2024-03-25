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
const ll maxn = 1e5;

std::vector<ll> primes, hp(maxn), lp(maxn, 0);
bool isprime[maxn];
std::map<ll, int> prime_factors;

// void factorall2() {
//     for(int i = 2; i<= maxn; i+= 2){
//         isprime[i] = 0;
//         lp[i] = 2;
//     }
// }
void sieve() {
    memset(isprime, 1, sizeof(isprime));
    isprime[2] = 1;
    //factorall2();
    for(int i = 2; i*i <= maxn-1; i++) {
        if(isprime[i]) {
            lp[i] = hp[i] = i;
            for(int j = i*i; j<= maxn-1; j+=i) {
                isprime[j] = 0;
                hp[j] = i;
                if(!lp[j]) lp[j] = i;
            }
        }
    }
    primes.push_back(2);
    for(int i = 3; i<= maxn; i++) {
        if(isprime[i]) primes.push_back(i);
    }

}

void prime_factor(ll num) {
    prime_factors.clear();
    while (num > 1) {
        auto prime_fact = hp[num];
        while (num % prime_fact == 0) {
            num /= prime_fact;
            prime_factors[prime_fact]++;
        }
    }
}

// Number of Divisors
ll NOD(ll num) {
    prime_factor(num);
    ll ans = 1;
    for(auto [key, val]: prime_factors) {
        ans *= (val + 1);
    }
    return ans;
}
// Sum od Divisors
ll SOD(ll num) {
    prime_factor(num);
    ll ans = 1;
    for(auto [key, val]: prime_factors) {
        ans *= (pow(key, val+1) -1)/(key-1);
    }
    return ans;
}

signed main()
{
    fastio;
    sieve();
    std::cout<< SOD(12);
    
    return 0;
}