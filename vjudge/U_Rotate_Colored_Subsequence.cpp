#include <bits/stdc++.h>

#define fastio std::ios_base::sync_with_stdio(false); \
                std::ios_base::sync_with_stdio(false);

signed main()
{
    fastio;
    int N, M;
    std::cin>> N>> M;
    std::vector<int> vec(N+1);
    std::string s;
    std::cin>> s;
    std::vector<std::vector<int>> combs(M+1);
    std::vector<std::string> strs;
    for(int i=1; i<=N; i++) {
        int col;
        std::cin>> col;
        combs[col].push_back(i);
    }
    for(int i=1; i<=combs.size(); i++) {

    }
    for(int i=1; i<=M; i++) {
        std::vector<int> nums = combs[i];
        int sz= nums.size();
        int last_num = nums[sz-1];
        char ch = s[last_num-1];
        std::string temp = s;
        for(int k=0; k<sz-1; k++) {
            s[nums[k+1]-1] = temp[nums[k]-1];
        }
        s[nums[0]-1] = ch;
    }
    std::cout<< s;
    return 0;
}