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

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int TC;
    std::cin>> TC;
    while (TC--)
    {
        int n;
        std::cin>> n;
        int minX = 0, minY = 0, maxX = 0, maxY = 0;
        REP(i, n) {
            int x, y;
            std::cin>> x>> y;
            minX = std::min(minX, x);
            minY = std::min(minY, y);
            maxX = std::max(maxX, x);
            maxY = std::max(maxY, y);
        }
        std::cout<< 2 * (maxX + maxY - minX - minY) << std::endl;
    }
    
    return 0;
}