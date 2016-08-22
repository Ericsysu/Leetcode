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

int singleNumber2(vector<int>& nums){//leetcode 137
    if(!nums.empty()){
        map<int,int> mymap;
        for(int i=0;i<nums.size();i++){
            if(mymap[nums[i]]) mymap[nums[i]]++;
            else mymap[nums[i]]=1;
        }
        map<int, int>::iterator it = mymap.begin();
        for(it;it!=mymap.end();it++){
            if(mymap[it->first]!=3) return it->first;
        }
    }
}
