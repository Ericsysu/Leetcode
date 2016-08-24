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
    int reverse(int x) {
        bool flag = false;
        int res = 0;
        if(x<0) flag = true;
        x = abs(x);
        while(x>0){
            if(res>(INT_MAX-x%10)/10){
                res = 0;
                break;
            }
            res = res*10+x%10;
            x/=10;
        }
        return flag?-res:res;
    }
};
