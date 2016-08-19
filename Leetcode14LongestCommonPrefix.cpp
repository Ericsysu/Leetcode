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
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if(strs.empty()) return res;
        int minsize = strs[0].size();
        for(int i=0;i<strs.size();i++){
            if(strs[i].size()<minsize) minsize = strs[i].size();
        }
        for(int i=0; i<minsize; i++){
            char tmp;
            tmp = strs[0][i];
            for(int j=0; j<strs.size(); j++){
                if(strs[j][i]!=tmp) return res;
            }
            res+=tmp;
        }
        return res;
    }
};
