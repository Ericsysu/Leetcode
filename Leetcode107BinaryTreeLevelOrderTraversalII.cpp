#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <stack>
#include <deque>

using namespace std;
using namespace tr1;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    void DFS(vector<vector<int> > &v, TreeNode* root, int level){
        if(!root) return;
        if(level + 1 > v.size()){
            v.resize(level + 1);
        }
        v[level].push_back(root->val);
        if(root->left) DFS(v, root->left, level+1);
        if(root->right) DFS(v, root->right, level+1);
    }
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        DFS(res, root, 0);
        reverse(res.begin(), res.end());
        return res;
    }
};

 vector<vector<int> > levelOrderBottom(TreeNode* root) {//approach using queue
    vector<vector<int> > res;
    if(!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector<int> visit;
        while(n-- > 0){
            TreeNode* p = q.front();
            q.pop();
            visit.push_back(p->val);
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
        res.push_back(visit);
    }
    reverse(res.begin(), res.end());
    return res;
 }
