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

string reverseString(string s){//leetcode 344
    string res="";
    for(int i=s.size()-1;i>=0;i--){
        res+=s[i];
    }
    return res;
}