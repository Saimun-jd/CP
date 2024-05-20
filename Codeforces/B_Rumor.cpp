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
const int N = 1e5+5;
WGraph graph(N);
std::vector<int> dis;

// Function to find the minimum spanning tree using Prim's algorithm
ll prims(int s) {
    int n = graph.size();
    std::vector<bool> visited(n, false);
    dis.assign(n+1, INF);
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;

    // Start from the specified vertex
    pq.push(std::make_pair(0, s));
    ll cost = 0;
    dis[s] = 0;
    while (!pq.empty()) {
        auto currentEdge = pq.top();
        pq.pop();
        int u = currentEdge.second;
        int w = currentEdge.first;

        // If the vertex has already been visited, skip it
        if (visited[u]) {
            continue;
        }

        // Mark the current vertex as visited
        visited[u] = true;

        // Add the current edge cost to the minimum spanning tree
        cost += w;

        // Explore all adjacent vertices
        for (auto neighbor : graph[u]) {
            int v = neighbor.second;
            int weight = neighbor.first;
            if(visited[v]) continue;
            if (weight < dis[v]) {
                dis[v] = weight;
                pq.push(std::make_pair(weight, v));
            }
        }
    }

    return cost;
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin>> n>> m;
    std::vector<ll> ci;
    REP(i, n) {
        ll c;
        std::cin>> c;
        ci.push_back(c);
    }
    REP(i, n) {
        graph[0].push_back({ci[i], i+1});
        graph[i+1].push_back({ci[i], 0});
    }
    REP(i, m) {
        ll x, y;
        std::cin>> x>> y;
        graph[x].push_back({0, y});
        graph[y].push_back({0, x});
    }
    std::cout<< prims(0);
    return 0;
}