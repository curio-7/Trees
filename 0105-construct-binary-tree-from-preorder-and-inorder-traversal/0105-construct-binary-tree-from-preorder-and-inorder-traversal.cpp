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
    TreeNode* build(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend,map<int,int>&mp){
        //base condition
        if(prestart>preend || instart>inend) return NULL;
        //create a new root from preorder
        TreeNode* root = new TreeNode(preorder[prestart]);
        //finding rrot from inorder
        int inroot = mp[root->val];
        //finding total no of elements in left subtree and right subtree
        int leftsub = inroot - instart;
        int rightsub = inend - inroot;
        //call function with new pre and in order
        root->left = build(preorder,prestart+1,prestart+leftsub,inorder,instart,inroot-1,mp);
        root->right = build(preorder,prestart+leftsub+1,preend,inorder,inroot+1,inend,mp);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //map for finding quicker mapping elem with index
        map<int,int>mp;
        for(int i=0;i<inorder.size();++i){
            mp[inorder[i]] = i;
        }
        
        TreeNode* root = build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
};