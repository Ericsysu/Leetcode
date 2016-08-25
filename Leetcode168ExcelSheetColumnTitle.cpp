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

using namespace std;
using namespace tr1;


class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while(n>0){
            res = char('A'+(n-1)%26)+res;
            n = (n-1)/26;
        }
        return res;
    }
};
