#include <bits/stdc++.h>

#define fastio std::ios_base::sync_with_stdio(false); \
                std::ios_base::sync_with_stdio(false);

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
const int MXN = 1e6+1, INF = 1e9 + 5;
int arr[MXN];
signed main()
{
    fastio;
    int N;
    std::cin>> N;
    int ans = 0;
    REQ(i, N){
        int ID;
        std::cin>> arr[i];
    }
    REQ(i, N) {
        if(arr[i] != 0){
            arr[arr[i]] = 0;
        }
    }
    REQ(i, N) {
        if(arr[i] != 0) ans++;
    }
    std::cout<< ans<< std::endl;
    REQ(i, N) {
        if(arr[i] != 0) std::cout<< i << " "; 
    }
    return 0;
}