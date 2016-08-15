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

int addDigits(int num){//leetcode 258
    int res = num;
    while(res>=10){
        num = res;
        res = 0;
        while(num>0){
            res+=num%10;
            num=(num-num%10)/10;
        }
    }
    return res;
}
