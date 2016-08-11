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
    bool help(TreeNode* left, TreeNode* right){
        if(!left || !right) return left == right;
        return (left->val == right->val) && help(left->left, right->right) && help(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return help(root->left, root->right);
    }
};

bool isSymmetric(TreeNode* root){//iterative approach
    if(!root) return true;
    stack<TreeNode*> s1, s2;
    TreeNode *p1 = root, *p2 = root;
    while((p1&&p2) || (!s1.empty()&&!s2.empty())){
        if(p1&&p2){
            if(p1->val != p2->val) return false;
            s1.push(p1);
            s2.push(p2);
            p1 = p1->left;
            p2 = p2->right;
        }else if(!p1 && !p2){
            if(!s1.empty() && !s2.empty()){
                if(s1.top() == root && s2.top() == root) return true;
                p1 = s1.top()->right;
                p2 = s2.top()->left;
                s1.pop();
                s2.pop();
            }else if( (s1.empty()&&!s2.empty() ) || (!s1.empty()&&s2.empty()))
                return false;
        }else return false;
    }
    return true;
}
