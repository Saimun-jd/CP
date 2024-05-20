#include <bits/stdc++.h>
using namespace std;

#define fastio std::ios_base::sync_with_stdio(false); \
                 std::cin.tie(nullptr);

using vi = vector<int>;
using mii = map<int, int>;
using ll = long long;
using ull = unsigned long long;
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

const int MXN = 1e18, INF = 1e9 + 7;
const int N = 100;

void solve() {
	int tc;
	cin>> tc;
	while(tc--) {
        int n, k, a, b;
        cin>> n>> k>> a>> b;
        vector<pair<ll, ll>> vec(n);
        loop(0, i, n) {
            cin>> vec[i].first >> vec[i].second;
        }
        ll dist = abs(vec[b-1].first - vec[a-1].first) + abs(vec[b-1].second - vec[a-1].second);
        ll dist1 = LLONG_MAX, dist2 = LLONG_MAX;
        loop(0, i, k) {
            ll tempdest = abs(vec[a-1].first-vec[i].first) + abs(vec[a-1].second - vec[i].second);
            dist1 = min(dist1, tempdest);
            tempdest = abs(vec[b-1].first-vec[i].first) + abs(vec[b-1].second - vec[i].second);
            dist2 = min(dist2, tempdest);
            dist = min(dist, dist1+dist2);
        }
        cout<< dist << endl;
	}
}

signed main()
{
    fastio
    solve();
    
    return 0;
}