class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size();

        int j = -1;
        int ans = 0;

        for(int i=0;i<n;i++){
            if(forts[i] == 0) continue;

            if(j != -1 && forts[i] != forts[j]){
                ans = max(ans,i-j-1);
            }

            j = i;
        }
        return ans;
    }
};