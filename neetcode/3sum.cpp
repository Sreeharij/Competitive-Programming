class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        sort(nums.begin(),nums.end());

        int left = 1,right = nums.size()-1;
        int current_triplet; 
        for(int i=0;i<=nums.size()-3;i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            left = i+1;
            right = nums.size()-1;
            while(left < right){
                current_triplet = nums[i] + nums[left] + nums[right];
                if(current_triplet == 0){
                    answer.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left-1]) left++;
                    while(left < right && nums[right] == nums[right+1]) right--;
                }
                else if(current_triplet > 0){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return answer;
    }
};
