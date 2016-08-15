#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cmath>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <stack>
#include <deque>
#include <queue>

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
    void help(TreeNode* root, string s, vector<string> &res){
        if(!root) return;
        if(!root->left&&!root->right) res.push_back(s + ("->"+to_string(root->val)));
        s += ("->"+to_string(root->val));
        if(root->left) help(root->left, s, res);
        if(root->right) help(root->right, s, res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        vector<string> res;
        if(!root) return res;
        if(root->left) {
            string l = to_string(root->val);
            help(root->left, l, res);
        }
        if(root->right) {
            string r = to_string(root->val);
            help(root->right, r, res);
        }
        if(!root->left&&!root->right) res.push_back(to_string(root->val));
        return res;
    }
};

//better solution
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;

    if(!root) return res;
    else if(!root->left && !root->right) res.push_back(to_string(root->val));

    string head = to_string(root->val) + "->";

    for(auto item: binaryTreePaths(root->left)) res.push_back(head + item);
    for(auto item: binaryTreePaths(root->right)) res.push_back(head + item);

    return res;
}

//recursive Solution
vector<int> binaryTreePathsr(TreeNode* root){
    vector<string> res;
    if(!root) return res;
    stack<TreeNode*> nodes;
    stack<string> str;
    nodes.push(root);
    str.push("");

    while(!nodes.empty()){
        TreeNode* top = nodes.top();
        string cs = str.top();
        if(!top->left && !top->right){
            cs += to_string(top->val);
            res.push_back(cs);
        }else{
            if(top->right){
                nodes.push(top->right);
                str.push(cs + to_string(top->val) + "->");
            }
            if(top->left){
                nodes.push(top->left);
                str.push(cs + to_string(top->val) + "->");
            }
        }
    }
    return res;
}
