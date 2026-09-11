class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n,0);
        for(int i=0;i<n;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                int up = prev[j];
                int leftDiagonal = INT_MAX;
                if(j > 0) leftDiagonal = prev[j-1];
                int rightDiagonal = INT_MAX;
                if(j < n - 1) rightDiagonal = prev[j+1];
                curr[j] = matrix[i][j] + min(up,min(leftDiagonal,rightDiagonal));
            }
            prev = curr;
        }
        return *min_element(prev.begin(),prev.end());
    }
};