class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;
        int n = nums.size();
        vector<int> freq(1001,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++){
                freq[nums[i][j]]++;
            }
        }
        for(int i=0;i<=1000;i++){
            if(freq[i] == n) ans.push_back(i);
        }
        return ans;
    }
};