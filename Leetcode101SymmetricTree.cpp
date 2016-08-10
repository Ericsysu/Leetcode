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
