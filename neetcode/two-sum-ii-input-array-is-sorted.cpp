class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer_arr;
        int left = 0,right = numbers.size() - 1;
        while(left<right){
            int summation = numbers[left] + numbers[right];
            if(summation == target){
                answer_arr.push_back(left+1);
                answer_arr.push_back(right+1);
                break;
            }
            else if(summation > target){
                right--;
            }
            else{
                left++;
            }
        }
        return answer_arr;
    }
};