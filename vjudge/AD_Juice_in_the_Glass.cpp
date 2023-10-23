#include <bits/stdc++.h>

#define fastio std::ios_base::sync_with_stdio(false); \
                std::cin.tie(0); std::cout.tie(0);

#define REQ(i, n) for(int i=1; i<=n; i++)

const double PI = acos(-1);

signed main() {
    fastio;
    int TC, r1, r2, h, p;
    std::cin >> TC;
    REQ(i, TC) {
        std::cin >> r1 >> r2 >> h >> p;
        double R = r2 + (r1-r2)* (double(p)/h);
        double sqr = (R * R + r2 * r2 + r2 * R);
        double V = 1/3.0 * PI * p * sqr;
        printf("Case %d: %lf\n", i, V);
    }

    return 0;
}