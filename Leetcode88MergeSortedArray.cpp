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

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int r1 = m-1, r2 = n-1, r = m+n-1;
        while(r1>=0 && r2>=0){
            nums1[r--] = nums1[r1]>nums2[r2] ? nums1[r1--] : nums2[r2--];
        }
        while(r2>=0)
            nums1[r--] = nums2[r2--];
    }
};
