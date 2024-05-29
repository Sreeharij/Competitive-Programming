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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(root == nullptr) return answer;
        
        vector<int> temp;
        temp.push_back(root->val);
        queue<TreeNode*> q;
        q.push(root);
        int current_level_size;
        TreeNode* ptr;
        while(!q.empty()){
            answer.push_back(temp);
            current_level_size = q.size();
            temp.clear();
            for(int i=0;i<current_level_size;i++){
                ptr = q.front();
                q.pop();
                if(ptr->left){
                    q.push(ptr->left);
                    temp.push_back(ptr->left->val);
                }
                if(ptr->right){
                    q.push(ptr->right);
                    temp.push_back(ptr->right->val);
                }
            }         
        }
        return answer;
    }
};
