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

void out(TreeNode* root){//Preorder output
    cout<<root->val<<" ";
    if(root->left) out(root->left);
    if(root->right) out(root->right);
}

vector<int> singleNumber3(vector<int>& nums){//leetcode 260
    vector<int> res;
    if(!nums.empty()){
        map<int, int> mymap;
        for(int i=0;i<nums.size();i++){
            if(mymap[nums[i]]) mymap[nums[i]]++;
            else mymap[nums[i]]=1;
        }
        map<int, int>::iterator it=mymap.begin();
        for(it;it!=mymap.end();it++){
            if(mymap[it->first]==1) res.push_back(it->first);
        }
    }
    return res;
}

int singleNumber2(vector<int>& nums){//leetcode 137
    if(!nums.empty()){
        map<int,int> mymap;
        for(int i=0;i<nums.size();i++){
            if(mymap[nums[i]]) mymap[nums[i]]++;
            else mymap[nums[i]]=1;
        }
        map<int, int>::iterator it = mymap.begin();
        for(it;it!=mymap.end();it++){
            if(mymap[it->first]!=3) return it->first;
        }
    }
}

void moveZeroes(vector<int>& nums){//leetcode 283
    if(!nums.empty()){
        int cnt=0;
        vector<int>::iterator it=nums.begin();
        for(it;it!=nums.end();it++){
            if(*it==0){
                nums.erase(it);
                it--;
                cnt++;
            }
        }
        for(int i=0;i<cnt;i++)
            nums.push_back(0);
    }
}

void moveZeroes1(vector<int>& nums){//leetcode 283 better solution
    int j=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=0){
            nums[j++]=nums[i];
        }
    }
    for(;j<nums.size();j++){
        nums[j]=0;
    }
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2){//leetcode 349
    map<int,bool> mymap;
    vector<int> res;
    for(int i=0;i<nums1.size();i++){
        if(!mymap[nums1[i]]){
            mymap[nums1[i]]=true;
        }
    }
    for(int i=0;i<nums2.size();i++){
        vector<int>::iterator s=find(res.begin(),res.end(),nums2[i]);
        if(mymap[nums2[i]]&&s==res.end()){
            res.push_back(nums2[i]);
        }
    }
    return res;
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2){//leetcode 350 O(n) using hash table
    unordered_map<int,int> mymap;
    vector<int> res;
    for(int i=0;i<nums1.size();i++)
        mymap[nums1[i]]++;
    for(int i=0;i<nums2.size();i++){
        if(--mymap[nums2[i]]>=0) res.push_back(nums2[i]);
    }
    return res;
}

vector<int> intersect1(vector<int>& nums1, vector<int>& nums2){//leetcode 350 O(nlogn)
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    int n1 = nums1.size(), n2 = nums2.size();
    int i1 = 0, i2 = 0;
    vector<int> res;
    while(i1<n1&&i2<n2){
        if(nums1[i1]==nums2[i2]){
            res.push_back(nums1[i1]);
            i1++;i2++;
        }else if(nums1[i1]>nums2[i2]){
            i2++;
        }else i1++;
    }
    return res;
}

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

void deleteNode(ListNode *node){//leetcode 237
    if(node->next){
        node->val=node->next->val;
        node->next=node->next->next;
    }else node=NULL;
}

vector<int> productExcepSelf(vector<int>& nums){//leetcode 238
    if(nums.empty()) return vector<int>();
    int size = nums.size();
    int lprod[size], rprod[size];
    lprod[0]=1;
    rprod[size-1]=1;
    for(int i=1;i<size;i++){
        lprod[i] = nums[i-1]*lprod[i-1];
    }
    for(int i=size-2;i>=0;i--){
        rprod[i] = nums[i+1]*rprod[i+1];
    }
    vector<int> v(size);
    for(int i=0;i<size;i++){
        v[i] = lprod[i]*rprod[i];
    }
    return v;
}

vector<int> productExcepSelf1(vector<int>& nums){//leetcode 238 better solution
    if(nums.empty()) return vector<int>();
    int size = nums.size(), t=1;
    vector<int> v(size);
    v[0]=1;
    for(int i=1;i<size;i++) v[i] = v[i-1]*nums[i-1];
    for(int i=size-2;i>=0;i--)  v[i]*=(t*=nums[i+1]);
    return v;
}

bool isSameTree(TreeNode* p, TreeNode* q){
    if(!p||!q){
        if(!p&&!q)  return true;
        return false;
    }
    return (p->val==q->val)&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
}

int maxProfit1(vector<int>& prices){//leetcode 121
    if(prices.size()==0)
        return 0;
    int small = prices[0];
    int profit = 0;
    int i=0;
    int j=i+1;
    for(i;i<prices.size()-1;i++){
        j=i+1;
        if(prices[i]<small)
            small = prices[i];
        if(prices[j]-small>profit)
            profit = prices[j]-small;
    }
    if(profit<0) return 0;
    return profit;
}

int maxProfit2(vector<int>& prices){//leetcode 122
    if(prices.size()==0) return 0;
    int profit = 0;
    for(int i=1;i<prices.size();i++){
        int tmp = prices[i]-prices[i-1];
        if(tmp>0) profit+=tmp;
    }
    return profit;
}

vector<int> twoSum(vector<int>& nums, int target){//leetcode 1
    int tmp1 = 0,tmp2 = 0;
    bool found=false;
    for(int i=0;i<nums.size()-1;i++){
        if((target>0&&nums[i]>target) || (target<0&&nums[i]<target)) continue;
        tmp1 = i;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]+nums[i]!=target) continue;
            else{
                tmp2 = j;
                found = true;
                break;
            }
        }
        if(!found) continue;
        else break;
    }
    vector<int> res;
    res.push_back(tmp1);
    res.push_back(tmp2);
    return res;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){//leetcode 2
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while(l1 || l2 || extra){
        int sum = (l1?l1->val:0)+(l2?l2->val:0)+extra;
        extra = sum/10;
        p->next = new ListNode(sum%10);
        p = p->next;
        l1 = l1?l1->next:l1;
        l2 = l2?l2->next:l2;
    }
    return preHead.next;
}
bool find(int begin, int end, char a,string s){
    for(int i=begin;i<=end;i++){
        if(s[i]==a) return true;
    }
    return false;
}
int lengthOfLongestSubstring(string s){//leetcode 3 bad way
    int l = s.length();
    const int MAX = l+5;
    int maxlen = 1;
    bool dp[MAX][MAX];
    memset(dp,false,sizeof(dp));
    for(int i=0;i<l;i++){
        dp[i][i] = true;
    }
    cout<< l << ' ';
    for(int i=0;i<l-1;i++){
        for(int j=i+1;j<l;j++){
            if(dp[i][j-1]&&!find(i,j-1,s[j],s)){
                dp[i][j] = true;
                maxlen = (j-i+1>maxlen)?(j-i+1):maxlen;
            }
        }
    }
    return maxlen;
}

int lengthOfLongestSubstring1(string s){//leetcode 3 too tricky
    int dict[256];
    memset(dict, -1, sizeof(dict));
    int maxlen = 0, start = -1;
    for(int i = 0; i < s.length(); i++){
        if(dict[s[i]] > start)
            start = dict[s[i]];
        dict[s[i]] = i;
        maxlen = max(maxlen, i - start);
    }
    return maxlen;
}

string longestPalindromeDP(string s){//最长回文子串，DP方法
    int l=s.length();
    int begin = 0;
    int maxlen = 1;
    bool dp[1000][1000];
    for(int i=0;i<l;i++){
        dp[i][i] = true;
    }
    for(int i=0;i<l-1;i++){
        if(s[i] == s[i+1]){
            dp[i][i+1] = true;
            begin = i;
            maxlen = 2;
        }
    }
    for(int len = 3; len < l; len++){
        for(int i=0;i<l-len+1;i++){
            int j = i+len-1;
            if(s[i]==s[j]&&dp[i+1][j-1]){
                dp[i][j] = true;
                begin = i;
                maxlen = len;
            }
        }
    }

    return s.substr(begin, maxlen);
}

int longestPalindromeMancher(string s){//最长回文子串，Mancher算法
    int l = s.length(),border=0,id=0,maxlen=0,p[1000];
    string str;
    for(int i=0;i<l;i++)
        str+='0';
    str[0] = '$';
    str[1] = '#';
    for(int i=0;i<l;i++){
       str[i*2+2] = s[i];
       str[i*2+3] = '#';
    }
    l = 2*l+2;
    for(int i=1;i<l;i++){
        if(border>i) p[i] = min(p[2*id-i], p[id]+id-i);
        else p[i] = 1;
        for(;str[i+p[i]]==str[i-p[i]];p[i]++);
        if(p[i]+i>border){
            border = p[i]+i;
            id = i;
        }
    }
    for(int i=0;i<l;i++){
        if(p[i]>maxlen) {
            maxlen = p[i];
        }
    }
    return maxlen-1;
}

bool cmp(const pair<int,int>& x, const pair<int,int>& y){
    return x.second > y.second;
}

vector<int> topKFrequent(vector<int>& nums, int k){//leetcode 347
    vector<int> res;
    if(nums.empty()) return res;
    map<int,int> freq;
    for(int i=0;i<nums.size();i++){
            //cout<<"nums:"<<nums[i]<<endl;
        if(freq.find(nums[i])==freq.end()) freq[nums[i]] = 1;
        else freq[nums[i]]++;
    }
    map<int, int>::iterator it = freq.begin();
    vector<pair<int,int> > pairmap;
    for(it;it!=freq.end();it++){
            //cout<<"map:"<<it->first<<' '<<it->second<<endl;
        pairmap.push_back(make_pair(it->first,it->second));
    }
    sort(pairmap.begin(),pairmap.end(),cmp);
    for(int i=0;i<k;i++){
        res.push_back(pairmap[i].first);
    }
    return res;
}

int titleToNumber(string s) {//leetcode 171
    int res=0;
    for(int i=0;i<s.length()-1;i++){
        int pownum = s.length()-i-1;
        res+=(s[i]-'A'+1)*pow(26,pownum);
    }
    res+=s[s.length()-1]-'A'+1;
    return res;
}

 bool isAnagram(string s, string t) {//leetcode 242
    unordered_map<char,int> mymap1,mymap2;
    for(int i=0;i<s.length();i++){
        if(mymap1.find(s[i])==mymap1.end()) mymap1[s[i]]=1;
        else mymap1[s[i]]++;
    }
    for(int i=0;i<t.length();i++){
        if(mymap2.find(t[i])==mymap2.end()) mymap2[t[i]]=1;
        else mymap2[t[i]]++;
    }
    unordered_map<char,int>::iterator it = mymap1.begin();
    for(it;it!=mymap1.end();it++){
        if(mymap2[it->first]!=it->second || (mymap2.find(it->first)==mymap2.end()) ) return false;
    }
    unordered_map<char,int>::iterator it1 = mymap2.begin();
    for(it1;it1!=mymap2.end();it1++){
        if(mymap1[it1->first]!=it1->second || (mymap1.find(it1->first)==mymap1.end()) ) return false;
    }
    return true;
}

bool isAnagram1(string s, string t){//leetcode 242 better solution
    if(s.length()!=t.length()) return false;
    int n = s.length();
    int counts[26] = {0};
    for(int i=0;i<n;i++){
        counts[s[i]-'a']++;
        counts[t[i]-'a']--;
    }
    for(int i=0;i<26;i++)
        if(counts[i]) return false;
    return true;
}

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
        //if(next) cout<<next->val<<"I"<<' ';
        node->next = prev;
        //if(node->next) cout<<node->next->val<<"II"<<' ';
        prev = node;
        //if(prev) cout<<prev->val<<"III"<<' ';
        node = next;
        //if(node) cout<<node->val<<"IV"<<' ';
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
