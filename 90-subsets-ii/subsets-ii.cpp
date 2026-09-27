class Solution {
public:
    void f(int i, int n, vector<vector<int>> &ans,vector<int> &arr,vector<int> &nums){
        if(i == n){
            ans.push_back(arr);
            return;
        }
        arr.push_back(nums[i]);
        f(i+1,n,ans,arr,nums);
        arr.pop_back();
        int j = i + 1;
        // skip
        while(j < n && nums[j] == nums[i]) j++;
        f(j,n,ans,arr,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(nums.begin(),nums.end());
        f(0,nums.size(),ans,arr,nums);
        return ans;
    }
};