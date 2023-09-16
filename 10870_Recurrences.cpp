#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()

const int MXN = 1e5 + 5, INF = 1e9 + 5;
int f[16], a[16], mod, d, n;
const int N = 15;
struct Mat
{
    ll data[N][N];
    Mat operator *(const Mat& a) const{
    Mat tmp;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            tmp.data[i][j] = 0;
            for (int k = 0; k < d; k++)
            {
                tmp.data[i][j] += (data[i][k] * a.data[k][j])%mod;
            }
            tmp.data[i][j] %= mod;
        }
    }
    return tmp;
    }
}M, identity;

Mat power(Mat mat, ll n, ll d)
{
    // Initializing the identity matrix
    for (size_t i = 0; i < N; i++)
        identity.data[i][i] = 1;

    while (n)
    {
        if (n & 1) // odd
            identity = identity * mat;
        mat = mat * mat;
        n >>= 1; // n/2
    }
    return identity;
}

int solve(int d, int n)
{
    n -= d;
    auto resMat = power(M, n, d);
    int ans = 0;
    for(int i=0; i<d; i++){
        ans += resMat.data[0][i] * f[d-i-1]%mod;
    }
    return ans%mod;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin>>d>>n>>mod && (d+n+mod))
    {
        memset(&identity, 0, sizeof(Mat));
        memset(&M, 0, sizeof(Mat));
        for(int i=0; i<d; i++){
            cin>>a[i];
            a[i] %= mod;
        }
        for(int i=0; i<d; i++){
            cin>>f[i];
            f[i] %= mod;
        }
        for(int i=0; i<d; i++)
            M.data[0][i] = a[i];
        for (size_t i = 1; i < d; i++)
            M.data[i][i-1] = 1;

        cout << solve(d, n) <<endl;
    }
    
}