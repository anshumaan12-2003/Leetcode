class Solution {
public:
    vector<int> findnse(vector<int> &nums){
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findpsee(vector<int> &nums){
        int n = nums.size();
        vector<int> psee(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            if(st.empty()) psee[i] = -1;
            else psee[i] = st.top();
            st.push(i);
        }
        return psee;
    }
    long long subArrayMins(vector<int>& nums){
        int n = nums.size();
        vector<int> nse = findnse(nums);
        vector<int> psee = findpsee(nums);
        long long total = 0;
        for(int i=0;i<n;i++){
            long long left = i - psee[i];
            long long right = nse[i] - i;
            total += (right*left*1LL*nums[i]);
        }
        return total;
    }
    vector<int> findnge(vector<int> &nums){
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(st.empty()) nge[i] = n;
            else nge[i] = st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int> findpgee(vector<int> &nums){
        int n = nums.size();
        vector<int> pgee(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            if(st.empty()) pgee[i] = -1;
            else pgee[i] = st.top();
            st.push(i);
        }
        return pgee;
    }
    long long subArrayMax(vector<int>& nums){
        int n = nums.size();
        vector<int> nge = findnge(nums);
        vector<int> pgee = findpgee(nums);
        long long total = 0;
        for(int i=0;i<n;i++){
            long long left = i - pgee[i];
            long long right = nge[i] - i;
            total += (right*left*1LL*nums[i]);
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long mins = subArrayMins(nums);
        long long maxs = subArrayMax(nums);
        return maxs-mins;
    }
};