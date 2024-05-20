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
		int n;
        cin>> n;
        vector<ll> prfsum(n);
        loop(0, i, n) {
            int x;
            cin>> x;
            prfsum[i] = (i==0)? x : prfsum[i-1] + x; 
        }

        ll maxi = 0;
        for(int k = 1; k<=n/2; k++) {
            if(n%k == 0) {
                vector<ll> vec;
                for(int i = 0; i<n; i+=k) {
                    if((i+k-1)<n && (i+2*k-1)<n) {
                        if(i==0) vec.push_back(prfsum[i+k-1]);
                        ll div2 = prfsum[i+(2*k)-1] - prfsum[i+k-1];
                        vec.pb(div2);
                    } else break;
                }
                maxi = max(maxi, *max_element(all(vec))- *min_element(all(vec)));
            }
        }
        cout<< maxi << endl;
	}
}

signed main()
{
    fastio
    solve();
    
    return 0;
}