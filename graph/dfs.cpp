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
int levels[N];

void dfs(int s) {
    visited[s] = true;
    for(auto child : graph[s]) {
        if(!visited[child]) {
            levels[child] = levels[s] + 1;
            dfs(child);
        }
    }
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
    dfs(1);
    std::cout << "1 --> 9 is : " << levels[9];

    return 0;
}