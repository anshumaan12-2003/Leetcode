class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> ahead(2,vector<int>(k+1,0));
        vector<vector<int>> curr(2,vector<int>(k+1,0));
        
        //base cases
        for(int i=0;i<n;i++){
            for(int buy=0;buy<=1;buy++){
                ahead[buy][0] = 0;
            }
        }

        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=k;cap++){
                ahead[buy][cap] = 0;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    long profit = 0;
                    if(buy){
                        profit = max(-prices[i] + ahead[0][cap],ahead[1][cap]);
                    }
                    else{
                        profit = max(+prices[i] + ahead[1][cap-1],ahead[0][cap]);
                    }
                    curr[buy][cap] = profit;
                }
            }
            ahead = curr;
        }
        return ahead[1][k];
    }
};