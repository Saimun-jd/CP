class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return coin2(n, amount, coins, dp);
    }
    int coin2(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if(idx==0) return 0;
        if(amount==0) return 1;
        if(dp[idx][amount] != -1) return dp[idx][amount];
        long long ans = 0;
        int n = coins.size();

        if(amount>=coins[idx-1])
            ans = coin2(idx, (amount-coins[idx-1]), coins, dp) + coin2(idx-1, amount, coins, dp);
            else ans = coin2(idx-1, amount, coins, dp);
        
        return dp[idx][amount] = ans;
    }
};