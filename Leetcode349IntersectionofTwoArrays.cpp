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

vector<int> intersection(vector<int>& nums1, vector<int>& nums2){//leetcode 349
    map<int,bool> mymap;
    vector<int> res;
    for(int i=0;i<nums1.size();i++){
        if(!mymap[nums1[i]]){
            mymap[nums1[i]]=true;
        }
    }
    for(int i=0;i<nums2.size();i++){
        vector<int>::iterator s=find(res.begin(),res.end(),nums2[i]);
        if(mymap[nums2[i]]&&s==res.end()){
            res.push_back(nums2[i]);
        }
    }
    return res;
}
