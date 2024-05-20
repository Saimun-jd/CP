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

const int MXN = 1e6+5, INF = 1e9 + 5;
const int N = 100;


void solve() {
	int tc;
	cin>> tc;
	while(tc--) {
		int n;
        string s[2];
        cin>> n;
        cin>> s[0];
        cin>> s[1];
        int dp[2][n];
        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[1][0] = 1;
        dp[1][1] = s[1][0] == '>';
        for(int i = 2; i<n; i++) {
            for(int j = 0; j<2; j++)
                dp[j][i] = (dp[j][i-2] && s[j][i-2] == '>') || (dp[(j+1)%2][i-1] && s[(j+1)%2][i-1]=='>');
        } 
        dp[1][n-2] && s[1][n-2] == '>' ? cout<< "YES" << endl: cout<< "NO" << endl; 
	}
}

signed main()
{
    fastio
    solve();
    
    return 0;
}