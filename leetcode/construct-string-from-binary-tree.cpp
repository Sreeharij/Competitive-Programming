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
    void get_string(TreeNode* root,string &final_string){
        if(!root) return;
        int number = root->val < 0 ? -1*root->val : root->val;
        int digits = number == 0 ? 1 : (int)log10(number) + 1;
        if(root->val < 0){
            final_string += '-';  
        }
        for(int exponent = pow(10,digits-1);exponent > 0;exponent /= 10){
            final_string += (int)((number%(exponent*10))/exponent) + '0';
        }

        if(root->left){
            final_string += '(';
            get_string(root->left,final_string);
            final_string += ')';
        }
        
        if(root->right){
            if(!root->left){
                final_string += "()";
            }
            final_string += '(';
            get_string(root->right,final_string);
            final_string += ')';
        }
    }

    string tree2str(TreeNode* root) {
        string final_string = "";
        get_string(root,final_string);
        return final_string;
    }
};


//Using stringstream to do all the tedius work
class Solution {
public:
    void get_string(TreeNode* root,stringstream &final_string){
        final_string << root->val;

        if(root->left){
            final_string << '(';
            get_string(root->left,final_string);
            final_string << ')';
        }
        
        if(root->right){
            if(!root->left){
                final_string << "()";
            }
            final_string << '(';
            get_string(root->right,final_string);
            final_string << ')';
        }
    }

    string tree2str(TreeNode* root) {
        stringstream final_string;
        get_string(root,final_string);
        return final_string.str();

    }
};
