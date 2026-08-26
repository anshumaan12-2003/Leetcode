class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n1 = nums1.size();
        int n2 = nums2.size();
        int left = 0;
        int right = 0;
        while(left < n1 && right < n2){
            if(nums1[left] == nums2[right]){
                ans.push_back(nums1[left]);
                left++;
                right++;
            }
            else if(nums1[left] < nums2[right]) left++;
            else right++;
        }
        return ans;
    }
};