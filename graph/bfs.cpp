#include <bits/stdc++.h>

using ll = long long;
using pii = std::pair<int, int>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define REP(i, n) for(int i=0; i<n; i++)
#define REPQ(i, n) for(int i=0; i<=n; i++)

const int MXN = 1e5 + 5, INF = 1e9 + 5;
const int N = 1e3 + 10;
std::vector<int> graph[N];

void solve()
{

}
int visited[N];
int levels[N];

void reset() {
    REP(i, N) {
        levels[i] = INF;
    }
}

// O(V + E)
void bfs(int source) {
    std::queue<int> Q;
    Q.push(source);
    visited[source] = 1;
    while(!Q.empty()) {
        auto curr = Q.front();
        Q.pop();
        for(auto child : graph[curr]) {
            if(!visited[child]) {
                Q.push(child);
                visited[child] = 1;
                levels[child] = levels[curr] + 1;
            }
        }
    }
}

int shortest_path(int src, int dest) {
    bfs(src);
    return abs(levels[dest] - levels[src]);
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    reset();

    int n, e;
    std::cin>>n>>e;
    REP(i, e){
        int a, b, w;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    std::cout<< "shortest path form "<< 1 << " -> " << 5 << " is : "<< shortest_path(1, 5);
    return 0;
}