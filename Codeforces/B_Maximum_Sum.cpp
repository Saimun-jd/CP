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

const int MXN = 1e5 + 5, INF = 1e9 + 5;
const int N = 100;
const ll MOD = 1e9 + 7;

void solve() {
	int tc;
	cin>> tc;
	while(tc--) {
		int n, k;
        cin>> n>> k;
        vector<int> vec(n);
        ll total = 0; // sum of whole array
        ll maxi = 0; // maximum subarray sum
        ll sum = 0; // sum till i
        for(auto &x: vec) {
            cin>> x;
            total += x;
            sum += x;
            maxi = max(maxi, sum);
            sum = max(0ll, sum);
        }

        total = (total%MOD + MOD)%MOD;
        // ans = total + ( 2^0 + 2^1 + 2^2 + 2^3 + ... + 2^(k-1) * maxi
        ll temp = 1;
        loop(i, k) {
            total = (total + maxi)%MOD;
            maxi = (maxi*2)%MOD; 
        }
        
        cout<< total << endl;
        
	}
}

signed main()
{
    fastio
    solve();
    
    return 0;
}