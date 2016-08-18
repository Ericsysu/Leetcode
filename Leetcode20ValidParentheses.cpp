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

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if(st.empty()) st.push(c);
             else if(st.top() == '(' && c == ')') st.pop();
             else if(st.top() == '[' && c == ']') st.pop();
             else if(st.top() == '{' && c == '}') st.pop();
             else st.push(c);
        }
        return st.empty();
    }
};
