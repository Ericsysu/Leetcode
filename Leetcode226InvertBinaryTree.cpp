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
#include <stack>

using namespace std;
using namespace tr1;

struct TreeNode{//Binary Tree Definition
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root){//leetcode 226
    TreeNode* tmp;
    if(root){
        tmp = root->right;
        root->right = root->left;
        root->left = tmp;
        if(root->left)  root->left = invertTree(root->left);
        if(root->right) root->right = invertTree(root->right);
    }
    return root;
}
