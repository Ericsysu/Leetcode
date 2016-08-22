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

bool isSameTree(TreeNode* p, TreeNode* q){
    if(!p||!q){
        if(!p&&!q)  return true;
        return false;
    }
    return (p->val==q->val)&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
}
