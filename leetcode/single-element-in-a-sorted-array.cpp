class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int answer=-1;
        while(left < right){
            int mid = (left + right)/2;

            if(mid == 0 || mid == nums.size()-1){
                answer = nums[mid];
                break;
            }
            else{
                if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                    answer = nums[mid];
                    break;
                }
                else{
                    if((mid-left+1)%2 == 1){
                        if(nums[mid] == nums[mid+1]){
                            left = mid+2;
                        }
                        else{
                            right = mid -2;
                        }
                    }
                    else{
                        if(nums[mid] == nums[mid-1]){
                            left = mid + 1;
                        }
                        else{
                            right = mid - 1;
                        }
                    }
                }
            }
        }
        return left == right ? nums[left] : answer;
    }
};