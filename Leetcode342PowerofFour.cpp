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
    bool isPowerOfFour(int num) {
        double x = log10(num)/log10(4);
        double eps = 1e-12;
        if(abs(x - floor(x)) <= eps){
            return true;
        }
        return false;
    }
};
