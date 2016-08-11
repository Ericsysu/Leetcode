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
#include <queue>

using namespace std;
using namespace tr1;

class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        while(n/5>0){
            sum+=n/5;
            n = n/5;
        }
        return sum;
    }
};
