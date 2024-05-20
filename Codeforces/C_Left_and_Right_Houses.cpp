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

int cil(int x) {
    int k = x/2;
    if(k*2>=x) return k;
    else return k+1;
}

void solve() {
	int tc;
	cin>> tc;
	while(tc--) {
		int n;
        cin>> n;
        int prf[2][n];
        string str;
        cin>> str;
        int allzero = 1;
        int allone = 1;
        loop(i, n) {
            char x = str[i];
            allzero &= (x=='0');
            allone &= (x=='1');
            if(i == 0) {
                prf[0][i] = (x=='0');
                prf[1][i] = (x=='1');
            } else {
                prf[0][i] = prf[0][i-1]+(x=='0');
                prf[1][i] = prf[1][i-1]+(x=='1');
            }
        }
        // if(allzero) {
        //     cout<< n << endl;
        //     continue;
        // }
        // if(allone) {
        //     cout<< 0 << endl;
        //     continue;
        // }
        int ans = 0;
        int k = INT_MAX;
        int middle = n/2;
        double mn = 1000000000000000;
        loop1(i, n) {
            int zeros = prf[0][i];
            int ones = prf[1][n-1] - prf[1][i];
            int dgt1 = i+1;
            if(zeros>=(int)(dgt1/2) && ones>=(int)((n-i-1)/2)) {
                 if(abs((n/2.0)-i-1) < mn) {
                    ans = i+1;
                    mn = abs((n/2.0)-i-1);
                }
            } 
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