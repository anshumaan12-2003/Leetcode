class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,0)));
        for(int n1=0;n1<n;n1++){
            for(int n2=0;n2<n;n2++){
                if(n1 == n2) dp[m - 1][n1][n2] = grid[m - 1][n1];
                else dp[m - 1][n1][n2] = grid[m - 1][n1] + grid[m - 1][n2];
            }
        }

        for(int i=m-2;i>=0;i--){
            for(int n1=0;n1<n;n1++){
                for(int n2=0;n2<n;n2++){
                    int maxi = -1e8;
                    for(int dn1=-1;dn1<=+1;dn1++){
                        for(int dn2=-1;dn2<=+1;dn2++){
                            int value = 0;
                            if(n1 == n2){
                                value = grid[i][n1];
                            }
                            else{
                                value = grid[i][n1] + grid[i][n2];
                            }

                            if(n1 + dn1 >= 0 && n1 + dn1 < n && n2 + dn2 >= 0 && n2 + dn2 < n){
                                value += dp[i + 1][n1 + dn1][n2 + dn2];
                            }
                            else value += -1e8;
                            maxi = max(maxi,value);
                        }
                    }
                    dp[i][n1][n2] = maxi;
                }
            }
        }
        return dp[0][0][n - 1];
    }
};