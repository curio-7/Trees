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
    TreeNode* parentptr(TreeNode* root,map<TreeNode*,TreeNode*>&mp,int target){
      queue<TreeNode*>q;
      q.push(root);
      TreeNode* res;//for start
      while(!q.empty()){
          auto node = q.front();
          if(node->val == target)res=node;
          q.pop();
          if(node->left){
              mp[node->left]=node;
              q.push(node->left);
              
          }
          if(node->right){
              mp[node->right]=node;
              q.push(node->right);
          }
      }
      return res;
  }
  int timetoburn(map<TreeNode*,TreeNode*>mp,TreeNode* target){
      queue<TreeNode*>q;
      q.push(target);
      map<TreeNode*,bool>vis;
      vis[target]=true;
      int t = 0;
      while(!q.empty()){
          int n = q.size();
          bool burn = false;
          while(n--){
              auto node = q.front();
              q.pop();
              if(node->left && !vis[node->left]){
                  burn=1;
                  vis[node->left]=true;
                  q.push(node->left);
              }
              if(node->right && !vis[node->right]){
                  burn=1;
                  vis[node->right]=true;
                  q.push(node->right);
              }
              if(mp[node] && !vis[mp[node]]){
                  //parent ptr chck
                  burn=1;
                  vis[mp[node]]=true;
                  q.push(mp[node]);
              }
              
          }
          if(burn)t++;
          
      }
      return t;
  }
        int amountOfTime(TreeNode* root, int start) {
         map<TreeNode*,TreeNode*>mp;
        TreeNode* target = parentptr(root,mp,start);
        return timetoburn(mp,target);
        //using graph:
        // createGraph(root);
        // queue<int>q;
        // q.push(start);
        // unordered_map<int,bool>vis;
        // vis[start] = true;
        // int time = 0;
        // while(q.size()){
        //     time++;
        //     int n = q.size();
        //     while(n--){
        //         auto node = q.front();q.pop();
        //         for(auto&neigh:adj[node]){
        //             if(!vis[neigh]){
        //                 vis[neigh] = true;
        //                 q.push(neigh);
        //             }
        //         }
        //     }
        // }
        // return time-1;
    }
//     unordered_map<int,vector<int>>adj;//adj list
//     void createGraph(TreeNode* root){
//         queue<pair<TreeNode*,int>>q;
//         q.push({root,-1});
        
//         while(q.size()){
//             auto front = q.front();q.pop();
//             auto node = front.first;
//             int p = front.second;
//             if(p!=-1){
//                 adj[node->val].push_back(p);
//                 adj[p].push_back(node->val);
//             }
//             if(node->left)q.push({node->left,node->val});
//             if(node->right)q.push({node->right,node->val});
//         }
//     }

};