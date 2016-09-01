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

void out(TreeNode* root){//Preorder output
    cout<<root->val<<" ";
    if(root->left) out(root->left);
    if(root->right) out(root->right);
}

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

int majorityElement(vector<int>& nums){//leetcode 169
    map<int, int> mymap;
    for(int i=0;i<nums.size();i++){
        if(mymap.find(nums[i])==mymap.end()) mymap[nums[i]] = 1;
        else mymap[nums[i]]++;
        if(mymap[nums[i]] > floor(nums.size()/2.0))
            return nums[i];
    }
    return 0;
}

int countNumbers(int n){
    int res = 9;
    if(n==1) return 10;
    for(int i=1;i<n;i++)
        res *= (10-i);
    return res;
}

int countNumbersWithUniqueDigits(int n){//leetcode 357
    if(n==0) return 1;
    int res = 0;
    for(int i=1;i<=n;i++){
        res+=countNumbers(i);
    }
    return res;
}

int intergerBreak(int n){//leetcode 343
    int res = 1;
    if(n==2) return 1;
    if(n==3) return 2;
    if(n==4) return 4;
    while(n>4){
        n = n-3;
        res*=3;
    }
    res*=n;
    return res;
}

bool containsDuplicate(vector<int>& nums) {//leetcode 217
    unordered_map<int,int> mymap;
    for(int i=0;i<nums.size();i++){
        if(mymap.find(nums[i])==mymap.end()) mymap[nums[i]]=1;
        else mymap[nums[i]]++;
    }
    unordered_map<int,int>::iterator it = mymap.begin();
    for(it;it!=mymap.end();it++){
        if(it->second>1) return true;
    }
    return false;
}

int missingNumber(vector<int>& nums){//leetcode 268
    sort(nums.begin(),nums.end());
    int tmp = nums[0];
    if(tmp!=0) return 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=tmp) return tmp;
        tmp++;
    }
    return tmp;
}

bool status(int num){
    int lcv;
    vector<int> factors;
    if(num==1) return true;
    for(lcv = 1;lcv <= (num/2);lcv++){
        if(num%lcv == 0) factors.push_back(lcv);
    }
    if(factors.empty()){
        return false;
    }else if(factors.size()%2) return false;
    else return true;
}
int bulbSwitch(int n) {//leetcode 319 Time Limit Exceed
    int res = 0;
    for(int i=1;i<=n;i++){
        if(status(i)) res++;
    }
    return res;
}

int bulbSwitchBetter(int n){//leetcode 319 better solution
    return sqrt(n);
}

int romanToInt(string s) {//leetcode 13
    int result=0;
    for(int i=0;i<s.size();i++)
    {
        switch(s[i])
        {
        case 'I' :
       if(s[i+1]=='V'||s[i+1]=='X')
        result-=1;
        else
        result+=1;
        break;

        case 'V' :
        result+=5;
        break;

        case 'X' :
        if(s[i+1]=='C'||s[i+1]=='L')
        result-=10;
        else
        result+=10;
        break;

        case 'L' :
        result+=50;
        break;

        case 'C' :
        if(s[i+1]=='D'||s[i+1]=='M')
        result-=100;
        else
        result+=100;
        break;

        case 'D' :
        result+=500;
        break;

        case 'M' :
        result+=1000;
        break;

        default:
        break;
        }

    }

    return result;
}

string intToRoman(int num){
    string res = "";
    while(num>0){
        if(num>=1000){
            res+='M';
            num -= 1000;
            //continue;
        }else if(num>=900&&num<1000){
            res+="CM";
            num -= 900;
        }else if(num>=500&&num<900){
            res+='D';
            num -= 500;
        }else if(num>=400&&num<500){
            res+="CD";
            num -= 400;
        }else if(num>=100&&num<400){
            res+='C';
            num-=100;
        }else if(num>=90&&num<100){
            res+="XC";
            num-=90;
        }else if(num>=50&&num<90){
            res+='L';
            num-=50;
        }else if(num>=40&&num<50){
            res+="XL";
            num-=40;
        }else if(num>=10&&num<40){
            res+='X';
            num-=10;
        }else if(num==9){
            res+="IX";
            num-=9;
        }else if(num>=5&&num<9){
            res+='V';
            num-=5;
        }else if(num==4){
            res+="IV";
            num-=4;
        }else{
            res+='I';
            num--;
        }
    }
    return res;
}

void inorder(TreeNode* root, vector<int>& res){
    if(root){
        if(root->left) inorder(root->left, res);
        res.push_back(root->val);
        if(root->right) inorder(root->right, res);
    }
}

vector<int> inorderTraversal(TreeNode* root){//leetcode 94 recursive
    vector<int> res;
    inorder(root,res);
    return res;
}

vector<int> inorderTraversalIterative(TreeNode* root){//leetcode 94 iterative
    vector<int> res;
    if(!root) return res;
    stack<TreeNode*> nodestack;
    while(root || !nodestack.empty()){
        while(root){
            nodestack.push(root);
            root = root->left;
        }
        root = nodestack.top();
        nodestack.pop();
        res.push_back(root->val);
        root = root->right;
    }
    return res;
}

vector<int> preorderTraversal(TreeNode* root){//leetcode 144 recursive
    vector<int> leftv,rightv, tmp;
    if(!root) return leftv;
    leftv.push_back(root->val);
    if(root->left) {
        tmp = preorderTraversal(root->left);
        leftv.insert(leftv.end(), tmp.begin(), tmp.end());
    }
    if(root->right) rightv = preorderTraversal(root->right);
    leftv.insert(leftv.end(), rightv.begin(), rightv.end());
    return leftv;
}

ListNode* reverseList(ListNode* head){//leetcode 206
    if(!head) return head;
     ListNode* node = head;
     ListNode* prev = NULL;

     while(node){
        ListNode* next = node->next;
        node->next = prev;
        prev = node;
        node = next;
     }
     return prev;
}

bool isPowerOfTwo(int n){//leetcode 231
    if(n<=0) return false;
        if(n==1) return true;
        while(n>1){
        if(n%2!=0) return false;
        n = n/2;
    }
    return true;
}

bool isPowerOfThree(int n){
    double x = log10(n)/log10(3);
    const double eps = 1e-6;
    if(abs(x-floor(x))<eps)
        return true;
    return false;
}

int maxProduct(vector<string>& words) {//leetcode 318 O(n*n)
    int maxn = 0;
    int *bit = new int[words.size()];
    fill(bit, bit+words.size(), 0);
    for(int i=0; i<words.size(); i++){
        int tmp = 0;
        for(int j = 0; j < words[i].size(); j++){
            bit[i] |= (1<<(words[i][j] - 'a'));
        }
        for(int j = 0; j<i; j++){
            if(bit[i]&bit[j]) continue;
            maxn = max(maxn, (int)(words[i].size()*words[j].size()));
        }
    }
    delete[] bit;
    return maxn;
}

int a;

int main(){
//    int a[6] = {1,1,1,2,2,3};
//    vector<int> v(a,a+6);
//    vector<int> res = topKFrequent(v,2);
//    for(int i=0;i<res.size();i++){
//        cout<<"result:"<<res[i]<<endl;
//    }
//    ListNode n(1);
//    ListNode* a = &n;
//    a->next = new ListNode(2);
//    a->next->next = new ListNode(3);
//    a->next->next->next = new ListNode(4);
//    ListNode* res = reverseList(a);
//    while(res){
//        cout<<res->val<<' ';
//        res = res->next;
//    }
int t =125;
t = t&27;
t = t^31;
cout<<sizeof(a);
}
