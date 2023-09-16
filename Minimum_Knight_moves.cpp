#include <bits/stdc++.h>

using ll = long long;
using pii = std::pair<int, int>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define REP(i, n) for(int i=0; i<n; i++)
#define REPQ(i, n) for(int i=0; i<=n; i++)

const int MXN = 1e5 + 5, INF = 1e9 + 10;
const int N = 8;
int visited[N][N];
int levels[N][N];

int getX(std::string s){
    return s[0] - 'a';
}
int getY(std::string s) {
    return s[1] - '1';
}

void reset() {
    REP(i, 8) {
        REP(j, 8) {
            visited[i][j] = 0;
            levels[i][j] = INF;
        }
    }
}

bool isValid(int x, int y) {
    return x>=0 && y>=0 && x<8 && y<8;
}

std::vector<pii> movements{
    {1, 2}, {1, -2},
    {2, 1}, {2, -1},
    {-1, 2}, {-1, -2},
    {-2, 1}, {-2, -1}
};

int bfs(std::string src, std::string dest) {
    std::queue<pii> Q;
    int srcX = getX(src);
    int srcY = getY(src);
    int destX = getX(dest);
    int destY = getY(dest);
    Q.push({srcX, srcY});
    visited[srcX][srcY] = 1;
    levels[srcX][srcY] = 0;
    while (!Q.empty()) {
        auto curr = Q.front();
        int dadX = curr.first, dadY = curr.second;
        Q.pop();
        for(auto movement: movements) {
            int childX = dadX + movement.first;
            int childY = dadY + movement.second;
            if(!isValid(childX, childY)) continue;
            if(!visited[childX][childY]){
                Q.push({childX, childY});
                visited[childX][childY] = 1;
                levels[childX][childY] = levels[dadX][dadY] + 1;
            }
        }
        if(levels[destX][destY] != INF) break;
    }
    return abs(levels[destX][destY]);
}


signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int TC;
    std::cin>>TC;
    while(TC--) {
        reset();
        std::string src, dest;
        std::cin >> src >> dest;
        std::cout << bfs(src, dest) << std::endl;
    }
    return 0;
}