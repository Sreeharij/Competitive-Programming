class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> answer(candies.size(),false);
        int max_val = candies[0];
        for(int i=1;i<candies.size();i++){
            max_val = max_val > candies[i] ? max_val : candies[i];
        }
        for(int i=0;i<candies.size();i++){
            if(candies[i] + extraCandies >= max_val){
                answer[i] = true;
            }
        }
        return answer; 
    }
};