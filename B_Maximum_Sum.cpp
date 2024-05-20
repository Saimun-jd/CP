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
#define loop(x, i, n) for(int i=x; i<n; i++)
#define loop1(x, i, n) for(int i=x; i<=n; i++)
#define pn cout<< "NO" << endl;
#define py cout<< "YES" << endl;

const int MXN = 1e5 + 5, INF = 1e9 + 7;
const int N = 100;

void solve() {
	int tc;
	cin>> tc;
	while(tc--) {
		int n, k;
        cin>> n>> k;
        vector<int> vec(n);
        for(auto &x: vec) cin>> x;
        sort(all(vec));

        vector<ll> prfx(n);
        prfx[0] = vec[0];
        loop(1, i, n) {
            prfx[i] = prfx[i-1] + vec[i];
        }

        int l = 0, r = n-1;
        while(k!=0) {
            // prfx[l+2*k-1] - prfx[l-1] >= prfx[r] - prfx[r-k]
            ll rs = (l-1 >= 0)? prfx[l-1]: 0;
            if((prfx[l+2*k-1] - rs) >= (prfx[r] - prfx[r-k])) {
                r--;
                k--;
            } else {
                l += 2;
                k--;
            }
        }
        // prfx[r] - prfx[l]
        cout<< prfx[r] - ((l-1>=0)? prfx[l-1]:0) << endl;

	}
}

signed main()
{
    fastio
    solve();
    
    return 0;
}