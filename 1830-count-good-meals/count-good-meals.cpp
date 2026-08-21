class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int n = deliciousness.size();
        const int MOD = 1e9 + 7;
        unordered_map<int,int> mpp;
        long long count = 0;
        for(int i=0;i<n;i++){
            for(int power = 1;power<= (1 << 21); power *= 2){
                int needed = power - deliciousness[i];
                if(mpp.find(needed) != mpp.end()){
                    count += mpp[needed];
                }
            }
            mpp[deliciousness[i]]++;
            count %= MOD;
        }
        return count;
    }
};