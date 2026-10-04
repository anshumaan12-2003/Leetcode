class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2,0);
        vector<int> curr(2,0);

        long aheadnotbuy,aheadbuy,currnotbuy,currbuy;
        aheadnotbuy = aheadbuy = 0;

        for(int i=n-1;i>=0;i--){
            currnotbuy= max(+prices[i] + aheadbuy,aheadnotbuy);
            currbuy = max(-prices[i] + aheadnotbuy, aheadbuy);
            aheadbuy = currbuy;
            aheadnotbuy = currnotbuy;
        }
        return aheadbuy;
    }
};