class Solution {
public:
    bool rotateString(string s, string goal) {

        return s.size() == goal.size() && (s+s).find(goal) != string::npos;

        // Not a optimal method ya but idea is nice
        // if(s.length() != goal.length()) return false;
        // int n = s.length();
        // string original = s;
        // for(int k=0;k<n;k++){
        //     string temp = original;

        //     reverse(temp.begin(),temp.begin()+k);
        //     reverse(temp.begin()+k,temp.end());
        //     reverse(temp.begin(),temp.end());
        //     if(temp == goal) return true;
        // }
        // return false;
    }
};