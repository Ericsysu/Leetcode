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

bool cmp(const pair<int,int>& x, const pair<int,int>& y){
    return x.second > y.second;
}

vector<int> topKFrequent(vector<int>& nums, int k){//leetcode 347
    vector<int> res;
    if(nums.empty()) return res;
    map<int,int> freq;
    for(int i=0;i<nums.size();i++){
        if(freq.find(nums[i])==freq.end()) freq[nums[i]] = 1;
        else freq[nums[i]]++;
    }
    map<int, int>::iterator it = freq.begin();
    vector<pair<int,int> > pairmap;
    for(it;it!=freq.end();it++){
        pairmap.push_back(make_pair(it->first,it->second));
    }
    sort(pairmap.begin(),pairmap.end(),cmp);
    for(int i=0;i<k;i++){
        res.push_back(pairmap[i].first);
    }
    return res;
}
