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

const int MXN = 1e5 + 5, INF = 1e9 + 5;
const int N = 1e9+5;
#define MN LONG_MIN
#define MX LONG_MAX
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin>> T;
    while(T--) {
        int n, w, h;
        std::cin>> n>> w>> h;
        std::vector<int> ai;
        std::vector<int> bi;
        REP(i, n){
            int a;
            std::cin>> a;
            ai.push_back(a);
        }
        REP(i, n){
            int b;
            std::cin>> b;
            bi.push_back(b);
        }
        bool isPossible = false;
        ll mn = MN, mx = MX;
        REP(i, n) {
            ll lc = ai[i] - w;
            ll hc = ai[i] + w;
            ll ld = bi[i] - h;
            ll hd = bi[i] + h;
            mn = std::max(mn, (hd-hc)); // max left
            mx = std::min(mx, (ld-lc)); // max right
        }
        // max(bi+h−w−ai) ≤ p ≤ min(bi−h+w−ai)
        
        if(mn<=mx) std::cout<< "YES"<<std::endl;
        else std::cout<< "NO" << std::endl;
    }
    return 0;
}