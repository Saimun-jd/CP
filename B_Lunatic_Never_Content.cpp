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

const int MXN = 1e9 + 1, INF = 1e9 + 7;
const int N = 100;

void solve() {
	int tc;
	cin>> tc;
	while(tc--) {
        int n;
        cin>> n;
        vi vec(n);
        for(auto &x: vec) {
            cin>> x;
        }
        int x = 0;
        for(int i = 0; i<n/2; i++) {
            x = __gcd(x, abs(vec[i] - vec[n-i-1]));
        }
        cout<< x << endl;
	}
}

signed main()
{
    fastio
    solve();
    
    return 0;
}