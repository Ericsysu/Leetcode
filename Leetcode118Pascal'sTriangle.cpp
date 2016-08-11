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

vector<vector<int> > generate(int numRows) {
    vector<vector<int> > res;
    if(numRows == 0) return res;
    vector<int> tmp, v;
    tmp.push_back(1);
    res.push_back(tmp);
    v = tmp;
    for(int i=1;i<numRows;i++){
        tmp.clear();
        tmp.push_back(1);
        for(int j=1;j<i;j++){
            tmp.push_back(v[j-1]+v[j]);
        }
        tmp.push_back(1);
        v = tmp;
        res.push_back(tmp);
    }
    return res;
}

