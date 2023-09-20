#include <bits/stdc++.h>

using ll = long long;
using pii = std::pair<int, int>;
using WGraph = std::vector<std::vector<pii>>;
using Graph = std::vector<std::vector<int>>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define REP(i, n) for(int i=0; i<n; i++)
#define REPQ(i, n) for(int i=0; i<=n; i++)

const int MXN = 1e5 + 5, INF = 1e9 + 5;
const int N = 1e7+5;

class DSU {
private:
    std::vector<int> parent;
    std::vector<int> sz;
    int find(int a) {
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
public:
    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 0);
        for(int i=0; i<n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    void Union(int a, int b) {
        int c = find(a);
        int d = find(b);
        if(c != d) {
            if(sz[c] < sz[d]) std::swap(c, d); //connect smaller tree benith bigger tree
            parent[c] = d;
            sz[c] += sz[d];
        }
    }
    bool same_set(int a, int b) {
        return find(a) == find(b);
    }
};

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto dsu = DSU(4);
    dsu.Union(0, 1);
    dsu.Union(2, 3);
    dsu.Union(3, 1);

    if(dsu.same_set(2, 3)) {
        std::cout<< "same set";
    } else {
        std::cout<< "not same set";
    }

    return 0;
}