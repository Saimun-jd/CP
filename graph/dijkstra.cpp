#include <bits/stdc++.h>

using ll = long long;
using pii = std::pair<int, int>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define REP(i, n) for(int i=0; i<n; i++)
#define REPQ(i, n) for(int i=0; i<=n; i++)

const int MXN = 1e5 + 5, INF = 1e9 + 5;

struct Node{
    int at, cost;
    Node(int _at, int _cost)
    :at(_at), cost(_cost) {}
    bool operator<( const Node& a) { return cost > a.cost; }
};


std::vector<std::vector<pii>> graph;
std::vector<int> dis;

void dijkstra(int s) {
    int n = graph.size();
    dis.assign(n, INF);
    std::vector<bool> visited(n, false);
    dis[s] = 0;
    for(int i=0; i<n; i++) {
        int vert = -1;
        for(int j=0; j<n; j++) {
            if(!visited[j] && (vert == -1 || dis[j] < dis[vert]))
                vert = j;
        }

        // Disconnected Node
        if(dis[vert] == INF) break;

        visited[vert] = true;
        for(auto edge: graph[vert]) {
            int child = edge.first;
            int wt = edge.second;
            if(dis[vert]+wt < dis[child]) dis[child] = dis[vert] + wt;
        }
    }
}

void solve()
{
    
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, e;
    std::cin>> n>> e;
    REP(i, e){
        int n1, n2, wt;
        std::cin>> n1>> n2>> wt;
        graph[n1].push_back({n2, wt});
        graph[n2].push_back({n1, wt});
    }
    return 0;
}