class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {

        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {

            int val = num % k;

            vector<long long> newDp(k, 0);
            newDp[val] = 1;
            for (int r = 0; r < k; r++) {

                int newRem = (r * val) % k;

                newDp[newRem] += dp[r];
            }
            for (int r = 0; r < k; r++) {
                ans[r] += newDp[r];
            }

            dp = newDp;
        }

        return ans;
    }
};