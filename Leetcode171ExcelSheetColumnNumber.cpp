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

int titleToNumber(string s) {//leetcode 171
    int res=0;
    for(int i=0;i<s.length()-1;i++){
        int pownum = s.length()-i-1;
        res+=(s[i]-'A'+1)*pow(26,pownum);
    }
    res+=s[s.length()-1]-'A'+1;
    return res;
}
