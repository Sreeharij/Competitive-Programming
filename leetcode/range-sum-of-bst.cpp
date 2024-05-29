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
    void modified_inorder(TreeNode* root, int low, int high,int &sum_val){
        if(!root) return;
        if(root->val < low){
            modified_inorder(root->right,low,high,sum_val);
        }
        else{
            if(root->val > high){
                modified_inorder(root->left,low,high,sum_val);
            }
            else{
                sum_val += root->val;
                modified_inorder(root->left,low,high,sum_val);
                modified_inorder(root->right,low,high,sum_val);
            }
        }
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum_val = 0;
        modified_inorder(root,low,high,sum_val);
        return sum_val;
    }
};
