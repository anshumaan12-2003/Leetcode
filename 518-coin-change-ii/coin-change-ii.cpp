class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long long> prev(amount+1,0);
        vector<long long> curr(amount+1,0);
        for(int a=0;a<=amount;a++){
            if(a % coins[0] == 0) prev[a] = 1;
            else prev[a] = 0;
        }
        for(int i=1;i<n;i++){
            for(int a=0;a<=amount;a++){
                long long pick = 0;
                if(a >= coins[i]) pick = curr[a-coins[i]];
                long long notPick = prev[a];
                if(pick > INT_MAX - notPick) curr[a] = INT_MAX;
                else curr[a] = pick + notPick;
            }
            prev = curr;
        }
        return (int)prev[amount];
    }
};