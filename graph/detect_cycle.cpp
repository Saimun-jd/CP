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
const int N = 1e8 + 7;
std::vector<int> graph[N];
std::vector<bool> visited(N, false);

bool dfs(int s, int parent) {
    visited[s] = true;
    bool isCycle = false;
    for(auto child : graph[s]) {
        if(visited[child] && parent == child) continue;
        if(visited[child]) return true;
        isCycle |= dfs(child, s);
    }
    return isCycle;
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);


    int n, e;
    std::cin>>n>>e;
    REP(i, e){
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bool cycle = false;
    for(int i=1; i<=n; i++) {
        if(visited[i]) continue;
        cycle = dfs(i, 0);
        if(cycle) {
            std::cout<< "Cycle exists!!";
            break;
        }
    }
    if(!cycle) std::cout<< "Cycle doesn't exists!";

    return 0;
}