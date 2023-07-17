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
    int maxi = INT_MIN;
    int f(TreeNode* node){
        if(!node)return 0;
        int leftCall = max(0,f(node->left));
        int rightCall = max(0,f(node->right));
        maxi = max(maxi,node->val + leftCall + rightCall);
        return node->val + max(leftCall,rightCall);
    }
    int maxPathSum(TreeNode* root) {
        f(root);
        return maxi;
    }
};
/*
we are treating each node as 
    a
   / \
   b  c
 
 where sum is a + maxfrom left: b + maxfrom right : c
 and we can return only one path so  either it will be b->a or c->a 
 so return max(b,c) + a.
 we are calling func by comparing it with max beacuse of an edge case when all nodes are negative .
 */