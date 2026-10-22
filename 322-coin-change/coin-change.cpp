class Solution {
public:
    const int INF = 1e9;
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1,0);
        for(int i=0;i<=amount;i++){
            if(i % coins[0] == 0) prev[i] = i / coins[0];
            else prev[i] = INF;
        }
        for(int i=1;i<n;i++){
            for(int a=0;a<=amount;a++){
                int notPick = prev[a];
                int pick = INF;
                if(a >= coins[i]) pick = 1 + curr[a-coins[i]];
                curr[a] = min(pick,notPick);
            }
            prev = curr;
        }
        int ans = prev[amount];
        if(ans >= INF) return -1;
        return ans;
    }
};