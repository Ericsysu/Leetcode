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
#include <cctype>
#include <ctime>

using namespace std;
using namespace tr1;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == "" || (s == "" && t == "")) return true;
        int sizes = s.size(), sizet = t.size();
        if(sizes>sizet) return false;
        int tmp = 0;
        bool found = false;
        for(int i=0; i<sizes; i++){
            int j = tmp;
            found = false;
            for(j = tmp; j<sizet; j++){
                if(s[i] == t[j]){
                    found = true;
                    tmp = j+1;
                    break;
                }
            }
            if(!found) return false;
        }
        return true;
    }
};
