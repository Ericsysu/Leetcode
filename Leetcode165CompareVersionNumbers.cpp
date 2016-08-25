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
    int compareVersion(string version1, string version2) {
        int i=0, j=0;
        int n1 = version1.size();
        int n2 = version2.size();
        int t1=0, t2=0;
        while(i<n1 || j<n2){
            while(i<n1 && version1[i]!='.'){
                t1 = t1*10+(version1[i]-'0');
                i++;
            }
            while(j<n2 && version2[j]!='.'){
                t2 = t2*10+(version2[j]-'0');
                j++;
            }
            if(t1>t2) return 1;
            else if(t1<t2) return -1;
            t1 = t2 = 0;
            i++;j++;
        }
        return 0;
    }
};
