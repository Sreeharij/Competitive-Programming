class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int length = arr.size();
        int left = 0,right = length - 1,mid;
        int current_missing = 0;
        int required_idx = length;
        while(left <= right){
            mid = (left + right)/2;
            current_missing = arr[mid] - mid - 1;
            if(current_missing<k){
                left = mid + 1;
            }
            else{
                required_idx = mid;
                right = mid - 1;
            }
        }
        return (k + required_idx);
    }
};