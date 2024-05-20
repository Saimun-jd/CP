#include <bits/stdc++.h>

#define fastio std::ios_base::sync_with_stdio(false); \
                 std::cin.tie(nullptr);

using ll = long long;
using pii = std::pair<int, int>;
using vii = std::vector<pii>;
using WGraph = std::vector<std::vector<pii>>;
using Graph = std::vector<std::vector<int>>;
using MinHeap = std::priority_queue<pii, std::vector<pii>, std::greater<pii>>;

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
        int n, k;
        std::cin>> n>> k;
        std::vector<pii> vec;
        std::vector<int> xi;
        std::vector<int> ai;
        for(int i = 0; i<n; i++){ 
            int a;
            std::cin>> a;
            ai.push_back(a);
        }
        for(int i = 0; i<n; i++){ 
            int x;
            std::cin>> x;
            xi.push_back(std::abs(x));
        }
        REP(i, n) {
            vec.push_back({xi[i], ai[i]});
        }
        std::sort(all(vec));
        int possible = 1;
        for(int i = 0; i<n-1; i++){

            int cost = (vec[i].second - vec[i].first) + (vec[i+1].second - vec[i+1].first) + 2;
            if (cost <= k)
            {
                
            }
            else{
                possible = 0;
                break;
            }
        }
        if(possible) std::cout<< "YES"<< std::endl;
        else std::cout<< "NO"<< std::endl;
    }
}

signed main()
{
    fastio
    solve();
    
    return 0;
}