#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int tc;
    cin>> tc;
    while(tc--) {
        int n;
        cin>> n;
        ll l = 1, r = 10e9;
        ll d = 0;
        int a;
        ll x;
        ll ans = 0;
        std::vector<int> vec;
        for(int i = 0; i<n; i++) {
            cin>> a>> x;
            if(a == 3) {
                vec.push_back(x);
            }
            if(a == 1) l = max(x, l);
            if(a == 2) r = min(x, r);
        }
        for(auto v: vec) {
            if(v>=l && v<=r) d++;
        }
        if(l<=r) { 
            ans = (r-l)+1-d;
        }
        cout<< ans<< endl;
    }
}