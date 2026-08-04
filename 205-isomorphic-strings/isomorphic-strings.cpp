class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mapST[256];
        int mapTS[256];
        for(int i=0;i<256;i++){
            mapST[i] = -1;
            mapTS[i] = -1;
        }

        for(int i=0;i<s.length();i++){
            char ch1 = s[i];
            char ch2 = t[i];

            if(mapST[ch1] == -1 && mapTS[ch2] == -1){
                mapST[ch1] = ch2;
                mapTS[ch2] = ch1;
            }
            else{
                if(mapST[ch1] != ch2 || mapTS[ch2] != ch1) return false;
            }
        }
        return true;
    }
};