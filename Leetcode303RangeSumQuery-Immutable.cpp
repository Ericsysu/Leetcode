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

class NumArray {
public:
    unordered_map<int,int> mp;
    NumArray(vector<int> &nums) {
        mp[-1] = 0;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            mp[i] = sum;
        }
    }

    int sumRange(int i, int j) {
        return mp[j] - mp[i-1];
    }
};
