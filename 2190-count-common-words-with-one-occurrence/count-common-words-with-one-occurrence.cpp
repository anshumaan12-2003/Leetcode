class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> mpp1,mpp2;
        for(int i=0;i<words1.size();i++){
            mpp1[words1[i]]++;
        }
        for(int i=0;i<words2.size();i++){
            mpp2[words2[i]]++;
        }
        int cnt = 0;
        for(auto it:mpp1){
            if(it.second == 1 && mpp2[it.first] == 1) cnt++;
        }
        return cnt;
    }
};