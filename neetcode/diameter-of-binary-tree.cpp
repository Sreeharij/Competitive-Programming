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
    int depth_func(TreeNode* root,int &diameter){
        if(root == nullptr){
            return 0;
        }
        int left_depth = depth_func(root->left,diameter);
        int right_depth = depth_func(root->right,diameter);

        diameter = max(diameter,left_depth + right_depth);
        return max(left_depth,right_depth) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        depth_func(root,diameter);
        return diameter;
    }
};
