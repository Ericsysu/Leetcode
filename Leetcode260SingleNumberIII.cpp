#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cmath>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <stack>
#include <deque>
#include <queue>

using namespace std;
using namespace tr1;

vector<int> singleNumber3(vector<int>& nums){//leetcode 260
    vector<int> res;
    if(!nums.empty()){
        map<int, int> mymap;
        for(int i=0;i<nums.size();i++){
            if(mymap[nums[i]]) mymap[nums[i]]++;
            else mymap[nums[i]]=1;
        }
        map<int, int>::iterator it=mymap.begin();
        for(it;it!=mymap.end();it++){
            if(mymap[it->first]==1) res.push_back(it->first);
        }
    }
    return res;
}
