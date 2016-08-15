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

vector<int> countBits(int num){//leetcode 338
    int count=0;
    vector<int> res;
    res.push_back(0);
    for(int i=1;i<=num;i++){
        int tmp = i;
        while(tmp>0){
            count++;
            tmp&=(tmp-1);
        }
        res.push_back(count);
        count=0;
    }
    return res;
}
