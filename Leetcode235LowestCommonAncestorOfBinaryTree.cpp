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

using namespace std;
using namespace tr1;

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = root;
        if(!root) return NULL;
        if(p->val < root->val && q->val < root->val){
            res = lowestCommonAncestor(root->left, p, q);
        }else if(p->val > root->val && q->val > root->val){
            res = lowestCommonAncestor(root->right, p, q);
        }else {
            res = root;
        }
        return res;
    }
};

//class Solution1 {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if(!root) return NULL;
//        if(p->val < root->val && q->val < root->val){
//            lowestCommonAncestor(root->left, p, q);
//        }else if(p->val > root->val && q->val > root->val){
//            lowestCommonAncestor(root->right, p, q);
//        }else return root;
//    }
//};
