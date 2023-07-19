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
        if(!root)return "";
        queue<TreeNode*>q;
        q.push(root);
        string ans = "";
        while(!q.empty()){
            auto node = q.front();
                if(node==NULL)ans.append("N,");
                else ans.append(to_string(node->val)+',');
                q.pop();
                if(node){
                    q.push(node->left);
                    q.push(node->right);
                }
        }
        //cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(s,str,',');
            if(str=="N"){
                node->left=NULL;
            }else{
                TreeNode* leftn = new TreeNode(stoi(str));
                node->left = leftn;
                q.push(node->left);
            }
            getline(s,str,',');
            if(str=="N"){
                node->right=NULL;
            }else{
                TreeNode* rightn = new TreeNode(stoi(str));
                node->right = rightn;
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));