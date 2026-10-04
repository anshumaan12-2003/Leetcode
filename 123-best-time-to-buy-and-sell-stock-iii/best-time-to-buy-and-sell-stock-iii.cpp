class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cnt=0;cnt<2;cnt++){
                    long profit = 0;
                    if(buy){
                        profit = max(-prices[i] + dp[i+1][0][cnt],dp[i+1][1][cnt]);
                    }
                    else{
                        profit = max(prices[i] + dp[i+1][1][cnt+1],dp[i+1][0][cnt]);
                    }
                    dp[i][buy][cnt] = profit;
                }
            }
        }
        return dp[0][1][0];
    }
};