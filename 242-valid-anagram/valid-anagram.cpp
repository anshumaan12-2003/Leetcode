class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int freqArray[26] = {0};
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            freqArray[ch - 'a']++;
        }

        for(int i=0;i<t.length();i++){
            char ch = t[i];
            freqArray[ch - 'a']--;
        }

        for(int i=0;i<26;i++){
            if(freqArray[i] != 0) return false;
        }
        return true;
    }
};