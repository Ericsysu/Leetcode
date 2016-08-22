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
