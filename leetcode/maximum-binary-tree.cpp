/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* make_tree(vector<int>& nums,int left,int right){
        if(left > right) return nullptr;
        int max_val = nums[left];
        int max_val_idx = left;
        for(int i=left;i<=right;i++){
            if(nums[i] > max_val){
                max_val = nums[i];
                max_val_idx = i;
            }
        }
        TreeNode* ptr = new TreeNode(max_val);
        ptr->left = make_tree(nums,left,max_val_idx-1);
        ptr->right = make_tree(nums,max_val_idx+1,right);

        return ptr;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return make_tree(nums,0,nums.size()-1);
    }
};
