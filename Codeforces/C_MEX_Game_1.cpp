#include <bits/stdc++.h>
using namespace std;

#define fastio std::ios_base::sync_with_stdio(false); \
                 std::cin.tie(nullptr);

using vi = vector<int>;
using mii = map<int, int>;
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
#define pn cout<< "NO" << endl;
#define py cout<< "YES" << endl;

const int MXN = 2*100000, INF = 1e9 + 5;
const int N = 100;

//alternative solution can be second smallest number which is present exactly once if the all previous elements are already present

void solve() {
	int tc;
	cin>> tc;
	while(tc--) {
		int n;
        cin>> n;
        unordered_map<int, int> mp;
        int maxn = 0;
        loop(i, n) {
            int x;
            cin>> x;
            maxn = max(maxn, x);
            mp[x]++;
        }
        maxn++;
        unordered_map<int, int> ans;
        bool alice = 1;
        loop1(i, maxn) {
            if(alice) {
                if(mp.find(i) != mp.end()) {
                    ans[i]++;
                    mp[i]--;
                    alice = 0;
                    // if there are repeating element
                    if(mp[i] > 0) {
                        mp[i]--;
                        alice = 1;
                    }
                }
                
            } else {
                if(mp.find(i) != mp.end()) {
                    mp[i]--;
                    alice = 1;
                    // if there are reapeting element
                    if(mp[i] > 0) {
                        mp[i]--;
                        ans[i]++;
                        alice = 0;
                    }
                }
            }
        }
        for(int i = 0; i<=maxn; i++) {
            if(ans.find(i) == ans.end()) {
                cout<< i << endl;
                break;
            }
        }
	}
}

signed main()
{
    fastio
    solve();
    
    return 0;
}