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

struct Edge
{
    int u, v;
    ll w;
    Edge() {}
    Edge(int _w, int _u, ll _v)
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
        parent.resize(n+1);
        sz.resize(n+1, 0);
        for(int i=0; i<=n; i++) {
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

void kruskal() {
    int n = graph.size();
    ll ans = 0;
    auto dsu = DSU(n);
    std::vector<int> power_station;
    std::vector<pii> connections;
    for(auto edge: graph) {
        if(!dsu.same_set(edge.u, edge.v)) {
            dsu.Union(edge.u, edge.v);
            ans += edge.w;
            if(edge.u == 0 || edge.v == 0) {
                power_station.push_back(std::max(edge.u, edge.v));
            } else {
                connections.push_back({edge.u, edge.v});
            }
        }
    }
    std::cout<< ans<< std::endl;
    std::cout<< power_station.size()<< std::endl;
    for(int p: power_station) {
        std::cout<< p<< " ";
    }
    std::cout<< std::endl;
    std::cout<< connections.size() << std::endl;
    for(auto &city: connections) {
        std::cout<< city.first << " " << city.second << std::endl;
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin>> n;

    std::vector<pii> cities(n+1);
    //std::vector<std::pair<int, pii>> graph;
    for(int i=1; i<=n; i++){
        std::cin>> cities[i].first >> cities[i].second;
    }
    std::vector<int> ci(n+1);
    for(int i=1; i<=n; i++) {
        std::cin>> ci[i];
    }
    std::vector<int> ki(n+1);
    for(int i=1; i<=n; i++) {
        std::cin>> ki[i];
    }
    for(int i=1; i<=n; i++) {
        graph.push_back({ci[i], 0, i});
    }
    for(int i=1; i<=n; i++) {
        for (int j = i+1; j <= n; j++) {
            int perkm = ki[i] + ki[j];
            int dist = std::abs(cities[i].first - cities[j].first) + std::abs(cities[i].second - cities[j].second);
            ll wt = perkm * 1LL * dist;
            Edge edge;
            edge.w = wt;
            edge.u = i;
            edge.v = j;
            graph.push_back(edge);
        }
    }
    std::sort(graph.begin(), graph.end());
    kruskal();

    return 0;
}