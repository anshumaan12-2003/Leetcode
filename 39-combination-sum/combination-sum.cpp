class Solution {
public:
    void f(int i,int n,int sum,vector<vector<int>> &ans,vector<int> &arr,vector<int> &candidates,int target){
        if(sum == target){
            ans.push_back(arr);
            return;
        }
        if(sum > target){
            return;
        }
        if(i == n) return;
        arr.push_back(candidates[i]);
        sum = sum + candidates[i];
        f(i,n,sum,ans,arr,candidates,target);
        sum = sum - candidates[i];
        arr.pop_back();
        f(i+1,n,sum,ans,arr,candidates,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        int n = candidates.size();
        f(0,n,0,ans,arr,candidates,target);
        return ans;
    }
};