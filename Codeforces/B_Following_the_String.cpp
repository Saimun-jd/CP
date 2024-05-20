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

const int MXN = 1e5, INF = 1e9 + 5;
const int N = 100;

void solve() {
    
}

signed main()
{
    fastio
    int tc;
    std::cin>> tc;
    while(tc--) {
        int n;
        std::cin>> n;
        std::vector<int> vc(n);
        std::vector<int> trc(26, 0);
        std::string ss = "";
        char ch = 'a';
        REP(i, n) {
            int k;
            std::cin>> k;
            vc.push_back(k);
        }
        REP(i, n) {
            
        }
        std::cout<< ss << std::endl;
    }
    
    return 0;
}