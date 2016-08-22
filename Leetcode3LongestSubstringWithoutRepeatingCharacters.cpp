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
