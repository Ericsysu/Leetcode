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
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mymap;
        for(char m : magazine)
            mymap[m]++;
        for(char r : ransomNote)
            if(--mymap[r]<0) return false;
        return true;
    }
};
