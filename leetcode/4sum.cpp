class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> answer;
        int length = nums.size();
        for(int i=0;i<length-3;i++){
            for(int j=i+1;j<length-2;j++){
                int left = j+1;
                int right = length-1;
                while(left < right){
                    long long current_sum = (long long)nums[i] + (long long)nums[j]
                                            + (long long)nums[left] + (long long)nums[right];
                    if(current_sum == target){
                        answer.push_back({nums[i],nums[j],nums[left],nums[right]});
                        int left_start = left;
                        int right_start = right;
                        while(left < right && nums[left] == nums[left_start]) left++;
                        while(left < right && nums[right] == nums[right_start]) right--;
                    }
                    else if(current_sum < target){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
                while(j+1 < length && nums[j] == nums[j+1])j++;
            }
            while(i+1 < length && nums[i] == nums[i+1])i++;
        }
        return answer;
    }
};