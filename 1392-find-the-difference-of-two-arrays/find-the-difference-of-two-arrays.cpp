class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        vector<int> a,b;
        int left = 0;
        int right = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while(left < n1 && right < n2){
            if(nums1[left] == nums2[right]){
                int value = nums1[left];
                while(left < n1 && nums1[left] == value){
                    left++;
                }
                while(right < n2 && nums2[right] == value){
                    right++;
                }
            }
            else{
                if(nums1[left] < nums2[right]){
                    if(a.size() == 0 || a.back() != nums1[left]){
                        a.push_back(nums1[left]);
                    }
                    left++;
                }
                else{
                    if(b.size() == 0 || b.back() != nums2[right]){
                        b.push_back(nums2[right]);
                    }
                    right++;
                }
            }
        }
        while(left < n1){
            if(a.size() == 0 || a.back() != nums1[left]){
                a.push_back(nums1[left]);
            }
            left++;
        }
        while(right < n2){
            if(b.size() == 0 || b.back() != nums2[right]){
                b.push_back(nums2[right]);
            }
            right++;
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};