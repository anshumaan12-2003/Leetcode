class Solution {
public:
    int arraySign(vector<int>& nums) {
        // int cntNeg = 0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i] == 0) return 0;
        //     else if(nums[i] < 0) cntNeg++;
        // }
        // if(cntNeg % 2 == 0) return 1;
        // return -1;

        int sign = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0) return 0;
            else if(nums[i] < 0) sign = -sign;
        }
        return sign;
    }
};