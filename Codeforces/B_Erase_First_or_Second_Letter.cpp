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

const int MOD = 1e9 + 7;
const int MXN = 1e5 + 1, INF = 1e9 + 5;
const int N = 100;


void solve() {
	int tc;
	cin>> tc;
	while(tc--) {
        int n;
        cin>> n;
        string str;
        cin>> str;
        unordered_map<char, int> mp;
        loop(i, n) {
            char ch = str[i];
            if(mp.find(ch) == mp.end()){ mp.insert({ch, i}); }
        }
        int ans = 0;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            ans += n-it->second;
        }
        cout<< ans << endl;
	}
}

signed main()
{
    fastio
    solve();
    
    return 0;
}