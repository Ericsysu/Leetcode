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
