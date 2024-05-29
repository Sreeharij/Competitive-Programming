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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* ptr;
        int current=1,next=0;
        int current_sum=0; 
        int max_sum = INT_MIN; 
        int required_level = 0,current_level=1;
        while(!q.empty()){
            ptr = q.front();
            q.pop();
            current -= 1;
            current_sum += ptr->val;

            if(ptr->left){
                q.push(ptr->left);
                next += 1;
            }
            if(ptr->right){
                q.push(ptr->right);
                next += 1;
            }
            if(current == 0){
                if(current_sum > max_sum){
                    max_sum = current_sum;
                    required_level = current_level;
                }
                current_sum = 0;
                current = next;
                next = 0;
                current_level += 1;
            }
        }

        return required_level;
    }
};
