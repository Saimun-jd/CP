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
const int N = 1e5+5;

void solve() {
	int tc;
	cin>> tc;
	while(tc--) {
		ll n;
        cin>> n;
        ll vec[n] = {0};
        ll prfsum[n] = {0};
        vector<pair<ll, ll>> arr;
        loop(i, n) {
            int x;
            cin>> x;
            arr.push_back(make_pair(x, i));
        }

        sort(all(arr));

        for(ll i = 0; i < n; i++) {
            ll val = arr[i].first;
            prfsum[i] = (i==0)? val: val+prfsum[i-1];
        }
        ll j = 0;
        for(ll i = 0; i < n; i++) {
            j = max(j, i);
            while(j<n-1 && prfsum[j] >= arr[j+1].first) {
                j++;
            }  
            vec[arr[i].second] = j;
        }
        
        for(ll i = 0; i<n; i++) {
            cout<< vec[i] << " ";
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