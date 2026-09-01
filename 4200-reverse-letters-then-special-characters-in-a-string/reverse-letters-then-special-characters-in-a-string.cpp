class Solution {
public:
    bool isAlphabet(char x){
        return (x >= 'a' && x <= 'z');
    }
    string reverseByType(string s) {
        int left = 0;
        int right = s.length() - 1;
        while(left < right){
            if(isAlphabet(s[left]) && isAlphabet(s[right])){
                swap(s[left],s[right]);
                left++;
                right--;
            }
            else if(!isAlphabet(s[left]) && !isAlphabet(s[right])){
                left++;
                right--;
            }
            else if(!isAlphabet(s[left])) left++;
            else right--;
        }
        left = 0;
        right = s.length() - 1;
        while(left < right){
            if(!isAlphabet(s[left]) && !isAlphabet(s[right])){
                swap(s[left],s[right]);
                left++;
                right--;
            }
            else if(isAlphabet(s[left]) && isAlphabet(s[right])){
                left++;
                right--;
            }
            else if(isAlphabet(s[left])) left++;
            else right--;
        }
        return s;
    }
};