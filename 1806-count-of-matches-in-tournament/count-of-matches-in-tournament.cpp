class Solution {
public:
    int numberOfMatches(int n) {
        int matchesPlayed = 0;
        int temp = n;
        while(temp != 1){
            if(temp % 2 == 0){
                matchesPlayed += (temp / 2);
                temp = temp / 2;
            }
            else{
                matchesPlayed += ((temp - 1) / 2);
                temp = ((temp - 1) / 2) + 1;
            }

        }
        return matchesPlayed;
    }
};