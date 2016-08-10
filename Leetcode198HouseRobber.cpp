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
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int size = nums.size();
        int dp[size][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        dp[1][0] = dp[0][1];
        dp[1][1] = nums[1];
        for(int i = 2; i < size; i++){
            dp[i][1] = dp[i-1][0]+nums[i];
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        }
        return max(dp[size-1][0], dp[size-1][1]);
    }
};
