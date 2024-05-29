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
    int depth_func(TreeNode* root,bool &answer){
        if(root == nullptr) return 0;

        int left_depth = depth_func(root->left,answer);
        int right_depth = depth_func(root->right,answer);
        int difference = abs(left_depth-right_depth);
        if(difference > 1){
            answer = false;
        }
        return max(left_depth,right_depth) + 1;
    }

    bool isBalanced(TreeNode* root) {
        bool answer=true;
        depth_func(root,answer);
        return answer;
    }
};
