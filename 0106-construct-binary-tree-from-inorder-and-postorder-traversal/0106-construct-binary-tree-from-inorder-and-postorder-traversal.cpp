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
    TreeNode* build(vector<int>&postorder,int poststart,int postend,vector<int>&inorder,int instart,int inend,map<int,int>&mp){
        //base 
        if(poststart > postend || instart > inend)return NULL;
        //finding root
        TreeNode* root = new TreeNode(postorder[postend]);
        int inroot = mp[root->val];
        //no of nodes
        int leftsub = inroot - instart;
        int rightsubn = inend - instart;
        //left subtree and right subtree
        root->left = build(postorder,poststart,poststart+leftsub-1,inorder,instart,inroot-1,mp);
        root->right = build(postorder,poststart+leftsub,postend-1,inorder,inroot+1,inend,mp);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //map for finding quicker mapping elem with index
        map<int,int>mp;
        for(int i=0;i<inorder.size();++i){
            mp[inorder[i]] = i;
        }
        
        TreeNode* root = build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
};