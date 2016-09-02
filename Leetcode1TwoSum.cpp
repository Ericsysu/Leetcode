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

vector<int> twoSum(vector<int>& nums, int target){//leetcode 1
    int tmp1 = 0,tmp2 = 0;
    bool found = false;
    for(int i=0; i<nums.size()-1; i++){
        if((target > 0 && nums[i] > target) || (target < 0 && nums[i] < target)) continue;
        tmp1 = i;
        for(int j=i+1; j<nums.size(); j++){
            if(nums[j]+nums[i]!=target) continue;
            else{
                tmp2 = j;
                found = true;
                break;
            }
        }
        if(!found) continue;
        else break;
    }
    vector<int> res;
    res.push_back(tmp1);
    res.push_back(tmp2);
    return res;
}
