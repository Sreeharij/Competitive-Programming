class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        return max(find_max(0,nums.size()-2,nums),find_max(1,nums.size()-1,nums));
    }

    int find_max(int left,int right,vector<int>& nums){
        int first = 0,second = 0;
        int current;
        for(int i=left;i<=right;i++){
            current = (first + nums[i]) > second ? (first + nums[i]) : second;
            first = second;
            second = current;
        }
        return current;
    }
};
