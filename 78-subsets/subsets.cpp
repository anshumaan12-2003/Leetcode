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
        f(i+1,n,ans,arr,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        f(0,nums.size(),ans,arr,nums);
        return ans;
    }
};