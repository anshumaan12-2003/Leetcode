class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxFruits = 0;
        int different = 0;
        int left = 0;
        unordered_map<int,int> freq;

        for(int right=0;right<fruits.size();right++){

            freq[fruits[right]]++;
            if(freq[fruits[right]] == 1) different++;

            while(different > 2){

                freq[fruits[left]]--;
                if(freq[fruits[left]] == 0){
                    different--;
                }
                left++;
            }


            maxFruits = max(maxFruits,right - left + 1);
        }
        return maxFruits;
    }
};