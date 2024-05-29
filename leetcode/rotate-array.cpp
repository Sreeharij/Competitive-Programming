class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        k = k%length;
        reverse(nums,0,length-k);
        reverse(nums,length-k,length);
        reverse(nums,0,length);
    }


    void reverse(vector<int>& nums, int start, int end){
        int temp = 0;
        for(int i=0;i<(end-start)/2;i++){
            temp = nums[start+i];
            nums[start+i] = nums[end-i-1];
            nums[end-i-1] = temp;
        }
    }
};