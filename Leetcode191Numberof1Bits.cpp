#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include<stack>

using namespace std;
using namespace tr1;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res;
        while(n){
            if(n&1 == 1) res++;
            n >>= 1;
        }
        return res;
    }
};
