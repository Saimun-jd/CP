#include <bits/stdc++.h>

#define inout() std::ios_base::sync_with_stdio(false); \
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

const int MXN = 1e5 + 5, INF = 1e9 + 5;
const double eps = 1e-6; // accuracy uptill 5 decimal points

double sqrt(int n) {
    double hi = n;
    double lo = 1;
    double mid;
    while (hi-lo > eps) {
        mid = (hi+lo)/2;
        if(mid*mid < n) lo = mid;
        else hi = mid;
    }
    return lo;
}

signed main()
{
    inout();
    std::cin.tie(nullptr);
    int n;
    std::cin>> n;

    std::cout <<sqrt(n);
    return 0;
}