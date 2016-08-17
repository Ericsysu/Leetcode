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
    bool wordPattern(string pattern, string str) {
        istringstream stream(str);
        unordered_map<string, char> m;
        unordered_map<char, string> rm;
        int i=0;
        while(i<pattern.length() && stream >> str) {
            if(m.find(str) == m.end() && rm.find(pattern[i]) == rm.end()){
                m[str] = pattern[i];
                rm[pattern[i]] = str;
            }else{
                if(m[str]!=pattern[i]) return false;
            }
            i++;
        }
        if(stream >> str || i != pattern.length())
            return false;

        return true;
    }
};
