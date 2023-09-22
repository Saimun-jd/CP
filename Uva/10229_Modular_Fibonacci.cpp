#include <iostream>
#include <cassert>
# include <cstdio>
# define ll long long
using namespace std;

ll mod=1;
struct Mat2x2 {
    ll data[2][2];
    Mat2x2 friend operator *(const Mat2x2& a, const Mat2x2& b){
      Mat2x2 c;
      for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
          ll sum = 0;
          for(int k=0; k<2; k++){
            sum += (a.data[i][k] % mod) * (b.data[k][j] % mod);
            sum %= mod;
          }
          sum %= mod;
          c.data[i][j] = sum;
        }
      }
      return c;
    }
};

Mat2x2 power(Mat2x2 mat, ll p)
{
  Mat2x2 identity{
    {
      {1, 0},
      {0, 1}
    }
  };
  while (p)
  {
    if (p&1) //odd
      identity = identity * mat;
    mat = mat * mat;
    p >>= 1;
  }
  return identity;
}

int main() {
  ll n, m;
  Mat2x2 mat{
    {{1, 1},
    {1, 0}}
  };
  while (cin>>n>>m)
  {
    mod = 1;
    for (int i = 0; i < m; i++) mod *= 2;
    auto ans = power(mat, n-1);
    ans.data[0][0] %= mod;
    cout << ans.data[0][0] << endl;
  }
  
  return 0;
}