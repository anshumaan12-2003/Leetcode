class Solution {
public:
    int f(int i,int amount,vector<int> &coins,int ways,vector<vector<int>> &dp){
        if(amount == 0){
            ways++;
            return ways;
        }
        if(i == 0){
            if(amount % coins[0] == 0){
                ways++;
                return ways;
            }
            else return 0;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        int pick = 0;
        if(amount >= coins[i]) pick = f(i,amount-coins[i],coins,ways,dp);
        int notPick = f(i-1,amount,coins,ways,dp);
        return dp[i][amount] = notPick + pick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,0,dp);
    }
};