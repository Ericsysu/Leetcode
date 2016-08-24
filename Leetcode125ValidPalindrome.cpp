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

class Solution {
public:
    string help(string s){
        string res = "";
        for(int i=0;i<s.size();i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
                if(s[i]>='a' && s[i]<='z') res+=s[i];
                else res+=(s[i]-'A'+'a');
            }else continue;
        }
        return res;
    }
    bool isPalindrome(string s) {
        if(s == "") return true;
        string s1 = help(s);
        string s2;
        s2.assign(s1.rbegin(), s1.rend());
        if(s1!=s2) return false;
        return true;
    }
};
