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

vector<int> intersect(vector<int>& nums1, vector<int>& nums2){//leetcode 350 O(n) using hash table
    unordered_map<int,int> mymap;
    vector<int> res;
    for(int i=0;i<nums1.size();i++)
        mymap[nums1[i]]++;
    for(int i=0;i<nums2.size();i++){
        if(--mymap[nums2[i]]>=0) res.push_back(nums2[i]);
    }
    return res;
}

vector<int> intersect1(vector<int>& nums1, vector<int>& nums2){//leetcode 350 O(nlogn)
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    int n1 = nums1.size(), n2 = nums2.size();
    int i1 = 0, i2 = 0;
    vector<int> res;
    while(i1<n1&&i2<n2){
        if(nums1[i1]==nums2[i2]){
            res.push_back(nums1[i1]);
            i1++;i2++;
        }else if(nums1[i1]>nums2[i2]){
            i2++;
        }else i1++;
    }
    return res;
}
