class Solution {
public:
    void merge(vector<int>& nums,vector<int>& left_arr,vector<int>& right_arr,int left,int mid,int right){
        int left_size = mid - left + 1;
        int right_size = right - mid;
        for(int i=0;i<left_size;i++){
            left_arr[i] = nums[left + i]; 
        }
        for(int i=0;i<right_size;i++){
            right_arr[i] = nums[mid+1+i];
        }
        int i=0,j=0,k=left;
        while(i < left_size && j < right_size){
            if(left_arr[i] <= right_arr[j]){
                nums[k++] = left_arr[i++];
            }   
            else{
                nums[k++] = right_arr[j++];
            }
        }
        while(i < left_size){
            nums[k++] = left_arr[i++];
        }
        while(j < right_size){
            nums[k++] = right_arr[j++];
        }
    }

    void mergeSort(vector<int>& nums,vector<int>& left_arr,vector<int>& right_arr,int left,int right){
        if(left < right){
            int mid = (left + right)/2;
            mergeSort(nums,left_arr,right_arr,left,mid);
            mergeSort(nums,left_arr,right_arr,mid+1,right);
            merge(nums,left_arr,right_arr,left,mid,right);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_arr(n,0);
        vector<int> right_arr(n,0);
        mergeSort(nums,left_arr,right_arr,0,n-1);

        return nums;
    }
};