class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt = 0;
        int sum = 0;
        map<int,int> preSumMap;
        preSumMap[0] = 1;
        for(int right=0;right<nums.size();right++){
            sum += nums[right];
            int rem = sum - goal;
            if(preSumMap.find(rem) != preSumMap.end()){
                cnt += preSumMap[rem];
            }
            preSumMap[sum]++;
        }
        return cnt;
    }
};