/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encoded = "";
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* ptr;
        int node_val,sign_bit;
        while(!q.empty()){
            ptr = q.front();
            q.pop();
            encoded += '#';
            if(ptr){
                encoded += to_string(ptr->val);
                q.push(ptr->left ? ptr->left : nullptr);
                q.push(ptr->right ? ptr->right : nullptr);
            }
            else{
                encoded += '$';
            }
        }
        return encoded;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0 || data[1] == '$') return nullptr;
        vector<int> values;
        int i=1;
        while(i<data.size()){
            if(data[i] == '#'){
                i++;continue;
            }
            if(data[i] == '$'){
                values.push_back(10000);
                i++;
            }
            else{
                string st = "";
                while(i < data.size() && data[i]!='#'){
                    st += data[i++];
                }
                values.push_back(stoi(st));
            }
        }
        TreeNode* root = new TreeNode(values[0]);
        TreeNode* ptr = root;
        queue<TreeNode*> q;
        q.push(root);
        i=1;
        while(!q.empty()){
            ptr = q.front();
            q.pop();
            if(values[i] != 10000){
                ptr->left = new TreeNode(values[i++]);
                q.push(ptr->left);
            }else i++;
            if(values[i] != 10000){
                ptr->right = new TreeNode(values[i++]);
                q.push(ptr->right);
            }else i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
