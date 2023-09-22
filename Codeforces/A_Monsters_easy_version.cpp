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

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin>> T;
    while(T--) {
        int n;
        std::cin>> n;
        std::vector<int> ai(n);
        std::vector<int> bi(n);
        REP(i, n) {
            int a;
            std::cin>> a;
            ai.push_back(a);
        }
        std::sort(ai.begin(), ai.end());
        int ans = 0;
        ans += ai[0] - 1;
        bi[0] = ai[0];
        int kill = 2;
        for(int i=1; i<n; i++) {
            if(ai[i] < kill) {
                bi[i] = ai[i];
            } else{
                bi[i] = kill;
                kill++;
            }
        }
        for(int i=0; i<n; i++) {
            ans += (ai[i] - bi[i]);
        }
        std::cout<< ans<< std::endl;
    }
    return 0;
}