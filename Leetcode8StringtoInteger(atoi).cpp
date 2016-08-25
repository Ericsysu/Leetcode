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
    int myAtoi(string str) {
        if(str == "") return 0;
        int res = 0;
        bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
        for(int i=0;i<str.size();i++){
            if(str[i]=='-' && i<str.size()-1 && (str[i+1]<='9' && str[i+1]>='0') && !flag1){
                flag1 = true;
                continue;
            }
            if(str[i] == '+' && i<str.size()-1 && (str[i+1]<='9' && str[i+1]>='0') && !flag1 && !flag2){
                flag2 = true;
                continue;
            }
            if(str[i] == ' ' && !flag4) continue;
            if(str[i]>'9' || str[i]<'0') break;
            if(res>(INT_MAX-(str[i]-'0'))/10){
                flag3 = true;
                res = INT_MAX;
                break;
            }
            res = res*10+(str[i] - '0');
            flag4 = true;
        }
        if(!flag1) return res;
        else{
            if(res == INT_MAX && flag3) return INT_MIN;
            else return -res;
        }
        return 0;
    }
};
