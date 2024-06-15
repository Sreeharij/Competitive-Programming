class Solution {
public:
    int jump(vector<int>& nums) {
        int length = nums.size();
        int jumps = 0;
        int current_idx = 0;
        int required_idx = 0;
        while(current_idx < length){
            int max_coverable = INT_MIN;
            if(current_idx == length - 1)return jumps;
            for(int i = current_idx+1;i<current_idx+1+nums[current_idx];i++){
                if(i >= length)break;
                if(i + nums[i] >= max_coverable){
                    max_coverable = min(i + nums[i],length-1);
                    required_idx = i;
                }
            }
            jumps++;
            current_idx = required_idx;
        }

        return jumps;
    }
};


class Solution {
public:
    int jump(vector<int>& nums) {
        int length = nums.size();
        int jumps = 0;
        int current_level_end_idx = 0;
        int next_level_farthest=0;
        for(int i=0;i<length-1;i++){
            next_level_farthest = max(next_level_farthest,nums[i] + i);
            if(i == current_level_end_idx){
                jumps++;
                current_level_end_idx = next_level_farthest;
                if(current_level_end_idx >= length-1)return jumps;
            }
        }
        return jumps;
    }
};