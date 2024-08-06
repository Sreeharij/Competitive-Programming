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

//MORRIS TRAVERSAL APPROACH WITH O(n) time and O(1) space
class Solution {

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        TreeNode* current = root;
        TreeNode* extra;
        while(current){
            if(current->left == NULL){
                answer.push_back(current->val);
                current = current->right;
            }
            else{
                extra = current->left;
                while(extra->right && extra->right!=current){
                    extra = extra->right;
                }
                if(extra->right == NULL){
                    extra->right = current;
                    current = current->left;
                }
                else{
                    extra->right = NULL;
                    answer.push_back(current->val);
                    current = current->right;
                }
            }   
        }
        return answer;
    }
};
