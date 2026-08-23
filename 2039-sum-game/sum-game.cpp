class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int sum1 = 0, sum2 = 0;
        int q1 = 0, q2 = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                q1++;
            else
                sum1 += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                q2++;
            else
                sum2 += num[i] - '0';
        }

        int diffQ = q1 - q2;
        int diffSum = sum1 - sum2;

        // If the number of '?' is odd, Alice always wins.
        if (diffQ % 2 != 0)
            return true;

        // Bob can make the sums equal only in this case.
        return diffSum != -9 * diffQ / 2;
    }
};