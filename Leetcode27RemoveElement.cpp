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
#include <tr1/unordered_set>
#include <stack>
#include <deque>

using namespace std;
using namespace tr1;

int removeElement(vector<int>& nums, int val) {
    vector<int>::iterator it = nums.begin();
    while(it != nums.end()){
        if(*it == val) {
            nums.erase(it);
            it--;
        }
        if(it == nums.end()) break;
        it++;
    }
    return nums.size();
}

void reallocate(vector<int>& v, int pos){
    for(int i = pos; i<v.size()-1; i++){
        v[i] = v[i+1];
    }
    v.pop_back();
}

int removeElement1(vector<int>& nums, int val) {
    int size = nums.size();
    for(int i=0; i < size; i++){
        if(nums[i] == val){
            cout<<nums[i]<<' ';
            reallocate(nums, i);
            size --;
            i--;
        }
    }
    cout<<endl;
    return size;
}
