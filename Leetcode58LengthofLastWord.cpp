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
#include <set>

using namespace std;
using namespace tr1;

int lengthOfLastWord(string s) {
    istringstream stream(s);
    string tmp;
    int res = 0;
    while(stream >> tmp){
        res = tmp.size();
    }
    return res;
}
