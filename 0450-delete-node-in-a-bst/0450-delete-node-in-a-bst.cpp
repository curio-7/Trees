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
    
    TreeNode* del(TreeNode* root){
        if(root->left==NULL)return root->right;
        else if(root->right==NULL)return root->left;
        TreeNode* leftsubtree = root->left;
        TreeNode* leftmostnode = leftmost(root->right);
        leftmostnode->left = leftsubtree;
        return root->right;
    }
    TreeNode* leftmost(TreeNode* root){
        if(root->left==NULL)return root;
        return leftmost(root->left);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        //seaching and then delete
        if (root == NULL) {
            return NULL;
        }
        if (root->val == key) {
            return del(root);
        }
        TreeNode *dummy = root;
        while (root != NULL) {
            if (root->val > key) {
                if (root->left != NULL && root->left->val == key) {
                    root->left = del(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right != NULL && root->right->val == key) {
                    root->right = del(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};