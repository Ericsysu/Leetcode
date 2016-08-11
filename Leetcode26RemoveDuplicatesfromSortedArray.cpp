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

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int flag = 0;
        int cnt = 0;
        int Size = nums.size();
        for(int i=1;i<nums.size();i++){
            if(!flag && nums[i]==nums[i-1]){
                flag = 1;
                cnt++;
            }else if(flag && nums[i]==nums[i-1]){
                cnt++;
            }else{
                nums[i-cnt] = nums[i];
                flag = 0;
            }
        }
        return Size-cnt;
    }
};
