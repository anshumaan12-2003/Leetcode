class Solution {
public:
    bool isSubsetSum(vector<int>arr, int k){
        int n = arr.size();
        vector<int> prev(k+1,0);
        vector<int> curr(k+1,0);
        prev[0] = curr[0] = true;
        if(arr[0] <= k ) prev[arr[0]] = true;

        for(int i=1;i<n;i++){
            for(int target=1;target<=k;target++){
                bool notTake = prev[target];
                bool take = false;
                if(target >= arr[i]) take = prev[target - arr[i]];
                curr[target] = notTake | take;
            }
            prev = curr;
        }
        return prev[k];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }
        if(totalSum % 2 == 1) return false;

        int targetSum = totalSum / 2;
        return isSubsetSum(nums,targetSum);
    }
};