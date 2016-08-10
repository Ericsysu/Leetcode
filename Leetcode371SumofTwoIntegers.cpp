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

int getSum(int a, int b){//leetcode 371
    if(a==0) return b;
    return getSum((a&b)<<1,a^b);
}