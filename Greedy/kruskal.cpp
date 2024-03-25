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
const int N = 100;
struct Edge
{
    int u, v, w;
    Edge() {}
    Edge(int _u, int _v, int _w)
        : u(_u), v(_v), w(_w) {}
    bool operator<(Edge const& other) {
        return w < other.w;
    }
};

std::vector<Edge> graph;

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

int kruskal() {
    std::sort(graph.begin(), graph.end());
    int n = graph.size();
    int ans = 0;
    auto dsu = DSU(n+1);
    for(auto edge: graph) {
        if(!dsu.same_set(edge.u, edge.v)) {
            dsu.Union(edge.u, edge.v);
            ans += edge.w;
            std::cout<< edge.u << " --> " << edge.v << std::endl;
        }
    }
    return ans;
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m; // Number of vertices and edges
    std::cin >> n >> m;

    // Read the edges and their weights
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph.push_back({u, v, w});
    }
    std::cout<< "MST: "<< kruskal();
    return 0;
}