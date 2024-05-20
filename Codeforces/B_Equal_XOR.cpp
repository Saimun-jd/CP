#include <bits/stdc++.h>
using namespace std;

#define fastio std::ios_base::sync_with_stdio(false); \
                 std::cin.tie(nullptr);

using ll = long long;
using pii = std::pair<int, int>;
using vii = std::vector<pii>;
using WGraph = std::vector<std::vector<pii>>;
using Graph = std::vector<std::vector<int>>;
using MinHeap = std::priority_queue<pii, std::vector<pii>, std::greater<pii>>;
using ump = std::unordered_map<int, int>;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define loop(i, n) for(int i=0; i<n; i++)
#define loop1(i, n) for(int i=0; i<=n; i++)
#define loop2(i, n) for(int i=1; i<=n; i++)

const int MXN = 1e5 + 5, INF = 1e9 + 5;
const int N = 100;

void solve() {
    int tc;
    cin>> tc;
    while(tc--) {
        int n, k;
        cin>> n>> k;
        std::vector<int> a(n+1, 0), b(n+1, 0);
        loop(i, n) {
            int x;
            cin>> x;
            a[x]++;
        }
        loop(i, n) {
            int x;
            cin>> x;
            b[x]++;
        }
        vector<int> ans1, ans2;
        loop2(i, n) {
            if(a[i]==1) {
                ans1.pb(i);
                ans2.pb(i);
                a[i]--;
                b[i]--;
            }
        }
        if(ans1.size()%2) {
            ans1.pop_back();
            ans2.pop_back();
        } 
        loop2(i, n) {
            if(a[i]==2) {
                ans1.pb(i);
                ans1.pb(i);
                a[i]-=2;
            }
            if(b[i]==2) {
                ans2.pb(i);
                ans2.pb(i);
                b[i]-=2;
            }
        }
        for(int i = 0; i<2*k; i++) {
            cout<< ans1[i] << " ";
        }
        cout<< endl;
        for(int i = 0; i<2*k; i++) {
            cout<< ans2[i] << " ";
        }
        cout<< endl;
    }
}

signed main()
{
    fastio
    solve();
    
    return 0;
}