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
    bool isBalanced(TreeNode* root) {
        //for balanced binary tree it is nec that height(left) - height(right) <=1
        return maxDepth(root)!=-1;
        //still the time complexity is O(N).
    }
     int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
         
         if(lh==-1 ||rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        
        return 1+max(lh,rh);
        //TC  = O(N) = sC
    }
};