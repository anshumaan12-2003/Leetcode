class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == divisor) return 1;
        bool sign = true;
        if(dividend >= 0 && divisor < 0) sign = false;
        if(dividend <= 0 && divisor > 0) sign = false;

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long ans = 0;
        while(n >= d){
            int cnt = 0;
            while(n >= (d << (cnt + 1))){
                cnt += 1;
            }
            ans += (1LL << cnt);
            n -= (d << cnt);
        }
        return sign ? (int)ans : (int)(-ans);
    }
};