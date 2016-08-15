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

int maxDepth(TreeNode* root){//leetcode 104
    int depth = 0;
    if(root){
        int leftdepth = maxDepth(root->left);
        int rightdepth = maxDepth(root->right);
        depth = leftdepth>=rightdepth?leftdepth+1:rightdepth+1;
    }
    return depth;
}
