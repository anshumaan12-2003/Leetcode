class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;

        for(int i=0;i<k;i++){
            sum += nums[i];
        }

        double maxSum = sum;

        for(int right = k ; right < nums.size(); right++){
            sum += nums[right];
            sum -= nums[right - k];
            maxSum = max(maxSum,sum);
        }
        return (maxSum / k);
    }
};