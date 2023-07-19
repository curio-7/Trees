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
    int lh(TreeNode* root){
        int h = 0;
        while(root){
            root=root->left;
            h++;
        }
        return h;
    }
    int rh(TreeNode* root){
        int h = 0;
        while(root){
            root=root->right;
            h++;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
//         if(root == NULL)
//         return 0;
    
//         int res = 0;
//         queue<TreeNode *> q;
//         q.push(root);
//         while(!q.empty())
//         {

//             int n = q.size();
//             while(n--){
//                 res++;
//                 auto node = q.front();q.pop();
//                 if(node->left)q.push(node->left);
//                 if(node->right)q.push(node->right);
//             }
//         }

//         return res;
        //O(N)
        //now another
        if(!root)return 0;
        int lefth = lh(root);
        int righth = rh(root);
        if(lefth==righth) return (1<<lefth)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
        //TC = O(logn)^2
        //SC = O(logn)
    }
};

For a complete tree the height of binary tree is O(logN)
