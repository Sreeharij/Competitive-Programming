class Solution {
public:
    int solve(vector<int>& nums,int left,int right){
        if(left > right)return INT_MIN;
        if(left == right)return nums[left];
        int first_idx=-1,last_idx=-1;
        int negative_count = 0;
        for(int i=left;i<=right;i++){
            if(nums[i] < 0){
                negative_count++;
                if(first_idx == -1){
                    first_idx = i;
                }
                last_idx = i;
            }
        }
        int product = 1,product_copy1 = 1,product_copy2 = 1;
        if(negative_count%2 == 0){
            for(int i=left;i<=right;i++){
                product *= nums[i];
            }
            return product;
        }
        else{
            for(int i=first_idx+1;i<=right;i++){
                product_copy1 *= nums[i];
            }
            for(int i=last_idx-1;i>=left;i--){
                product_copy2 *= nums[i];
            }
            return max(product_copy1,product_copy2);
        }

    }

    int maxProduct(vector<int>& nums) {
        int length = nums.size();
        int max_product = INT_MIN;
        vector<int> zero_indices;
        for(int i=0;i<length;i++){
            if(nums[i] == 0){
                zero_indices.push_back(i);
            }
        }
        int left = 0;
        for(auto val: zero_indices){
            max_product = max(max_product,solve(nums,left,val-1));
            left = val+1;
        }
        max_product = max(max_product,solve(nums,left,length-1));
        if(max_product < 0){
            if(zero_indices.size() > 0)return 0;
        }
        return max_product;
    }
};