class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> answer(length,0);

        int temp_product = 1;
        answer[0] = 1;
        for(int i=1;i<length;i++){
            temp_product *= nums[i-1];
            answer[i] += temp_product;
        }   
        temp_product = 1;
        for(int i=length-2;i>=0;i--){
            temp_product *= nums[i+1];
            answer[i] *= temp_product;
        }
        return answer;
    }
};