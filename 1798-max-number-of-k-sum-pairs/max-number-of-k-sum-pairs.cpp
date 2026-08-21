class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        int left = 0 , right = n - 1;
        sort(nums.begin(),nums.end());
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum == k){
                cnt++;
                left++;
                right--;
            }
            else if (sum > k) right--;
            else left++;
        }
        return cnt;
    }
};