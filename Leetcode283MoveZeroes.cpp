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

void moveZeroes(vector<int>& nums){//leetcode 283
    if(!nums.empty()){
        int cnt=0;
        vector<int>::iterator it=nums.begin();
        for(it;it!=nums.end();it++){
            if(*it==0){
                nums.erase(it);
                it--;
                cnt++;
            }
        }
        for(int i=0;i<cnt;i++)
            nums.push_back(0);
    }
}

void moveZeroes1(vector<int>& nums){//leetcode 283 better solution
    int j=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=0){
            nums[j++]=nums[i];
        }
    }
    for(;j<nums.size();j++){
        nums[j]=0;
    }
}
