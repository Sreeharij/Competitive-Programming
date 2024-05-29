class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int pairs = 0;

        unordered_map<int,int> hash_map;
        for(int i=0;i<nums.size();i++){
            hash_map[nums[i]]++;
        }
        for(auto x : hash_map){
            pairs += x.second * (x.second - 1) / 2;
        }
        return pairs;
    }
};