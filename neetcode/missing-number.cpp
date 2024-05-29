class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xored_val = 0;
        int i=1;
        for(auto x:nums){
            xored_val ^= x;
            xored_val ^= i++;
        }
        return xored_val;
    }
};