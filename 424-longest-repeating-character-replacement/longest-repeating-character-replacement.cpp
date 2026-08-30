class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxLen = 0;
        int maxfreq = 0;

        vector<int> freq(26,0);

        for(int right = 0; right < s.length(); right++){
            freq[s[right] - 'A']++;
            maxfreq = max(maxfreq,freq[s[right] - 'A']);

            int replacements = (right - left + 1) - maxfreq;

            while(replacements > k){
                freq[s[left] - 'A']--;
                left++;
                replacements = (right - left + 1) - maxfreq;

            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};