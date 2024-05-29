class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        unordered_set<char> hash_set(jewels.begin(),jewels.end());
        for(int i=0;i<stones.size();i++){
            if(hash_set.count(stones[i])){
                count++;
            }
        }
        return count;
    }
};