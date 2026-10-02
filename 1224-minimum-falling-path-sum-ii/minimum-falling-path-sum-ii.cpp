class Solution {
public:
    int f(int row,int last,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(row == 0){
            int mini = INT_MAX;
            for(int i=0;i<grid[0].size();i++){
                if(i != last){
                    mini = min(mini,grid[0][i]);
                }
            }  
            return mini;
        }

        if(dp[row][last] != -1) return dp[row][last];

        int mini = INT_MAX;
        for(int i=0;i<grid[0].size();i++){
            if(i != last){
                int up = grid[row][i] + f(row - 1,i,grid,dp);
                mini = min(mini,up);
            }
        }
        
        return dp[row][last] = mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(n - 1,n,grid,dp);
    }
};