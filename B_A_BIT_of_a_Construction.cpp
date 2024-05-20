#include <bits/stdc++.h>
using namespace std;

#define fastio                             \
    std::ios_base::sync_with_stdio(false); \
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
#define loop(x, i, n) for (int i = x; i < n; i++)
#define loop1(x, i, n) for (int i = x; i <= n; i++)
#define pn cout << "NO" << endl;
#define py cout << "YES" << endl;

const int MXN = 1e5 + 5, INF = 1e9 + 7;
const int N = 100;

void solve()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        ll n, k;
        cin >> n >> k;
        int msb = log2(k);
        if (n == 1)
        {
            cout << k << endl;
            continue;
        }
        vector<ll> vec;
        ll l = (1<<msb)-1;
        vec.push_back(l);
        vec.push_back(k-l);
        for(ll i = 0; i<n-2; i++) vec.push_back(0);

        for(auto x: vec) {
            cout<< x << " ";
        }

        cout << endl;
    }
}

signed main()
{
    fastio
    solve();

    return 0;
}