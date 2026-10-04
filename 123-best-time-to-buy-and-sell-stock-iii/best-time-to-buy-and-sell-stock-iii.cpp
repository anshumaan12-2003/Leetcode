class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));

        // base cases
        for(int i=0;i<n;i++){
            for(int buy=0;buy<=1;buy++){
                ahead[buy][0] = 0;
            }
        }
        for(int buy=0;buy<=1;buy++){
            for(int cnt=0;cnt<=2;cnt++){
                ahead[buy][cnt] = 0;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cnt=1;cnt<=2;cnt++){
                    long profit = 0;
                    if(buy){
                        profit = max(-prices[i] + ahead[0][cnt],ahead[1][cnt]);
                    }
                    else{
                        profit = max(prices[i] + ahead[1][cnt-1],ahead[0][cnt]);
                    }
                    curr[buy][cnt] = profit;
                }
            }
            ahead = curr;
        }
        return ahead[1][2];
    }
};