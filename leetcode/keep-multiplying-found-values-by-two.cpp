class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> st(nums.begin(),nums.end());
        while(true){
            if(st.count(original)){
                original *= 2;
            }
            else{
                return original;
            }
        }
        return original;
    }
};


//below contains efficient solution
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int answer = 0;
        int remaining;
        for(int i=0;i<nums.size();i++){
            if(nums[i] % original != 0)continue;
            remaining = nums[i]/original;
            if((remaining & (remaining-1)) == 0){
                answer = answer | remaining;
            }
        }
        int highest_2 = 1;
        while(1){
            if((answer & 1) != 0){
                highest_2 *= 2;
                answer >>= 1;
            }
            else return highest_2 * original;
            if(answer <= 0) return highest_2 * original;
        }
        return original;

    }
};