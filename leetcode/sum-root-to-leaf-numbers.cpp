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
    void backtrack(TreeNode* ptr,int& answer,int current){
        if(ptr == nullptr){
            return;
        }
        current = current * 10 + ptr->val;
        if(ptr->left == nullptr && ptr->right == nullptr){
            answer += current;
            return;
        }
        backtrack(ptr->left,answer,current);
        backtrack(ptr->right,answer,current);

    }

    int sumNumbers(TreeNode* root) {
        int answer = 0;
        backtrack(root,answer,0);

        return answer;
    }
};