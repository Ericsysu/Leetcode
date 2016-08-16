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
    bool isIsomorphic(string s, string t) {
        int a[128], b[128];
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            if(a[s[i]] != b[t[i]]) return false;
            a[s[i]] = i+1;
            b[t[i]] = i+1;
        }
        return true;
    }
};
