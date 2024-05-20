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

int findGrp(std::string str, int& i) {
    
}
void solve() {
    int tc;
    std::cin>> tc;
    while(tc--) {
        int n;
        std::cin>> n;
        int arr[100];
        for(int i = 0; i<n; i++) std::cin>> arr[i];
        int low = 0;
        while(arr[low] != 1) {
            low++;
        }
        int hi = n-1;
        while(arr[hi] != 1) hi--;
        int k = 0;
        for(int i = low; i<hi; i++) {
            if(arr[i] == 0) k++;
        }
        std::cout<< k << std::endl;
    }
}

signed main()
{
    fastio
    solve();
    
    return 0;
}