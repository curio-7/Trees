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
    vector<vector<int>>ans;
    bool isLeaf(TreeNode* node){
        if(!node->left && !node->right){
            return true;
        }
        return false;
    }
    void dfs(TreeNode* node,int targetSum,vector<int>&vals){
        //base case
        if(!node)return;
        if(node)vals.emplace_back(node->val);
        //check
        if(isLeaf(node) && targetSum-node->val==0){
            ans.emplace_back(vals);
        }
        //explore
        if(node->left)dfs(node->left,targetSum-node->val,vals);
        if(node->right)dfs(node->right,targetSum-node->val,vals);
        vals.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return {};
        }
        vector<int>vals;
        dfs(root,targetSum,vals);
        return ans;
    }
};