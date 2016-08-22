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

vector<int> productExcepSelf(vector<int>& nums){//leetcode 238
    if(nums.empty()) return vector<int>();
    int size = nums.size();
    int lprod[size], rprod[size];
    lprod[0]=1;
    rprod[size-1]=1;
    for(int i=1;i<size;i++){
        lprod[i] = nums[i-1]*lprod[i-1];
    }
    for(int i=size-2;i>=0;i--){
        rprod[i] = nums[i+1]*rprod[i+1];
    }
    vector<int> v(size);
    for(int i=0;i<size;i++){
        v[i] = lprod[i]*rprod[i];
    }
    return v;
}

vector<int> productExcepSelf1(vector<int>& nums){//leetcode 238 better solution
    if(nums.empty()) return vector<int>();
    int size = nums.size(), t=1;
    vector<int> v(size);
    v[0]=1;
    for(int i=1;i<size;i++) v[i] = v[i-1]*nums[i-1];
    for(int i=size-2;i>=0;i--)  v[i]*=(t*=nums[i+1]);
    return v;
}
