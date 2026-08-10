class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixSumMap;
        prefixSumMap[0] = -1;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int remainder = sum % k;

            if(prefixSumMap.find(remainder) != prefixSumMap.end()){
                if((i - prefixSumMap[remainder]) >= 2) return true;
            }
            else prefixSumMap[remainder] = i;
        }
        return false;
    }
};