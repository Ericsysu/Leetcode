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
    int depth(TreeNode* root){
        int d = 0;
        if(!root) return 0;
        return max(depth(root->left), depth(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int ldepth = 0, rdepth = 0;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* p = s.top();
            s.pop();
            ldepth = depth(p->left);
            rdepth = depth(p->right);
            if(abs(ldepth - rdepth) > 1) return false;
            if(p->left) s.push(p->left);
            if(p->right) s.push(p->right);
        }
        return true;
    }
};
