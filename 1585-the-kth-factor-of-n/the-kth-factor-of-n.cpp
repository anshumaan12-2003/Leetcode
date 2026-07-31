class Solution {
public:
    int kthFactor(int n, int k) {
        int root = sqrt(n);
        //first pass
        for(int i=1;i<=root;i++){
            if(n % i == 0) k--;
            if(k == 0) return i;
        }
        //second pass
        for(int i=root;i>=1;i--){
            if(n % i == 0){
                if(i * i == n) continue;
                k--;
                if(k == 0) return n/i;
            }
        }
        return -1;
    }
};