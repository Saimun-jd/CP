#include<bits/stdc++.h>
using pii = std::pair<int, int>;
int main()
{
    int tc;
    std::cin>> tc;
    while(tc--) {
        int a, b, xk, xq, yk, yq;
        std::cin>> a>> b;
        std::cin>> xk>> yk;
        std::cin>> xq>> yq;
        std::set<pii> sk, sq;
        int ans = 0;
        sk.insert({xk+a, yk+b});
        sk.insert({xk-a, yk+b});
        sk.insert({xk+a, yk-b});
        sk.insert({xk-a, yk-b});
        sk.insert({xk+b, yk+a});
        sk.insert({xk-b, yk+a});
        sk.insert({xk+b, yk-a});
        sk.insert({xk-b, yk-a});

        sq.insert({xq+a, yq+b});
        sq.insert({xq-a, yq+b});
        sq.insert({xq+a, yq-b});
        sq.insert({xq-a, yq-b});
        sq.insert({xq+b, yq+a});
        sq.insert({xq-b, yq+a});
        sq.insert({xq+b, yq-a});
        sq.insert({xq-b, yq-a});
        for(auto it: sk) {
            if(sq.find({it.first, it.second}) != sq.end()) {
                ans++;
            }
        }
        std::cout<< ans <<std::endl;
    }
}