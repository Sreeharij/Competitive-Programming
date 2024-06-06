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
    int solve(TreeNode* ptr,int& answer){
        if(!ptr)return INT_MIN;
        int left = solve(ptr->left,answer);
        int right = solve(ptr->right,answer);
        answer = max(answer,left);
        answer = max(answer,right);

        left = left == INT_MIN ? 0 : left;
        right = right == INT_MIN ? 0 : right;

        int vals[3] = {left + ptr->val, right + ptr->val,ptr->val};
        int sum = *max_element(vals,vals+3);
        answer = max(answer,sum);
        answer = max(answer, left + right + ptr->val);
        return sum;
    }

    int maxPathSum(TreeNode* root) {
        int answer = INT_MIN;
        solve(root,answer);
        return answer;
    }
};