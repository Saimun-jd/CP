#include <bits/stdc++.h>

#define fastio std::ios_base::sync_with_stdio(false); \
                 std::cin.tie(nullptr);

using ll = long long;
using pii = std::pair<int, int>;
using vii = std::vector<pii>;
using WGraph = std::vector<std::vector<pii>>;
using Graph = std::vector<std::vector<int>>;
using MinHeap = std::priority_queue<pii, std::vector<pii>, std::greater<pii>>;
using ump = std::unordered_map<int, int>;
using vi = std::vector<int>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define REP(i, n) for(int i=0; i<n; i++)
#define REPQ(i, n) for(int i=0; i<=n; i++)
#define REQ(i, n) for(int i=1; i<=n; i++)

const int MXN = 1e5 + 5, INF = 1e9 + 5;
const int N = 100;

void solve() {
    int tc;
    std::cin>> tc;
    while(tc--) {
        vi vec(MXN);
        int n;
        ump mp;
        std::cin>> n;
        REP(i, n){
            std::cin>> vec[i];
            mp[vec[i]] = 1;
        }
        int mex = 0;
        for(int i = 0; i<=MXN; i++) {
            if(mp[i] == 0){ mex = i; break;}
        }
        if(mex == 0) {
            std::cout<< 2 << std::endl;
            std::cout<< 1 << " " << 1 << std::endl;
            std::cout<< 2 << " " << n << std::endl;
        }
        int fi = 1;
        std::vector<pii> vpi;
        REP(i, n){
            if(vec[i] == vec[i+1]) {vpi.push_back({fi, fi}); fi += 1;}
            else if(vec[i] > mex) {
                vpi.push_back({fi, i});
                fi = i+1;
            }
        }
        if(vpi.size()<2) std::cout<< -1 << std::endl;
        else {
            vpi[sz(vpi)-1].second = n;
            std::cout<< sz(vpi) << std::endl;
            for(auto it: vpi) {
                std::cout<< it.first << " " << it.second << std::endl;
            }
        }
    }
        
}

signed main()
{
    fastio
    solve();
    
    return 0;
}