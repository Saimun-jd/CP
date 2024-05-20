// This is my most hardworking built solution

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
#define loop(x ,i, n) for(int i=x; i<n; i++)
#define loop1(x, i, n) for(int i=x; i<=n; i++)
#define pn cout<< "NO" << endl;
#define py cout<< "YES" << endl;

const int MXN = 1e5 + 5, INF = 1e9 + 5;
const int N = 100;

void solve() {
	int tc;
	cin>> tc;
	while(tc--) {
        int n, k;
        cin>> n>> k;
        vector<int> a, b;
        vector<int> prfmax(n);
        vector<int> prfsum(n);
        loop(0, i, n) {
            int x;
            cin>> x;
            a.pb(x);
            prfsum[i] = (i==0)? a[0]: prfsum[i-1] + a[i];
        } 
        loop(0, i, n) {
            int x;
            cin>> x;
            b.pb(x);
            prfmax[i] = (i==0)? b[0]: max(prfmax[i-1], b[i]);
        } 

        int jmax = b[0];
        int total = a[0];
        int kp = k;
        k--;
        int maxi = b[0]*k;
        int m = (k<n)? k: n-1; // may need fix

        int imax = 0;
        for(int i = m; i>=1; i--) {
            int jmax = prfmax[i];
            int sum = prfsum[i] - prfsum[0] + jmax * (k-i); 
            if(sum>maxi) {
                imax = i;
                maxi = sum;
            }
        }
        total += maxi;
        cout<<  total << endl;
	}
}

signed main()
{
    fastio
    solve();
    
    return 0;
}