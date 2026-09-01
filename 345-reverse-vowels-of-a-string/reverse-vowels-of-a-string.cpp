class Solution {
public:
    bool isVowel(char x){
        return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U');
    }
    string reverseVowels(string s) {
        int n = s.length();
        int left = 0;
        int right = n - 1;
        while(left < right){
            while(left < right && !isVowel(s[left])){
                left++;
            }
            while(left < right && !isVowel(s[right])){
                right--;
            }
            if(left < right){
                swap(s[left],s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};