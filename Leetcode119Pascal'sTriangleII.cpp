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
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        vector<int> tmp;
        v.push_back(1);
        tmp = v;
        for(int i=1; i<rowIndex+1; i++){
            for(int j = 1; j<v.size(); j++){
                v[j] = tmp[j-1] + tmp[j];
            }
            v.push_back(1);
            tmp = v;
        }
        return v;
    }
};
