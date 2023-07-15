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
    // void traversal(TreeNode* root,int level,vector<int>&ans){
    //     if(root == NULL) return;
    //     if(ans.size()==level) {
    //         ans.push_back(root->val);
    //     }
    //     traversal(root->right,level+1,ans);
    //     traversal(root->left,level+1,ans);
    //     //For left view just swap above two segments.
    // }
    vector<int> rightSideView(TreeNode* root) {
        //iterative
        vector<int>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int>level;
            while(n--){
                auto node = q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level[level.size()-1]); //left view
        }
         return ans;
        // vector<int>ans;
        // traversal(root,0,ans);
        // return ans;
    }
};