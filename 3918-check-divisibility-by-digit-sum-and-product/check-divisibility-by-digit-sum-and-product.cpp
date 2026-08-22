class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int temp = n;
        while(temp != 0){
            int a = temp % 10;
            sum += a;
            product *= a;
            temp = temp / 10;
        }
        int result = sum + product;
        return n % result == 0;
    }
};