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
#include <set>

using namespace std;
using namespace tr1;

bool containsNearbyDuplicate(vector<int>& nums, int k) {//TLE
    for(int i=0;i<nums.size();i++){
        int sizebehind;
        if(nums.size()-i>k) sizebehind = i+k;
        else sizebehind = nums.size() - 1;
        set<int> s;
        for(int j=i;j<=sizebehind;j++){
            if(s.find(nums[j])!=s.end()) return true;
            s.insert(nums[j]);
        }
        s.clear();
    }
    return false;
}

bool containsNearbyDuplicate(vector<int> &nums, int k){
    unordered_map<int,int> mymap;
    for(int i=0;i<nums.size();i++){
        if(mymap.find(nums[i]) == mymap.end()){
            mymap[nums[i]] = i;
        }else{
            if(i-mymap[nums[i]] <= k) return true;
            else mymap[nums[i]] = i;
        }
    }
    return false;
}


int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    bool res = containsNearbyDuplicate(v,1);
    cout<<res<<endl;
}
