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

//O(N) SOLUTION WITH QUEUE
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzag_order;
        if(!root) return zigzag_order;
        queue<TreeNode*> q;
        q.push(root);
        int current = 1,next =0;
        TreeNode* ptr;
        int required_idx=0;
        vector<int> temp(current);
        bool flag = true;
        while(!q.empty()){
            if(current == 0){
                current = next;
                next = 0;

                if(flag){
                    flag = false;
                    required_idx = current - 1;
                }
                else{
                    flag = true;
                    required_idx = 0;
                }
                
                zigzag_order.push_back(temp);
                temp.clear();
                temp.resize(current);
            }

            ptr= q.front();
            q.pop();
            current -= 1;
            if(flag){
                temp[required_idx++] = ptr->val;
            }
            else{
                temp[required_idx--] = ptr->val;
            }

            if(ptr->left){
                q.push(ptr->left);
                next += 1;
            }
            if(ptr->right){
                q.push(ptr->right);
                next += 1;
            }
        }

        zigzag_order.push_back(temp);
        return zigzag_order;
    }
};

//O(N^2) SOLUTION WITHOUT QUEUE
//FORMS AN AGP SERIES AND SUMMATION LEADS TO O(N^2)

class Solution {
public:
    int tree_height(TreeNode* root){
        if(!root) return 0;
        int left = tree_height(root->left);
        int right = tree_height(root->right);
        int bigger = left > right ? left : right;
        return bigger+1;
    }

    void current_level(TreeNode* root,int level,vector<int>& temp,bool flag){
        if(!root) return;
        if(level == 1){
            temp.push_back(root->val);
        }
        else{
            if(flag){
                current_level(root->left,level-1,temp,flag);
                current_level(root->right,level-1,temp,flag);
            }
            else{
                current_level(root->right,level-1,temp,flag);
                current_level(root->left,level-1,temp,flag);
            }
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzag_order;
        if(!root) return zigzag_order;
        int height = tree_height(root);
        vector<int> temp;
        bool flag =true;
        for(int i=1;i<=height;i++){
            temp.clear();
            current_level(root,i,temp,flag);
            flag = flag ? false : true;
            zigzag_order.push_back(temp);
        }
        return zigzag_order;
    }
};
