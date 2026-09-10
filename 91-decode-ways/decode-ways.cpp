class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        if(s[0] == '0')
            return 0;

        // prev2 = dp[i-2]
        // prev1 = dp[i-1]
        int prev2 = 1;
        int prev1 = 1;

        for(int i = 1; i < n; i++) {

            int curr = 0;

            // Take one digit
            if(s[i] != '0') {
                curr += prev1;
            }

            // Take two digits
            int num = (s[i - 1] - '0') * 10
                    + (s[i] - '0');

            if(num >= 10 && num <= 26) {
                curr += prev2;
            }

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};