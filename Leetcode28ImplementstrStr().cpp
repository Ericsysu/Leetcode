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
    int strStr(string haystack, string needle) {
        int sizeh = haystack.size(), sizen = needle.size();
        if(sizen == 0) return 0;
        for(int i = 0; i<=sizeh - sizen; i++){
            for(int j=0; j<sizen; j++){
                if(haystack[i+j] != needle[j]) break;
                if(j==sizen - 1) return i;
            }
        }
        return -1;
    }
};
