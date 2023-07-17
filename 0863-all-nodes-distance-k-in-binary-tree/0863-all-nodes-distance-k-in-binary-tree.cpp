/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int,vector<int>>adj;
      void create(TreeNode* root){
          queue<pair<TreeNode*,int>>q;
          q.push({root,-1});
          while(q.size()){
              auto node = q.front().first;
              int p = q.front().second;
              q.pop();
              if(p!=-1){
                  adj[p].push_back(node->val);
                  adj[node->val].push_back(p);
              }
              if(node->left)q.push({node->left,node->val});
              if(node->right)q.push({node->right,node->val});
          }
      }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        create(root);
        vector<int>ans;
        queue<int>q;
        q.push(target->val);
        unordered_map<int,bool>vis;
        vis[target->val] = true;
        int cnt = 0;
        while(q.size()){
            cnt++;
            if(cnt>k){
                while(!q.empty()){
                    ans.push_back(q.front());
                    q.pop();
                }
                break;
            }
            int n = q.size();
            while(n--){
                auto node = q.front();q.pop();
                vis[node] = true;
                for(auto&n:adj[node]){
                    if(!vis[n]){
                        vis[n] = true;
                        q.push(n);
                    }
                }
            }
        }
        
        return ans;
    }
};