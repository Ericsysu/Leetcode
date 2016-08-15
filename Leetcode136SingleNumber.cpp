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

int singleNumber1(vector<int>& nums){//leetcode 136
    int res = nums[0];
    for(int i=1;i<nums.size();i++){
        res^=nums[i];
    }
    return res;
}
