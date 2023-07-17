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
    int cnt = 0;
    int mod = (int)1e9+7;
    void dfs(TreeNode* node,int targetSum){
        //base
        if(!node) return;
        //check
        if(targetSum - node->val == 0)cnt++;
        //calls
        if(node->left)dfs(node->left,(targetSum - node->val)%mod);
        if(node->right)dfs(node->right,(targetSum - node->val)%mod);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        if(root){
            dfs(root,targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        
        return cnt;
    }
};