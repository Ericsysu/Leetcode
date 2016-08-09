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
    unordered_set<int> myset;
public:
    bool isHappy(int n) {
        int cnt = 0;
        myset.insert(n);
        while(n>0){
            cnt += pow(n%10,2);
            n /= 10;
        }
        n = cnt;
        if(n == 1) return true;
        if(myset.find(n)!=myset.end()) return false;
        bool res = isHappy(n);
        return res;
    }
};
