class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int current_diff = INT_MAX;
        int lowest_diff = INT_MAX;
        int answer = INT_MAX;

        for(int i=0;i<nums.size()-2;i++){
            int left = i+1;
            int right = nums.size()-1;
            while(left < right){
                int sum_val = nums[i] + nums[left] + nums[right];
                current_diff = abs(sum_val - target);
                if(current_diff < lowest_diff){
                    lowest_diff = current_diff;
                    answer = sum_val;
                }
                if(sum_val < target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return answer;

    }
};