class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash_set;
        for(int i=0;i<nums.size();i++){
        
            if(hash_set.find(nums[i])!=hash_set.end()){
                return true;
            }
            hash_set.insert(nums[i]);
        }
        return false;
    }
};
