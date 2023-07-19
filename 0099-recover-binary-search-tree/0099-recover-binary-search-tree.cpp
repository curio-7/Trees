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
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
    
    // vector<int> v;
    // int i=0;
    // void inorder(TreeNode* root){
    //     if(!root) return;
    //     inorder(root->left);
    //     v.push_back(root->val);
    //     inorder(root->right);
    // }
    // void check(TreeNode* root){
    //     if(!root) return;
    //     check(root->left);
    //     if(v[i]!=root->val) swap(v[i],root->val);
    //     i++;
    //     check(root->right);
    // }
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        if(prev && root->val < prev->val){
            if(!first){
                first = prev;
                middle = root;
            }
            else{
                last=root;
            }
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        // inorder(root);
        // sort(v.begin(),v.end());
        // check(root);
        //tc = O(nlogn)
        //optimal
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last)swap(first->val,last->val);
        else if(first && middle) swap(first->val,middle->val);
    }
};