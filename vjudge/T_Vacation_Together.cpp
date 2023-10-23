#include <bits/stdc++.h>

#define fastio std::ios_base::sync_with_stdio(false); \
                std::ios_base::sync_with_stdio(false);

using ll = long long;
using pii = std::pair<int, int>;
using WGraph = std::vector<std::vector<pii>>;
using Graph = std::vector<std::vector<int>>;
using MinHeap = std::priority_queue<pii, std::vector<pii>, std::greater<pii>>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define REP(i, n) for(int i=0; i<n; i++)
#define REPQ(i, n) for(int i=0; i<=n; i++)
#define REQ(i, n) for(int i=1; i<=n; i++)
template <typename T>
T ckmax(T arg) {
    return arg;
}

// Recursive case to find the maximum value.
template <typename T, typename... Args>
T ckmax(T first, Args... rest) {
    T maxRest = ckmax(rest...); // Recursively find the maximum of the remaining arguments.
    return (first > maxRest) ? first : maxRest; // Compare the current argument with the maximum of the rest.
}

const int MXN = 1e5 + 5, INF = 1e9 + 5;

std::string BitwiseAnd(std::string& s1, std::string& s2) {
    std::string res = "";
    for(int i=0; i<s1.length(); i++) {
        res = res + (char)((s1[i]-'0' & s2[i]-'0')+'0');
    }
    return res;
}

signed main()
{
    fastio;
    int n, d;
    std::cin>> n>> d;
    std::vector<std::string> s;
    std::size_t maxlen = 0;
    REP(i, n) {
        std::string str;
        std::cin>> str;
        std::string temp;
        for(int i=0; i<str.length(); i++) {
            if(str[i] == 'o') temp.push_back(1);
            else temp.push_back(0);
        }
        s.push_back(temp);
        maxlen = std::max(maxlen, str.length());
    }
    std::string base(maxlen, '1');
    for(int i=0; i<s.size(); i++) {
        base = BitwiseAnd(base, s[i]);
    }
    int ans = 0;
    for(int i=0; i<base.length(); i++) {
        if(base[i] == '1'){
            int tempans = 0; 
            while (base[i] == '1') {
                tempans++;
                i++;
            }
            ans = std::max(ans, tempans);
        }
    }
    std::cout<< ans;
    return 0;
}